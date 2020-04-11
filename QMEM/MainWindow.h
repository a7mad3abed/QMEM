#pragma once
#include "wx/wx.h"

class MainWindow : public wxFrame
{
public:
    MainWindow(wxString title);
    void onExitSelected(wxCommandEvent& event);

};

