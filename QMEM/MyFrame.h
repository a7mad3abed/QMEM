#pragma once
#include "wx/wx.h"


class MyFrame : public wxFrame
{
public:
	MyFrame(wxWindow *parent, wxString title);
    ~MyFrame();
	void OnOpenButtonClicked(wxCommandEvent &event);
	void OnCancelButtonClicked(wxCommandEvent& event);
	void OnTextChanged(wxCommandEvent& event);
private:
	wxTextCtrl* firstText;
	wxTextCtrl* secondText;
	wxStaticText* resultText;
	wxTextAttr origAttr;

};


