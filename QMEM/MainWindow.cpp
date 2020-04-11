#include "MainWindow.h"


MainWindow::MainWindow(wxString title)
    :wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600))
{
    CenterOnScreen();
    auto menubar = new wxMenuBar();
    auto file = new wxMenu();
    auto exit = new wxMenuItem(file, wxID_CLOSE, "close");
    file->Append(exit);
    file->Bind(wxEVT_COMMAND_MENU_SELECTED, &MainWindow::onExitSelected, this);
    menubar->Append(file, "Exit");
    SetMenuBar(menubar);
    auto baseSizer = new wxBoxSizer(wxVERTICAL);
    auto topSizer = new wxBoxSizer(wxHORIZONTAL);
    auto topPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, 100));
    auto welcomeText = new wxStaticText(topPanel, wxID_ANY, "\nWelcome to QMEM",wxDefaultPosition, wxSize(700,100), wxALIGN_CENTER);
    topSizer->Add(topPanel);
    baseSizer->Add(topSizer, 1,  wxEXPAND | wxALL);
    auto CoreSizer = new wxBoxSizer(wxHORIZONTAL);
    auto rightCoreSizer = new wxBoxSizer(wxVERTICAL);
    auto rightPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(400, 450));
    auto RCText = new wxStaticText(rightPanel, wxID_ANY, "\nWelcome to QMEM",wxDefaultPosition, wxSize(350,400), wxALIGN_CENTER);
    rightCoreSizer->Add(rightPanel,1, wxEXPAND|wxALL);
    auto leftCoreSizer = new wxBoxSizer(wxVERTICAL);
    auto leftPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(400, 450));
    auto LCText = new wxStaticText(leftPanel, wxID_ANY, "\nWelcome to QMEM",wxDefaultPosition, wxSize(350,400), wxALIGN_CENTER);
    leftCoreSizer->Add(leftPanel, 1, wxEXPAND|wxALL);
    CoreSizer->Add(rightCoreSizer);
    CoreSizer->Add(leftCoreSizer);
    baseSizer->Add(CoreSizer);
    SetSizer(baseSizer);

}

void MainWindow::onExitSelected(wxCommandEvent& event)
{
    Destroy();
}
