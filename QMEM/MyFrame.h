#pragma once
#include "wx/wx.h"


class MyFrame : public wxFrame
{
public:
	MyFrame(wxString title);
	void OnCompButtonClicked(wxCommandEvent &event);
private:
	wxTextCtrl* firstText;
	wxTextCtrl* secondText;

};


