#include "MainFrame.h"
#include "MainWindow.h"
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

enum
{
    id_m_book = wxID_HIGHEST
};

MainFrame::MainFrame()
    :wxFrame(nullptr, wxID_ANY, "QMEM", wxDefaultPosition, wxSize(600, 400), wxDEFAULT_FRAME_STYLE)
{
    auto sizer = new wxBoxSizer(wxHORIZONTAL);
    m_book = new wxSimplebook(this, id_m_book);
    sizer->Add(m_book, 1, wxEXPAND | wxALL, 10);
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

    // now adding the to menu items to the menu
    file->Append(new_text);
    file->Append(show_lessons);
    file->Append(exit);

    // now making the menubar and adding the file menu to it then setting it as the menubar of the frame
    auto menubar = new wxMenuBar();
    menubar->Append(file, "File");
    return menubar;
}

void MainFrame::on_new_text_selected(wxCommandEvent& event)
{
    //auto new_text_dialog = new TextEntryDialog(this, "New Text", wxSize(400, 500));

    
    //new_text_dialog->Show();

}


void MainFrame::on_exit_selected(wxCommandEvent& event)
{
    Destroy();
}

void MainFrame::on_show_lessons(wxCommandEvent& event)
{
    //results_dlg->Show();
    auto newPage = new wxPanel(m_book);
    auto results_dlg = new Results_Dlg(newPage, "results");
    m_book->AddPage(newPage, "results");
    auto sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(results_dlg, 1, wxEXPAND | wxALL, 4);
    newPage->SetSizer(sizer);
    
} 
