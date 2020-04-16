#pragma once
#include "wx/wx.h"


class LearnWindow : public wxFrame
{
public:
	LearnWindow(wxWindow *parent, wxString title);
    ~LearnWindow();
	void OnOpenButtonClicked(wxCommandEvent &event);
	void OnCancelButtonClicked(wxCommandEvent& event);
	void OnTextChanged(wxCommandEvent& event);
private:
	wxTextCtrl* firstText;
	wxTextCtrl* secondText;
	wxStaticText* resultText;
	wxTextAttr origAttr;

};


