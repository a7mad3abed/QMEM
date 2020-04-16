#include "MainWindow.h"
#include "textEntryDialog.h"
#include "LearnWindow.h"

enum {
    NEWTEXT = 45,
    LEARN
};

MainWindow::MainWindow(wxString title)
    :wxFrame(
            NULL,
            wxID_ANY,
            title,
            wxDefaultPosition,
            wxSize(800, 600),
        wxDEFAULT_FRAME_STYLE ^ wxMAXIMIZE_BOX ^ wxRESIZE_BORDER
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

    // now making the menuar and adding the file menu to it then setting it as the menubar of the frame
    auto menubar = new wxMenuBar();
    menubar->Append(file, "File");
    SetMenuBar(menubar);

    auto baseSizer = new wxBoxSizer(wxVERTICAL);
    auto topSizer = new wxBoxSizer(wxHORIZONTAL);
    auto topPanel = new wxPanel(
            this,
            wxID_ANY,
            wxDefaultPosition,
            wxSize(800, 100));
    auto welcomeText = new wxStaticText(
            topPanel,
            wxID_ANY,
            "\nWelcome to QMEM",
            wxDefaultPosition,
            wxSize(700,100),
            wxALIGN_CENTER);
    topSizer->Add(topPanel);
    baseSizer->Add(topSizer, 1,  wxEXPAND | wxALL);
    auto CoreSizer = new wxBoxSizer(wxHORIZONTAL);
    auto rightCoreSizer = new wxBoxSizer(wxVERTICAL);
    auto rightPanel = new wxPanel(
            this,
            wxID_ANY,
            wxDefaultPosition,
            wxSize(400, 500));
    auto RCText = new wxStaticText(
            rightPanel,
            wxID_ANY,
            "\nWelcome to QMEM",
            wxDefaultPosition,
            wxSize(400,500),
            wxALIGN_CENTER);
    rightCoreSizer->Add(rightPanel,1, wxEXPAND|wxALL);
    auto leftCoreSizer = new wxBoxSizer(wxVERTICAL);
    auto leftPanel = new wxPanel(
            this,
            wxID_ANY,
            wxDefaultPosition,
            wxSize(400, 500));
    auto LCText = new wxStaticText(
            leftPanel,
            wxID_ANY,
            "\nWelcome to QMEM",
            wxDefaultPosition,
            wxSize(400,500),
            wxALIGN_CENTER);
    leftCoreSizer->Add(leftPanel, 1, wxEXPAND|wxALL);
    CoreSizer->Add(rightCoreSizer);
    CoreSizer->Add(leftCoreSizer);
    baseSizer->Add(CoreSizer);
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
