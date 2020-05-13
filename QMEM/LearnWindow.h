#pragma once

#include "wx/wx.h"

class wxToggleButton;
class wxRichTextCtrl;

enum
{
	ALIGN_LEFT_BUTTON,
	ALIGN_RIGHT_BUTTON,
	HIDE_LEFT,
	CancelLearn
};

class LearnWindow : public wxWindow
{
public:
	LearnWindow(wxWindow* parent, const wxString& title, const wxString& address);
	~LearnWindow();
	void on_hide_left_button_clicked(wxCommandEvent& event);
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
