#pragma once
#include "wx/wx.h"
#include "DB_Manager.h"

class MainWindow : public wxFrame
{
public:
	explicit MainWindow(const wxString& title);
    void on_open_selected_button_clicked(wxCommandEvent& event);
    void on_new_text_selected(wxCommandEvent& event);
    void on_exit_selected(wxCommandEvent& event);

    void on_learn_selected(wxCommandEvent &event);
    void on_show_lessons(wxCommandEvent &event);

private:
    DB_Manager dbm;
    wxListBox* list_box;

};

