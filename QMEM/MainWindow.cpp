#include "MainWindow.h"
#include "TextEntryWindow.h"
#include "LearnWindow.h"
#include "Results_Dlg.h"

enum {
    NEWTEXT = 45,
    LEARN, 
    SHOW,
    BUTTON_LIST_OPEN,
	REMOVE_RECORD,
	WELCOME,
	POPUP_TEST
};

#define CLOSE_TO_WINDOW 66

MainWindow::MainWindow(const wxString& title)
    :wxFrame(
            nullptr,
            wxID_ANY,
            title,
            wxDefaultPosition,
            wxSize(600,400),
        wxDEFAULT_FRAME_STYLE
    ) 

{
    wxIcon mainIcon;
    mainIcon.LoadFile("Qmem.ico", wxBITMAP_TYPE_ICO);
    this->SetIcon(mainIcon);
    CenterOnScreen();
    
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainWindow::on_child_added_new_record, this, CLOSE_TO_WINDOW);
    
    // making a new menu with name file
    auto file = new wxMenu();

    // making a new menu item with the name exit and binding it to the corresponding event
    auto exit = new wxMenuItem(file, wxID_CLOSE, "Exit");
    file->Bind(
            wxEVT_COMMAND_MENU_SELECTED,
            &MainWindow::on_exit_selected,
            this,
            wxID_CLOSE);

	

    // making a new menu item with the name newText and binding it to the corresponding event
    auto new_text = new wxMenuItem(file, NEWTEXT, "New text");
    file->Bind(
            wxEVT_COMMAND_MENU_SELECTED,
            &MainWindow::on_new_text_selected,
            this,
            NEWTEXT);


    auto show_lessons = new wxMenuItem(file, SHOW, "Show Lessons");
    file->Bind(
            wxEVT_COMMAND_MENU_SELECTED,
            &MainWindow::on_show_lessons,
            this,
            SHOW);

    // now adding the to menu items to the menu
    file->Append(new_text);
    file->Append(show_lessons);
    file->Append(exit);

    // now making the menubar and adding the file menu to it then setting it as the menubar of the frame
    auto menubar = new wxMenuBar();
    menubar->Append(file, "File");
    SetMenuBar(menubar);

    wxFont f(
            18,
            wxFONTFAMILY_DEFAULT,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD,
            false,
            "Tahoma");


    auto welcomeText = new wxStaticText(
            this,
            WELCOME,
            "",
            wxDefaultPosition,
            wxSize(400, 50),
            wxALIGN_CENTER);

    welcomeText->SetLabel("Welcome to Qmem");
    welcomeText->SetFont(f);
    welcomeText->SetForegroundColour(wxColour("red"));


    DB_Manager::instance()->init_db();

   list_box = new wxListBox(
            this,
            BUTTON_LIST_OPEN,
            wxDefaultPosition,
            wxDefaultSize
            );
   auto text_left = new wxStaticText(this, wxID_ANY, "");

    for (int i = 0; i < DB_Manager::instance()->retrieve_results().size(); i++)
    {
        list_box->Append(DB_Manager::instance()->retrieve_results()[i].name);
    }

    auto remove_selected_button = new wxButton(this, REMOVE_RECORD, "remove");

    Bind(wxEVT_LISTBOX_DCLICK, &MainWindow::on_open_selected_button_clicked, this, BUTTON_LIST_OPEN);
    Bind(wxEVT_BUTTON, &MainWindow::on_remove_selected_button_clicked, this, REMOVE_RECORD);


    auto base_sizer = new wxBoxSizer(wxVERTICAL);
    auto body_sizer = new wxBoxSizer(wxHORIZONTAL);

    base_sizer->Add(welcomeText, 0,   wxALIGN_CENTRE|wxALL, 10);
    auto *left_sizer = new wxBoxSizer(wxVERTICAL);
    auto *right_sizer = new wxBoxSizer(wxVERTICAL);

    right_sizer->Add(list_box,1, wxALL|wxEXPAND, 10);
    right_sizer->Add(remove_selected_button,0, wxALL, 10);
    left_sizer->Add(text_left, 1, wxALL | wxEXPAND, 10);
    body_sizer->Add(left_sizer, 1, wxEXPAND|wxALL);
    body_sizer->Add(right_sizer, 1, wxEXPAND|wxALL);
    base_sizer->Add(body_sizer, 1, wxEXPAND);
    SetSizer(base_sizer);

}

void MainWindow::on_open_selected_button_clicked(wxCommandEvent& event) 
{
    wxString address = "./saved mems/";
    auto LW = new LearnWindow(this, "Learn", wxString::Format("%s%s.txt", address, list_box->GetStringSelection()));
    LW->Show();

}

void MainWindow::on_new_text_selected(wxCommandEvent& event)
{
    auto new_text_dialog = new TextEntryDialog(this, "New Text", wxSize(400, 500));

    
    new_text_dialog->Show();

}


void MainWindow::on_exit_selected(wxCommandEvent& event)
{
    Destroy();
}


void MainWindow::on_show_lessons(wxCommandEvent& event)
{
    auto results_dlg = new Results_Dlg(this, "results");
    results_dlg->Show();
    
}


void MainWindow::on_child_added_new_record(wxCommandEvent& event)
{
    
    list_box->Clear();
    for (int i = 0; i < DB_Manager::instance()->retrieve_results().size(); i++)
    {
        list_box->Append(DB_Manager::instance()->retrieve_results()[i].name);
    }
    
    list_box->SetSelection(list_box->GetCount()-1);
}

void MainWindow::on_remove_selected_button_clicked(wxCommandEvent& event) 
{
    DB_Manager::instance()->remove_record(list_box->GetStringSelection());

    list_box->Clear();
    for (int i = 0; i < DB_Manager::instance()->retrieve_results().size(); i++)
    {
        list_box->Append(DB_Manager::instance()->retrieve_results()[i].name);
    }

    list_box->SetSelection(list_box->GetCount()-1);

}


