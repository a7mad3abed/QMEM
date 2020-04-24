#pragma once
#include "wx/wx.h"

class MainWindow : public wxFrame
{
public:
	explicit MainWindow(const wxString& title);
    void on_new_text_selected(wxCommandEvent& event);
    void on_exit_selected(wxCommandEvent& event);

    void on_learn_selected(wxCommandEvent &event);
    void on_show_lessons(wxCommandEvent &event);


};

