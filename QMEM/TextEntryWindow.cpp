#include "TextEntryWindow.h"
#include "wx/filename.h"
#include "DB_Manager.h"
#include <string>
#include <sstream>


#define CLOSE_TO_WINDOW 66

TextEntryDialog::TextEntryDialog(wxWindow* parent, const wxString& title, const wxSize& size)
	:wxWindow(
		parent,
		wxID_ANY,
		wxDefaultPosition,
		size)
{
	if (!DB_Manager::instance()->init_db()) wxMessageBox("error initializing the datebase");

	auto baseSizer = new wxBoxSizer(wxVERTICAL);
	textEntry = new wxTextCtrl(
		this,
		wxID_ANY,
		"",
		wxDefaultPosition,
		wxSize(400, 200),
		wxTE_MULTILINE | wxTE_RICH2 | wxTE_RIGHT);
	baseSizer->Add(
		textEntry,
		1,
		wxEXPAND | wxALL,
		10);
	auto controlSizer = new wxBoxSizer(wxHORIZONTAL);
	auto saveButton = new wxButton(
		this,
		SAVE_BUTTON,
		"save",
		wxDefaultPosition,
		wxDefaultSize,
		wxBU_TOP);
	auto cancelButton = new wxButton(
		this,
		New_Canel_Button,
		"cancel",
		wxDefaultPosition,
		wxDefaultSize,
		wxBU_TOP);
	auto alignLeftButton = new wxButton(
		this,
		ALIGN_LEFT_BUTTON,
		"align left",
		wxDefaultPosition,
		wxDefaultSize,
		wxBU_TOP);
	auto alignRightButton = new wxButton(
		this,
		ALIGN_RIGHT_BUTTON,
		"align right",
		wxDefaultPosition,
		wxDefaultSize,
		wxBU_TOP);
	saveButton->Bind(
		wxEVT_BUTTON,
		&TextEntryDialog::on_save_button_clicked,
		this,
		SAVE_BUTTON);
	cancelButton->Bind(
		wxEVT_BUTTON,
		&TextEntryDialog::on_cancel_button_clicked,
		this,
		New_Canel_Button);
	alignLeftButton->Bind(
		wxEVT_BUTTON,
		&TextEntryDialog::on_align_left_button_clicked,
		this,
		ALIGN_LEFT_BUTTON);
	alignRightButton->Bind(
		wxEVT_BUTTON,
		&TextEntryDialog::on_align_right_button_clicked,
		this,
		ALIGN_RIGHT_BUTTON);
	controlSizer->AddSpacer(5);
	controlSizer->Add(saveButton, 0, wxALL);
	controlSizer->AddSpacer(5);
	controlSizer->Add(cancelButton, 0, wxALL);
	controlSizer->AddSpacer(5);
	controlSizer->Add(alignLeftButton, 0, wxALL);
	controlSizer->AddSpacer(5);
	controlSizer->Add(alignRightButton, 0, wxALL);
	baseSizer->Add(controlSizer, 0, wxALL, 10);
	SetSizerAndFit(baseSizer);
}

TextEntryDialog::~TextEntryDialog()
{
}

void TextEntryDialog::on_save_button_clicked(wxCommandEvent& event)
{
	if (!wxFileName::Exists("saved mems"))
	{
		if (!wxFileName::Mkdir("saved mems", wxS_DIR_DEFAULT)) wxMessageBox("directory can not be made");
	}
	wxString fileName = "";
	wxTextEntryDialog dlg(
		this,
		"enter a name for the memo",
		wxGetTextFromUserPromptStr,
		"");
	dlg.SetTextValidator(wxFILTER_ALPHANUMERIC | wxFILTER_NONE | wxFILTER_EMPTY);
	if (dlg.ShowModal() == wxID_OK &&
		!(fileName = dlg.GetValue()).empty() &&
		textEntry->SaveFile(wxString::Format("./saved mems/%s.txt", fileName), wxTEXT_TYPE_ANY))
	{
		if (DB_Manager::instance()->add_record(fileName,
			wxString::Format("./saved mems/%s.txt", fileName)) == SQLITE_DONE) {
			wxMessageBox("saved successfully!");

			wxWindow* prnt = GetParent();
			wxCommandEvent* event = new wxCommandEvent(wxEVT_BUTTON, SaveSuccessful);
			wxQueueEvent(prnt, event);
		}
		else {
			wxMessageBox("name must be unique!");
		}
	}

	wxWindow* prnt = GetParent();
	wxEvent* evt = new wxCloseEvent(wxEVT_COMMAND_MENU_SELECTED, CLOSE_TO_WINDOW);
	//wxPostEvent(prnt, evt);
	wxQueueEvent(prnt, evt);
}

void TextEntryDialog::on_cancel_button_clicked(wxCommandEvent& event)
{
	wxWindow* prnt = GetParent();
	wxEvent* evt = new wxCommandEvent(wxEVT_BUTTON, New_Canel_Button);
	//wxPostEvent(prnt, evt);
	wxQueueEvent(prnt, evt);
}

void TextEntryDialog::on_align_left_button_clicked(wxCommandEvent& event)
{
	textEntry->SetWindowStyleFlag(wxTE_MULTILINE | wxTE_RICH2 | wxTE_LEFT);
	wxStaticCast(textEntry, wxWindow)->SetFocus();
}

void TextEntryDialog::on_align_right_button_clicked(wxCommandEvent& event)
{
	textEntry->SetWindowStyleFlag(wxTE_MULTILINE | wxTE_RICH2 | wxTE_RIGHT);
	wxStaticCast(textEntry, wxWindow)->SetFocus();
}