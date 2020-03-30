#include "MyFrame.h"


MyFrame::MyFrame(wxString title)
	:wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(600, 400))
{
    SetBackgroundColour(wxColour(200,55,70));
	wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* textSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* firsthor = new wxBoxSizer(wxHORIZONTAL);

	firstText = new wxTextCtrl(this, -1, "", wxDefaultPosition, wxSize(400, 300), wxTE_MULTILINE);
	firstText->LoadFile("textTest.txt", wxTEXT_TYPE_ANY);
	secondText = new wxTextCtrl(this, -1, "", wxDefaultPosition, wxSize(400, 300), wxTE_MULTILINE);
	textSizer->Add(firstText,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        10 );         // set border width to 10)

	textSizer->Add(secondText,
        1,            // make vertically stretchableM
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        10 );         // set border width to 10)

	topSizer->Add(textSizer);

	wxButton* compButton = new wxButton(this, wxID_OK, "OK");
	compButton->Bind(wxEVT_BUTTON, &MyFrame::OnCompButtonClicked, this);
	wxButton* cancelButton = new wxButton(this, wxID_CANCEL, "Cancel");
	cancelButton->Bind(wxEVT_BUTTON, &MyFrame::OnCancelButtonClicked, this);
	firsthor->Add(compButton, 0, wxALL, 10);

	firsthor->Add(
		cancelButton,
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
		{
			if (firstText->SetStyle(0, 2, wxTextAttr(wxColour(200, 0, 20))))
				wxMessageBox("changed");
			wxMessageBox(wxString::Format("Line %d is different", i));
		}
	}

}

void MyFrame::OnCancelButtonClicked(wxCommandEvent& event)
{
	this->Destroy();

}


