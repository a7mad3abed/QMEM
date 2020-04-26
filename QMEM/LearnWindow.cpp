#include "LearnWindow.h"
#include "wx/tglbtn.h"

enum
{
	HIDE_LEFT
};


LearnWindow::LearnWindow(wxWindow *parent, const wxString &title, const wxString &address)
	:wxFrame(
        parent,
        wxID_ANY,
        title,
        wxDefaultPosition,
        wxDefaultSize,
        wxDEFAULT_FRAME_STYLE
	)
{
	wxWindowBase::SetBackgroundColour(wxColour(187,25,25));
    auto* top_sizer = new wxBoxSizer(wxVERTICAL);
    auto* text_sizer = new wxBoxSizer(wxHORIZONTAL);
	auto* control_sizer = new wxBoxSizer(wxHORIZONTAL);

	first_text_ = new wxTextCtrl(
        this,
        -1,
        "click open to load a learn file",
        wxDefaultPosition,
        wxSize(350, 300),
        wxTE_MULTILINE|wxTE_RICH2|wxTE_READONLY|wxALIGN_LEFT);
    first_text_->LoadFile(address, wxTEXT_TYPE_ANY);

	//firstText->LoadFile("text01.txt", wxTEXT_TYPE_ANY);
	second_text_ = new wxTextCtrl(
        this,
        -1,
        "",
        wxDefaultPosition,
        wxSize(350, 300),
        wxTE_MULTILINE | wxTE_RICH2| wxALIGN_RIGHT);

    second_text_->Bind(wxEVT_TEXT, &LearnWindow::on_text_changed, this);
	second_text_->GetStyle(0, orig_attr_);
	//secondText->SetEditable(false);
	//second_text_->Show(false);


	result_text_ = new wxStaticText(
        this,
        wxID_ANY,
        "Results\n",
        wxDefaultPosition,
        wxSize(400, 20),
        wxALIGN_RIGHT
        );

	text_sizer->Add(first_text_,
        0,            // make vertically stretchable
        wxALL|
        wxRESERVE_SPACE_EVEN_IF_HIDDEN,
        10 );         // set border width to 10)


	text_sizer->Add(second_text_,
        0,            // make vertically stretchableM
        wxALL|        //   and make border all around
        wxRESERVE_SPACE_EVEN_IF_HIDDEN,        //   and make border all around
        10 );         // set border width to 10)

	top_sizer->Add(text_sizer, 1, wxALL | wxEXPAND);

	hide_left = new wxToggleButton(this, HIDE_LEFT, "Hide left");
    hide_left->SetValue(false);
	Bind(wxEVT_TOGGLEBUTTON, &LearnWindow::on_hide_left_button_clicked, this, HIDE_LEFT);
	auto cancelButton = new wxButton(this, wxID_CANCEL, "Cancel");
	cancelButton->Bind(wxEVT_BUTTON, &LearnWindow::on_cancel_button_clicked, this);
	control_sizer->AddSpacer(10);
	control_sizer->Add(hide_left, 0, wxALL, 10);
    control_sizer->AddSpacer(5);

	control_sizer->Add(
		cancelButton,
		0,
		wxALL,
		10);

	control_sizer->Add(result_text_, 0, wxALL, 10);

	top_sizer->Add(control_sizer, 0, wxALL | wxEXPAND);
	SetSizerAndFit(top_sizer);

};

LearnWindow::~LearnWindow()
= default;


void LearnWindow::on_hide_left_button_clicked(wxCommandEvent& event)
{
    if (hide_left->GetValue() == true) first_text_->Show(false);
    if (hide_left->GetValue() == false) first_text_->Show(true);

    /*
	wxString str;
    wxFileDialog open_file_dialog(this, _("Open text file"), "", "", "text files (*.txt)|*.txt",
                                  wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (open_file_dialog.ShowModal() == wxID_CANCEL)
        return;
    first_text_->LoadFile(open_file_dialog.GetPath(), 0);
    //secondText->SetEditable(true);
    second_text_->Show(true);
	second_text_->SetFocus();
	*/


}

void LearnWindow::on_cancel_button_clicked(wxCommandEvent& event)
{
	this->Destroy();

}

void LearnWindow::on_text_changed(wxCommandEvent& event)
{
        auto pos2 = second_text_->GetLastPosition();
		result_text_->SetLabelText(wxString::Format("%ld\n", pos2));

		auto txt01 = first_text_->GetValue();
		auto txt02 = second_text_->GetValue();

		auto lengthOftxt01 = first_text_->GetValue().length();
		auto lengthOftxt02 = second_text_->GetValue().length();


		if (pos2 == 0) second_text_->SetStyle(0, 100, orig_attr_);
		if (pos2 != 0 && (txt01[pos2-1] != txt02[pos2-1]))
		{
            ::wxBell();
			wxTextAttr attr;
			attr.SetTextColour(*wxRED);
			second_text_->SetStyle(pos2-1, pos2, attr);
		}
		if (pos2 != 0 && (txt01[pos2 - 1] == txt02[pos2 - 1]))
		{
			second_text_->SetStyle(pos2, pos2+1, orig_attr_);
            if(lengthOftxt01 == lengthOftxt02) {
                wxMessageBox("Congratulation!");
                Destroy();
            }
		}

}

