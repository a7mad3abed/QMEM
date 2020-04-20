#pragma once
#include "wx/wx.h"

class TextEntryDialog :
	public wxDialog
{
public:
    TextEntryDialog(wxWindow *parent, const wxString &title, const wxSize &size);
    void on_save_button_clicked(wxCommandEvent& event);
    void on_cancel_button_clicked(wxCommandEvent& event);
    void on_align_left_button_clicked(wxCommandEvent& event);
    void on_align_right_button_clicked(wxCommandEvent& event);
private:
    wxTextCtrl* textEntry;

};

