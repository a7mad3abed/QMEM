#pragma once
#include <wx/wx.h>

enum {
	IdEditor = wxID_HIGHEST,
	IdSaveButton,
	IdCancelButton,
	EndEdit
};

class EditText : public wxPanel
{
public:
	EditText(wxWindow* parent, const wxString& address);
	void on_save_button_clicked(wxCommandEvent& event);
	void on_cancel_button_clicked(wxCommandEvent& event);

private:
	wxTextCtrl* m_editor;
	wxString m_address;
};
