#pragma once

#include "wx/wx.h"

class wxToggleButton;
class wxRichTextCtrl;

class LearnWindow : public wxFrame
{
public:
	LearnWindow(wxWindow *parent, const wxString &title, const wxString &address);
    ~LearnWindow();
	void on_hide_left_button_clicked(wxCommandEvent &event);
	void on_cancel_button_clicked(wxCommandEvent& event);
	void on_text_changed(wxCommandEvent& event);
    void on_align_left_button_clicked(wxCommandEvent& event);
    void on_align_right_button_clicked(wxCommandEvent& event);
    void on_bs_button_clicked(wxKeyEvent& event);
private:
	wxTextCtrl* first_text_{};
    wxRichTextCtrl* second_text_{};
    wxTextAttr orig_attr_{};
	wxToggleButton* hide_left;

};



