#include "LearnWindow.h"


LearnWindow::LearnWindow(wxWindow *parent, wxString title)
	:wxFrame(
        parent,
        wxID_ANY,
        title,
        wxDefaultPosition,
        wxDefaultSize,
        wxDEFAULT_FRAME_STYLE
	)
{
    SetBackgroundColour(wxColour(187,25,25));
    auto* topSizer = new wxBoxSizer(wxVERTICAL);
    auto* textSizer = new wxBoxSizer(wxHORIZONTAL);
	auto controlSizer = new wxBoxSizer(wxHORIZONTAL);

	firstText = new wxTextCtrl(
        this,
        -1,
        "click open to load a learn file",
        wxDefaultPosition,
        wxSize(300, 300),
        wxTE_MULTILINE|wxTE_RICH2|wxTE_READONLY|wxALIGN_LEFT);
    

	//firstText->LoadFile("text01.txt", wxTEXT_TYPE_ANY);
	secondText = new wxTextCtrl(
        this,
        -1,
        "",
        wxDefaultPosition,
        wxSize(350, 300),
        wxTE_MULTILINE | wxTE_RICH2| wxALIGN_RIGHT);

    secondText->Bind(wxEVT_TEXT, &LearnWindow::OnTextChanged, this);
	secondText->GetStyle(0, origAttr);
	secondText->SetEditable(false);


	resultText = new wxStaticText(
        this,
        wxID_ANY,
        "Results\n",
        wxDefaultPosition,
        wxSize(400, 20),
        wxALIGN_RIGHT
        );

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

	topSizer->Add(textSizer, 1, wxEXPAND|wxALL);

	auto openButton = new wxButton(this, wxID_OK, "Open");
	openButton->Bind(wxEVT_BUTTON, &LearnWindow::OnOpenButtonClicked, this);
	auto cancelButton = new wxButton(this, wxID_CANCEL, "Cancel");
	cancelButton->Bind(wxEVT_BUTTON, &LearnWindow::OnCancelButtonClicked, this);
	controlSizer->AddSpacer(10);
	controlSizer->Add(openButton, 0, wxALL, 10);
    controlSizer->AddSpacer(5);

	controlSizer->Add(
		cancelButton,
		0,
		wxALL,
		10);

	controlSizer->Add(resultText, 0, wxALL, 10);

	topSizer->Add(controlSizer, 0, wxEXPAND|wxALL);
	SetSizerAndFit(topSizer);

};

LearnWindow::~LearnWindow()
= default;


void LearnWindow::OnOpenButtonClicked(wxCommandEvent& event)
{

	wxString str;
    wxFileDialog openFileDialog(this, _("Open text file"), "", "", "text files (*.txt)|*.txt", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;
    firstText->LoadFile(openFileDialog.GetPath(), 0);
    secondText->SetEditable(true);
	secondText->SetFocus();


}

void LearnWindow::OnCancelButtonClicked(wxCommandEvent& event)
{
	this->Destroy();

}

void LearnWindow::OnTextChanged(wxCommandEvent& event)
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
            if(lengthOftxt01 == lengthOftxt02) {
                wxMessageBox("Congratulation!");
                Destroy();
            }
		}

}

