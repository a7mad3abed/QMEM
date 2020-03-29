#include "MyFrame.h"


MyFrame::MyFrame(wxString title)
	:wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(600, 400))
{
    SetBackgroundColour(wxColour(200,55,50));
	wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* textSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* firsthor = new wxBoxSizer(wxHORIZONTAL);

	firstText = new wxTextCtrl(this, -1, "", wxDefaultPosition, wxSize(400, 300), wxTE_MULTILINE);
	secondText = new wxTextCtrl(this, -1, "", wxDefaultPosition, wxSize(400, 300), wxTE_MULTILINE);
	textSizer->Add(firstText,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        10 );         // set border width to 10)

	textSizer->Add(secondText,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        10 );         // set border width to 10)

	topSizer->Add(textSizer);

	wxButton* compButton = new wxButton(this, wxID_OK, "OK");
	compButton->Bind(wxEVT_BUTTON, &MyFrame::OnCompButtonClicked, this);
	firsthor->Add(compButton, 0, wxALL, 10);

	firsthor->Add(
		new wxButton(this, wxID_CANCEL, "Cancel"),
		0,
		wxALL,
		10);
	topSizer->Add(firsthor);
	SetSizerAndFit(topSizer);

};


void MyFrame::OnCompButtonClicked(wxCommandEvent& event)
{
	for (int i = 0; i < firstText->GetNumberOfLines() || i < secondText->GetNumberOfLines(); i++)
	{
		wxString txt01 = firstText->GetLineText(i);
		wxString txt02 = secondText->GetLineText(i);
		if (txt01 == txt02)
		{
			wxMessageBox(wxString::Format("Line %d It's ok", i) );
		}
		else
			wxMessageBox(wxString::Format("Line %d is different", i) );
	}

}



