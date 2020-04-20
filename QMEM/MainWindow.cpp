#include "MainWindow.h"
#include "textEntryDialog.h"
#include "LearnWindow.h"

enum {
    NEWTEXT = 45,
    LEARN
};

MainWindow::MainWindow(const wxString& title)
    :wxFrame(
            nullptr,
            wxID_ANY,
            title,
            wxDefaultPosition,
            wxDefaultSize,
        wxDEFAULT_FRAME_STYLE
    )

{
    wxIcon mainIcon;
    mainIcon.LoadFile("Qmem.ico", wxBITMAP_TYPE_ICO);
    this->SetIcon(mainIcon);
    CenterOnScreen();
    
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

    auto learn = new wxMenuItem(file, LEARN, "Learn");
    file->Bind(
            wxEVT_COMMAND_MENU_SELECTED,
            &MainWindow::on_learn_selected,
            this,
            LEARN);

    // now adding the to menu items to the menu
    file->Append(new_text);
    file->Append(learn);
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

    auto baseSizer = new wxBoxSizer(wxVERTICAL);
    auto topSizer = new wxBoxSizer(wxHORIZONTAL);

    auto welcomeText = new wxStaticText(
            this,
            wxID_ANY,
            "",
            wxDefaultPosition,
            wxSize(600, 50),
            wxALIGN_CENTER);

    welcomeText->SetLabel("Welcome to Qmem");
    welcomeText->SetFont(f);
    welcomeText->SetForegroundColour(wxColour("red"));

    topSizer->Add(welcomeText, 1, wxEXPAND|wxALL, 10);
    baseSizer->Add(topSizer, 0,   wxALIGN_CENTRE|wxALL, 10);
    auto *core_sizer = new wxBoxSizer(wxHORIZONTAL);
    auto *right_core_sizer = new wxBoxSizer(wxVERTICAL);
    auto *rc_text = new wxStaticText(
            this,
            wxID_ANY,
            "",
            wxDefaultPosition,
            wxSize(300, 50),
            wxALIGN_CENTER);
    auto rc_text01 = new wxStaticText(
            this,
            wxID_ANY,
            "",
            wxDefaultPosition,
            wxDefaultSize,
            wxALIGN_CENTER);
    auto rc_text02 = new wxStaticText(
            this,
            wxID_ANY,
            "",
            wxDefaultPosition,
            wxDefaultSize,
            wxALIGN_CENTER);

    right_core_sizer->Add(rc_text,1, wxEXPAND|wxALL, 10);
    right_core_sizer->Add(rc_text01,1, wxEXPAND|wxALL, 10);
    right_core_sizer->Add(rc_text02,1, wxEXPAND|wxALL, 10);
    auto leftCoreSizer = new wxBoxSizer(wxVERTICAL);
    auto lc_text = new wxStaticText(
            this,
            wxID_ANY,
            "",
            wxDefaultPosition,
            wxSize(300, 50),
            wxALIGN_CENTER);
    leftCoreSizer->Add(lc_text, 0, wxALL, 10);
    core_sizer->Add(leftCoreSizer, 1, wxEXPAND|wxALL);
    core_sizer->Add(right_core_sizer, 1, wxEXPAND|wxALL);
    baseSizer->Add(core_sizer, 1, wxEXPAND|wxALL);
    SetSizerAndFit(baseSizer);

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

void MainWindow::on_learn_selected(wxCommandEvent &event)
{
    auto my_frame = new LearnWindow(this, "Learn");

    my_frame->Show();

}
