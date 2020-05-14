#pragma once
#include "wx/wx.h"

enum {
	SAVE_BUTTON = 77,
	ALIGN_RIGHT_BUTTON,
	ALIGN_LEFT_BUTTON,
	SaveSuccessful,
	New_Canel_Button
};

class TextEntryDialog :
	public wxWindow
{
public:
	TextEntryDialog(wxWindow* parent, const wxString& title, const wxSize& size);
	~TextEntryDialog();
	void on_save_button_clicked(wxCommandEvent& event);
	void on_cancel_button_clicked(wxCommandEvent& event);
	void on_align_left_button_clicked(wxCommandEvent& event);
	void on_align_right_button_clicked(wxCommandEvent& event);
private:
	wxTextCtrl* textEntry;
};
