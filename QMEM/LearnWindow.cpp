#include "LearnWindow.h"


LearnWindow::LearnWindow(wxWindow *parent, wxString title)
	:wxFrame(
        parent,
        wxID_ANY,
        title,
        wxDefaultPosition,
        wxSize(800, 600),
        wxDEFAULT_FRAME_STYLE ^ wxMAXIMIZE_BOX ^ wxRESIZE_BORDER
	)
{
    SetBackgroundColour(wxColour(187,25,25));
    auto* topSizer = new wxBoxSizer(wxVERTICAL);
    auto* commenTextSizer = new wxBoxSizer(wxHORIZONTAL);
	auto* firstTextSizer = new wxBoxSizer(wxHORIZONTAL);
	auto* secondTextSizer = new wxBoxSizer(wxHORIZONTAL);
	auto resultSizer = new wxBoxSizer(wxHORIZONTAL);
	auto firsthor = new wxBoxSizer(wxHORIZONTAL);

	firstText = new wxTextCtrl(
        this,
        -1,
        "click open to load a learn file",
        wxDefaultPosition,
        wxSize(350, 300),
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
        wxSize(400, 100),
        wxALIGN_CENTER);

	firstTextSizer->Add(firstText,
        1,            // make vertically stretchable
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        10 );         // set border width to 10)


	secondTextSizer->Add(secondText,
        1,            // make vertically stretchableM
        wxEXPAND |    // make horizontally stretchable
        wxALL,        //   and make border all around
        10 );         // set border width to 10)

	commenTextSizer->Add(firstTextSizer);
	commenTextSizer->Add(secondTextSizer);
	topSizer->Add(commenTextSizer);

	wxButton* openButton = new wxButton(this, wxID_OK, "Open");
	openButton->Bind(wxEVT_BUTTON, &LearnWindow::OnOpenButtonClicked, this);
	wxButton* cancelButton = new wxButton(this, wxID_CANCEL, "Cancel");
	cancelButton->Bind(wxEVT_BUTTON, &LearnWindow::OnCancelButtonClicked, this);
	firsthor->Add(openButton, 0, wxALL, 10);

	firsthor->Add(
		cancelButton,
		0,
		wxALL,
		10);
	firsthor->Add(resultText, 1, wxEXPAND | wxALL, 10);

	topSizer->Add(firsthor);
	SetSizer(topSizer);

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

