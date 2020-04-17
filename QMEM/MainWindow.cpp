#include "MainWindow.h"
#include "textEntryDialog.h"
#include "LearnWindow.h"

enum {
    NEWTEXT = 45,
    LEARN
};

MainWindow::MainWindow(const wxString& title)
    :wxFrame(
            NULL,
            wxID_ANY,
            title,
            wxDefaultPosition,
            wxDefaultSize,
        wxDEFAULT_FRAME_STYLE
    )

{
    CenterOnScreen();
    
    // making a new menu with name file
    auto file = new wxMenu();

    // making a new menu item with the name exit and binding it to the corresponding event
    auto exit = new wxMenuItem(file, wxID_CLOSE, "Exit");
    file->Bind(
            wxEVT_COMMAND_MENU_SELECTED,
            &MainWindow::onExitSelected,
            this,
            wxID_CLOSE);

    // making a new menu item with the name newText and binding it to the corresponding event
    auto newText = new wxMenuItem(file, NEWTEXT, "new text");
    file->Bind(
            wxEVT_COMMAND_MENU_SELECTED,
            &MainWindow::onNewTextSelected,
            this,
            NEWTEXT);

    auto learn = new wxMenuItem(file, LEARN, "learn");
    file->Bind(
            wxEVT_COMMAND_MENU_SELECTED,
            &MainWindow::onLearnSelected,
            this,
            LEARN);

    // now adding the to menu items to the menu
    file->Append(newText);
    file->Append(learn);
    file->Append(exit);

    // now making the menubar and adding the file menu to it then setting it as the menubar of the frame
    auto menubar = new wxMenuBar();
    menubar->Append(file, "File");
    SetMenuBar(menubar);

    auto baseSizer = new wxBoxSizer(wxVERTICAL);
    auto topSizer = new wxBoxSizer(wxHORIZONTAL);
    auto welcomeText = new wxStaticText(
            this,
            wxID_ANY,
            "\nWelcome to QMEM",
            wxDefaultPosition,
            wxSize(600, 50),
            wxALIGN_CENTER);
    topSizer->Add(welcomeText, 1, wxEXPAND|wxALL, 10);
    baseSizer->Add(topSizer, 0,   wxALIGN_CENTRE|wxALL, 10);
    auto CoreSizer = new wxBoxSizer(wxHORIZONTAL);
    auto rightCoreSizer = new wxBoxSizer(wxVERTICAL);
    auto RCText = new wxStaticText(
            this,
            wxID_ANY,
            "\nWelcome to QMEM",
            wxDefaultPosition,
            wxSize(300, 50),
            wxALIGN_CENTER);
    auto RCText01 = new wxStaticText(
            this,
            wxID_ANY,
            "\nWelcome to QMEM",
            wxDefaultPosition,
            wxDefaultSize,
            wxALIGN_CENTER);
    auto RCText02 = new wxStaticText(
            this,
            wxID_ANY,
            "\nWelcome to QMEM",
            wxDefaultPosition,
            wxDefaultSize,
            wxALIGN_CENTER);
    rightCoreSizer->Add(RCText,1, wxEXPAND|wxALL, 10);
    rightCoreSizer->Add(RCText01,1, wxEXPAND|wxALL, 10);
    rightCoreSizer->Add(RCText02,1, wxEXPAND|wxALL, 10);
    auto leftCoreSizer = new wxBoxSizer(wxVERTICAL);
    auto LCText = new wxStaticText(
            this,
            wxID_ANY,
            "\nWelcome to QMEM",
            wxDefaultPosition,
            wxSize(300, 50),
            wxALIGN_CENTER);
    leftCoreSizer->Add(LCText, 0, wxALL, 10);
    CoreSizer->Add(leftCoreSizer, 1, wxEXPAND|wxALL);
    CoreSizer->Add(rightCoreSizer, 1, wxEXPAND|wxALL);
    baseSizer->Add(CoreSizer, 1, wxEXPAND|wxALL);
    SetSizerAndFit(baseSizer);

}

void MainWindow::onNewTextSelected(wxCommandEvent& event)
{
    auto newTextDialog = new TextEntryDialog(this, "New Text", wxSize(400, 500));

    
    newTextDialog->Show();

}

void MainWindow::onExitSelected(wxCommandEvent& event)
{
    Destroy();
}

void MainWindow::onLearnSelected(wxCommandEvent &event)
{
    auto myFrame = new LearnWindow(this, "Learn");

    myFrame->Show();

}
