#pragma once
#include "wx/wx.h"


class LearnWindow : public wxFrame
{
public:
	LearnWindow(wxWindow *parent, const wxString &title);
    ~LearnWindow();
	void on_open_button_clicked(wxCommandEvent &event);
	void on_cancel_button_clicked(wxCommandEvent& event);
	void on_text_changed(wxCommandEvent& event);
private:
	wxTextCtrl* first_text_{};
	wxTextCtrl* second_text_{};
	wxStaticText* result_text_{};
	wxTextAttr orig_attr_;

};


