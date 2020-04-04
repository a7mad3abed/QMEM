#include "MyFrame.h"


MyFrame::MyFrame(wxString title)
	:wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(600, 400))
{
    SetBackgroundColour(wxColour(58, 168, 199));
	wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* textSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* resultSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* firsthor = new wxBoxSizer(wxHORIZONTAL);

	firstText = new wxTextCtrl(this, -1, "", wxDefaultPosition, wxSize(400, 300),  wxTE_MULTILINE|wxTE_RICH2|wxTE_READONLY);
	firstText->LoadFile("text01.txt", wxTEXT_TYPE_ANY);
	secondText = new wxTextCtrl(this, -1, "", wxDefaultPosition, wxSize(400, 300), wxTE_MULTILINE | wxTE_RICH2);
    secondText->Bind(wxEVT_TEXT, &MyFrame::OnTextChanged, this);
	resultText = new wxStaticText(this, wxID_ANY, "Results\n", wxDefaultPosition, wxSize(400, 100), wxALIGN_CENTER);
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
	firsthor->Add(resultText, 1, wxEXPAND | wxALL, 10);
	topSizer->Add(firsthor);
	SetSizerAndFit(topSizer);

};


void MyFrame::OnCompButtonClicked(wxCommandEvent& event)
{
	wxString str;
	str.append("Results\n");
	for (int i = 0; i < firstText->GetNumberOfLines() || i < secondText->GetNumberOfLines(); i++)
	{
		wxString txt01 = firstText->GetLineText(i);
		wxString txt02 = secondText->GetLineText(i);
		if (txt01 != txt02)
		{
			wxTextAttr attr;
			attr.SetTextColour(*wxRED);
			firstText->SetStyle(4, 8, attr);
			str.append(wxString::Format("Line %d is different\n", i));
		}
	}
	resultText->SetLabelText(str);

}

void MyFrame::OnCancelButtonClicked(wxCommandEvent& event)
{
	this->Destroy();

}

void MyFrame::OnTextChanged(wxCommandEvent& event)
{
        auto pos1 = firstText->GetLastPosition();
        auto pos2 = secondText->GetLastPosition();
		wxString txt01 = firstText->GetValue();
		wxString txt02 = secondText->GetValue();
		if (txt01.GetChar(pos1) != txt02.GetChar(pos1))
		{
            resultText->SetLabelText(wxString::Format("%d",pos1));
            resultText->SetLabelText(wxString::Format("%d",pos2));
			wxTextAttr attr;
			attr.SetTextColour(*wxRED);
			secondText->SetStyle(pos2,pos2,attr);
		//	str.append(wxString::Format("Line %d is different\n", i));
		}
	//resultText->SetLabelText(str);

    //wxString str = resultText->GetLabelText();
    //str.append("text Changed!\n");
    //resultText->SetLabelText(str);

}

