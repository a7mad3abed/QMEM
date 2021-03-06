#include "LearnWindow.h"
#include "wx/tglbtn.h"
#include "wx/richtext/richtextctrl.h"
#include <iostream>

LearnWindow::LearnWindow(wxWindow* parent, const wxString& title, const wxString& address)
	:wxWindow(
		parent,
		wxID_ANY,
		wxDefaultPosition,
		wxDefaultSize,
		wxDEFAULT_FRAME_STYLE | wxWANTS_CHARS
	)
{
	//CreateStatusBar(1);
	//SetStatusText("Welcome to Learn Module!");
	SetBackgroundColour(RGB(55, 168, 213));

	wxFont f;
	f.SetFamily(wxFONTFAMILY_SCRIPT);
	f.SetSymbolicSize(wxFONTSIZE_LARGE);

	auto* top_sizer = new wxBoxSizer(wxVERTICAL);
	auto* text_sizer = new wxBoxSizer(wxHORIZONTAL);
	auto* control_sizer = new wxBoxSizer(wxHORIZONTAL);

	first_text_ = new wxTextCtrl(
		this,
		-1,
		"click open to load a learn file",
		wxDefaultPosition,
		wxDefaultSize,
		wxTE_MULTILINE | wxTE_RICH2 | wxTE_READONLY);
	first_text_->LoadFile(address, wxTEXT_TYPE_ANY);
	first_text_->Hide();

	second_text_ = new wxRichTextCtrl(
		this,
		-1,
		"",
		wxDefaultPosition,
		wxDefaultSize,
		wxTE_MULTILINE | wxTEXT_ALIGNMENT_RIGHT);

	second_text_->Bind(wxEVT_TEXT, &LearnWindow::on_text_changed, this);
	second_text_->SetFocus();

	text_sizer->Add(first_text_,
		1,
		wxALL | wxEXPAND |
		wxRESERVE_SPACE_EVEN_IF_HIDDEN,
		10);

	text_sizer->Add(second_text_,
		1,
		wxALL | wxEXPAND |
		wxRESERVE_SPACE_EVEN_IF_HIDDEN,
		10);

	top_sizer->Add(text_sizer, 5, wxALL | wxEXPAND);

	hide_left = new wxToggleButton(this, HIDE_LEFT, "Show", wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
	hide_left->SetValue(true);
	Bind(wxEVT_TOGGLEBUTTON, &LearnWindow::on_hide_left_button_clicked, this, HIDE_LEFT);

	auto cancelButton = new wxButton(this, CancelLearn, "Cancel", wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
	auto align_left_button = new wxButton(this, Learn_ALIGN_LEFT_BUTTON, "Align left", wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
	auto align_right_button = new wxButton(this, Learn_ALIGN_RIGHT_BUTTON, "Align right", wxDefaultPosition, wxDefaultSize, wxNO_BORDER);

	align_right_button->Bind(wxEVT_BUTTON, &LearnWindow::on_align_right_button_clicked, this, Learn_ALIGN_RIGHT_BUTTON);
	align_left_button->Bind(wxEVT_BUTTON, &LearnWindow::on_align_left_button_clicked, this, Learn_ALIGN_LEFT_BUTTON);
	cancelButton->Bind(wxEVT_BUTTON, &LearnWindow::on_cancel_button_clicked, this);

	cancelButton->SetFont(f);
	align_left_button->SetFont(f);
	align_right_button->SetFont(f);
	hide_left->SetFont(f);

	cancelButton->SetBackgroundColour(RGB(55, 168, 213));
	align_left_button->SetBackgroundColour(RGB(55, 168, 213));
	align_right_button->SetBackgroundColour(RGB(55, 168, 213));
	hide_left->SetBackgroundColour(RGB(55, 168, 213));

	cancelButton->SetForegroundColour(*wxWHITE);
	align_left_button->SetForegroundColour(*wxWHITE);
	align_right_button->SetForegroundColour(*wxWHITE);
	hide_left->SetForegroundColour(*wxWHITE);

	control_sizer->AddStretchSpacer(1);
	control_sizer->Add(hide_left, 0, wxALL, 10);
	control_sizer->Add(
		cancelButton,
		0,
		wxALL,
		10);

	control_sizer->Add(align_left_button, 0, wxALL, 10);
	control_sizer->Add(align_right_button, 0, wxALL, 10);
	control_sizer->AddStretchSpacer(1);

	top_sizer->Add(control_sizer, 1, wxALL | wxEXPAND);
	SetSizer(top_sizer);
};

LearnWindow::~LearnWindow()
= default;

void LearnWindow::on_hide_left_button_clicked(wxCommandEvent & event)
{
	if (hide_left->GetValue() == true)
	{
		first_text_->Show(false);
		hide_left->SetLabel("show");
	}
	if (hide_left->GetValue() == false)
	{
		first_text_->Show(true);
		hide_left->SetLabel("hide");
	}
}

void LearnWindow::on_cancel_button_clicked(wxCommandEvent & event)
{
	event.Skip();
	//this->Destroy();
}

void LearnWindow::on_text_changed(wxCommandEvent & event)
{
	auto pos2 = second_text_->GetLastPosition();

	auto txt01 = first_text_->GetValue();
	auto txt02 = second_text_->GetValue();

	auto lengthOftxt01 = first_text_->GetValue().length();
	auto lengthOftxt02 = second_text_->GetValue().length();

	if (lengthOftxt02 > 0 && (lengthOftxt01 >= lengthOftxt02))
	{
		if (txt01[lengthOftxt02 - 1] != txt02[lengthOftxt02 - 1])
		{
			second_text_->SetEditable(false);
			Bind(wxEVT_CHAR_HOOK, &LearnWindow::on_bs_button_clicked, this);
		}
	}

	if (lengthOftxt02 == 0) second_text_->SetStyle(0, 0, wxTextAttr(*wxBLACK));

	if ((lengthOftxt02 > 0) && (lengthOftxt01 >= lengthOftxt02))
	{
		if (txt01[lengthOftxt02 - 1] == txt02[lengthOftxt02 - 1])
		{
			//SetStatusText("press backspace if you make an error to activate the keyboard");
			if (lengthOftxt01 == lengthOftxt02) {
				bool typo = false;
				for (int i = 0; i < lengthOftxt02; i++)
				{
					if (txt01[i] != txt02[i]) {
						typo = true;
					}
				}
				if (!typo)
				{
					wxMessageBox("Congratulation!");
					//Destroy();
					wxWindow* prnt = GetParent();
					wxCommandEvent* event = new wxCommandEvent(wxEVT_BUTTON, CancelLearn);
					wxQueueEvent(prnt, event);
				}
			}
		}
	}
}

void LearnWindow::on_align_left_button_clicked(wxCommandEvent & event)
{
	second_text_->ApplyAlignmentToSelection(wxTEXT_ALIGNMENT_LEFT);
	second_text_->SetFocus();
}

void LearnWindow::on_align_right_button_clicked(wxCommandEvent & event)
{
	second_text_->ApplyAlignmentToSelection(wxTEXT_ALIGNMENT_RIGHT);
	second_text_->SetFocus();
}

void LearnWindow::on_bs_button_clicked(wxKeyEvent & event)
{
	if (event.GetKeyCode() == WXK_BACK) {
		Unbind(wxEVT_CHAR_HOOK, &LearnWindow::on_bs_button_clicked, this);
		second_text_->SetEditable(true);

		second_text_->Remove(second_text_->GetLastPosition() - 1, second_text_->GetLastPosition());
	}
	else
	{
		//SetStatusText("you must erase wrong letter first");
	}
}