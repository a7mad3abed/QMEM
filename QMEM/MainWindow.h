#pragma once
#include "wx/wx.h"

class MainWindow : public wxFrame
{
public:
    MainWindow(const wxString& title);
    void onNewTextSelected(wxCommandEvent& event);
    void onExitSelected(wxCommandEvent& event);

    void onLearnSelected(wxCommandEvent &event);
};

