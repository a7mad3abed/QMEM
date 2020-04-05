#pragma once
#include "wx/wx.h"


class MyFrame : public wxFrame
{
public:
	MyFrame(wxString title);
    ~MyFrame();
	void OnCompButtonClicked(wxCommandEvent &event);
	void OnCancelButtonClicked(wxCommandEvent& event);
	void OnTextChanged(wxCommandEvent& event);
private:
	wxTextCtrl* firstText;
	wxTextCtrl* secondText;
	wxStaticText* resultText;
	wxTextAttr origAttr;

};


