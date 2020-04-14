#pragma once
#include "wx/wx.h"

class TextEntryDialog :
	public wxDialog
{
public:
    TextEntryDialog(wxWindow *parent, wxString title, wxSize size);
    void OnSaveButtonClicked(wxCommandEvent& event);
    void OnCancelButtonClicked(wxCommandEvent& event);
    void OnAlignLeftButtonClicked(wxCommandEvent& event);
    void OnAlignRightButtonClicked(wxCommandEvent& event);
private:
    wxTextCtrl* textEntry;

};

