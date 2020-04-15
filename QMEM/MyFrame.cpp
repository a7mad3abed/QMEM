#include "MyFrame.h"


MyFrame::MyFrame(wxWindow *parent, wxString title)
	:wxFrame(
        parent,
        wxID_ANY,
        title,
        wxDefaultPosition,
        wxSize(600, 400))
{
    SetBackgroundColour(wxColour(187,25,25));
	wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* textSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* resultSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* firsthor = new wxBoxSizer(wxHORIZONTAL);

	firstText = new wxTextCtrl(
        this,
        -1,
        "",
        wxDefaultPosition,
        wxSize(400, 300),
        wxTE_MULTILINE|wxTE_RICH2|wxTE_READONLY);

	//firstText->LoadFile("text01.txt", wxTEXT_TYPE_ANY);
	secondText = new wxTextCtrl(
        this,
        -1,
        "",
        wxDefaultPosition,
        wxSize(400, 300),
        wxTE_MULTILINE | wxTE_RICH2);

    secondText->Bind(wxEVT_TEXT, &MyFrame::OnTextChanged, this);
	secondText->GetStyle(0, origAttr);
	secondText->SetFocus();

	resultText = new wxStaticText(
        this,
        wxID_ANY,
        "Results\n",
        wxDefaultPosition,
        wxSize(400, 100),
        wxALIGN_CENTER);

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

	wxButton* openButton = new wxButton(this, wxID_OK, "OK");
	openButton->Bind(wxEVT_BUTTON, &MyFrame::OnOpenButtonClicked, this);
	wxButton* cancelButton = new wxButton(this, wxID_CANCEL, "Cancel");
	cancelButton->Bind(wxEVT_BUTTON, &MyFrame::OnCancelButtonClicked, this);
	firsthor->Add(openButton, 0, wxALL, 10);

	firsthor->Add(
		cancelButton,
		0,
		wxALL,
		10);
	firsthor->Add(resultText, 1, wxEXPAND | wxALL, 10);

	topSizer->Add(firsthor);
	SetSizerAndFit(topSizer);

};

MyFrame::~MyFrame()
{
}


void MyFrame::OnOpenButtonClicked(wxCommandEvent& event)
{
	wxString str;
    wxFileDialog openFileDialog(this, _("Open text file"), "", "", "text files (*.txt)|*.txt", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;
    firstText->LoadFile(openFileDialog.GetPath(), 0);


}

void MyFrame::OnCancelButtonClicked(wxCommandEvent& event)
{
	this->Destroy();

}

void MyFrame::OnTextChanged(wxCommandEvent& event)
{
        auto pos2 = secondText->GetLastPosition();
		resultText->SetLabelText(wxString::Format("%ld\n", pos2));

		auto txt01 = firstText->GetValue();
		auto txt02 = secondText->GetValue();

		auto lengthOftxt01 = firstText->GetValue().length();
		auto lengthOftxt02 = secondText->GetValue().length();


		if (pos2 == 0) secondText->SetStyle(0, 100, origAttr);
		if (pos2 != 0 && (txt01[pos2-1] != txt02[pos2-1]))
		{
            ::wxBell();
			wxTextAttr attr;
			attr.SetTextColour(*wxRED);
			secondText->SetStyle(pos2-1, pos2, attr);
		}
		if (pos2 != 0 && (txt01[pos2 - 1] == txt02[pos2 - 1]))
		{
			secondText->SetStyle(pos2, pos2+1, origAttr);
		}

    if(lengthOftxt01 == lengthOftxt02) {
        wxMessageBox("Congratulation!");
        Destroy();
    }
}

