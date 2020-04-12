#pragma once
#include "wx/wx.h"

class textEntryDialog :
	public wxDialog
{
public:
    textEntryDialog(wxWindow *parent, wxString title, wxSize size);
    void OnSaveButtonClicked(wxCommandEvent& event);
    void OnAlignLeftButtonClicked(wxCommandEvent& event);
    void OnAlignRightButtonClicked(wxCommandEvent& event);
private:
    wxTextCtrl* textEntry;

};

