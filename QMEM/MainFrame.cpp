#include "MainFrame.h"
#include "MainWindow.h"
#include "Results_Dlg.h"
#include "TextEntryWindow.h"
#include "LearnWindow.h"

enum {
    NEWTEXT = 45,
    LEARN,
    SHOW,
    START,
    BUTTON_LIST_OPEN,
	REMOVE_RECORD,
	WELCOME,
	POPUP_TEST,
	IdLearn
};

#define CLOSE_TO_WINDOW 66

enum
{
    id_m_book = wxID_HIGHEST
};

MainFrame::MainFrame()
    :wxFrame(nullptr, wxID_ANY, "QMEM", wxDefaultPosition, wxSize(800, 600), wxDEFAULT_FRAME_STYLE)
{
    Center();
    CreateStatusBar(2);
    SetStatusText(wxT("Welcome to Qmem"));
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::on_child_added_new_record, this, CLOSE_TO_WINDOW);
    Bind(wxEVT_BUTTON, &MainFrame::on_exit_selected, this, CancelLearn);
    auto sizer = new wxBoxSizer(wxVERTICAL);
    m_book = new wxSimplebook(this, id_m_book);

    auto start_panel = new wxPanel(m_book,wxID_ANY);

    DB_Manager::instance()->init_db();

   list_box = new wxListBox(
            start_panel,
            BUTTON_LIST_OPEN,
            wxDefaultPosition,
            wxDefaultSize
            );

    for (int i = 0; i < DB_Manager::instance()->retrieve_results().size(); i++)
    {
        list_box->Append(DB_Manager::instance()->retrieve_results()[i].name);
    }
    Bind(wxEVT_LISTBOX_DCLICK, &MainFrame::on_open_selected_button_clicked, this, BUTTON_LIST_OPEN);
    Bind(wxEVT_BUTTON, &MainFrame::on_remove_selected_button_clicked, this, REMOVE_RECORD);
    Bind(wxEVT_BUTTON, &MainFrame::on_learn_selected_button_clicked, this, IdLearn);

    auto remove_selected_button = new wxButton(start_panel, REMOVE_RECORD, "remove");
    auto learn_selected_button = new wxButton(start_panel, IdLearn, "learn");

    auto list_box_sizer = new wxBoxSizer(wxVERTICAL);
    list_box_sizer->Add(list_box, 1, wxEXPAND | wxALL, 10);
    list_box_sizer->Add(remove_selected_button, 0,  wxLEFT|wxBOTTOM, 10);
    list_box_sizer->Add(learn_selected_button, 0,  wxLEFT|wxBOTTOM, 10);
    start_panel->SetSizer(list_box_sizer);

    m_book->AddPage(start_panel, "Start");
	results_dlg = new Results_Dlg(m_book, "results");
	m_book->AddPage(results_dlg, "results");
    auto new_text_dialog = new TextEntryDialog(m_book, "New Text", wxDefaultSize);
    m_book->AddPage(new_text_dialog, "new text");
    m_book->SetSelection(0);

    wxFont f(
            18,
            wxFONTFAMILY_DEFAULT,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD,
            false,
            "Tahoma");

    auto welcome_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    auto welcome_sizer = new wxBoxSizer(wxHORIZONTAL);
    auto welcomeText = new wxStaticText(
            welcome_panel,
            WELCOME,
            "",
            wxDefaultPosition,
            wxDefaultSize,
            wxALIGN_CENTER
            );
    welcome_sizer->Add(welcomeText, 1, wxEXPAND | wxALL);
    welcome_panel->SetSizer(welcome_sizer);

    welcomeText->SetLabel("Welcome to Qmem");
    welcomeText->SetFont(f);
    welcomeText->SetForegroundColour(wxColour("red"));
 

    sizer->Add(welcome_panel, 0.5, wxEXPAND | wxALL);
    sizer->Add(m_book, 3, wxEXPAND | wxALL, 0);
    SetSizer(sizer);
    SetMenuBar(make_m_bar());

}

wxMenuBar* MainFrame::make_m_bar()
{
    auto file = new wxMenu();

    // making a new menu item with the name exit and binding it to the corresponding event
    auto exit = new wxMenuItem(file, wxID_CLOSE, "Exit");
    file->Bind(
            wxEVT_COMMAND_MENU_SELECTED,
            &MainFrame::on_exit_selected,
            this,
            wxID_CLOSE);

	

    // making a new menu item with the name newText and binding it to the corresponding event
    auto new_text = new wxMenuItem(file, NEWTEXT, "New text");
    file->Bind(
            wxEVT_COMMAND_MENU_SELECTED,
            &MainFrame::on_new_text_selected,
            this,
            NEWTEXT);


    auto show_lessons = new wxMenuItem(file, SHOW, "Show Lessons");
    file->Bind(
            wxEVT_COMMAND_MENU_SELECTED,
            &MainFrame::on_show_lessons,
            this,
            SHOW);

    auto show_start = new wxMenuItem(file, START, "Show Start");
    file->Bind(
            wxEVT_COMMAND_MENU_SELECTED,
            &MainFrame::on_show_start,
            this,
            START);

    // now adding the to menu items to the menu
    file->Append(new_text);
    file->Append(show_lessons);
    file->Append(show_start);
    file->Append(exit);

    // now making the menubar and adding the file menu to it then setting it as the menubar of the frame
    auto menubar = new wxMenuBar();
    menubar->Append(file, "File");
    return menubar;
}

void MainFrame::on_new_text_selected(wxCommandEvent& event)
{
   /* m_book->DeleteAllPages();
    auto new_text_dialog = new TextEntryDialog(m_book, "New Text", wxDefaultSize);
    m_book->AddPage(new_text_dialog, "new text");*/
    m_book->SetSelection(2);
}


void MainFrame::on_exit_selected(wxCommandEvent& event)
{
    //Destroy();
    m_book->SetSelection(0);
    m_book->DeletePage(3);
}

void MainFrame::on_show_lessons(wxCommandEvent& event)
{
    results_dlg->update_results();
    m_book->SetSelection(1);

} 

void MainFrame::on_show_start(wxCommandEvent& event)
{
    m_book->SetSelection(0);
    list_box->Clear();
    for (int i = 0; i < DB_Manager::instance()->retrieve_results().size(); i++)
    {
        list_box->Append(DB_Manager::instance()->retrieve_results()[i].name);
    }
    
    list_box->SetSelection(list_box->GetCount()-1);
}

void MainFrame::on_child_added_new_record(wxCommandEvent& event)
{
    
    list_box->Clear();
    for (int i = 0; i < DB_Manager::instance()->retrieve_results().size(); i++)
    {
        list_box->Append(DB_Manager::instance()->retrieve_results()[i].name);
    }
    
    list_box->SetSelection(list_box->GetCount()-1);
}

void MainFrame::on_remove_selected_button_clicked(wxCommandEvent& event) 
{
    DB_Manager::instance()->remove_record(list_box->GetStringSelection());
    wxRemoveFile(wxString::Format("./saved mems/%s.txt", list_box->GetStringSelection()));

    list_box->Clear();
    for (int i = 0; i < DB_Manager::instance()->retrieve_results().size(); i++)
    {
        list_box->Append(DB_Manager::instance()->retrieve_results()[i].name);
    }

    list_box->SetSelection(list_box->GetCount()-1);

}

void MainFrame::on_open_selected_button_clicked(wxCommandEvent& event) 
{
    //wxString address = "./saved mems/";
    //auto LW = new LearnWindow(this, "Learn", wxString::Format("%s%s.txt", address, list_box->GetStringSelection()));
    //LW->Show();

}

void MainFrame::on_learn_selected_button_clicked(wxCommandEvent &event) {
    wxString address = "./saved mems/";
    auto LW = new LearnWindow(m_book, "Learn", wxString::Format("%s%s.txt", address, list_box->GetStringSelection()));
    m_book->AddPage(LW, "Learn");
    m_book->SetSelection(3);
}
