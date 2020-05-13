#include "EditText.h"

EditText::EditText(wxWindow* parent, const wxString& address)
	:wxPanel(parent, wxID_ANY)
{
	m_editor = new wxTextCtrl(this, IdEditor, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
	m_editor->LoadFile(address, wxTEXT_TYPE_ANY);
	auto save_button = new wxButton(this, IdSaveButton, "save");
	auto cancel_button = new wxButton(this, IdCancelButton, "cancel");
	save_button->Bind(wxEVT_BUTTON, &EditText::on_save_button_clicked, this);
	cancel_button->Bind(wxEVT_BUTTON, &EditText::on_cancel_button_clicked, this);
	auto base_sizer = new wxBoxSizer(wxVERTICAL);
	auto button_sizer = new wxBoxSizer(wxHORIZONTAL);
	button_sizer->Add(save_button, 0, wxALL);
	button_sizer->Add(cancel_button, 0, wxALL);
	base_sizer->Add(m_editor, 1, wxEXPAND | wxALL, 10);
	base_sizer->Add(button_sizer, 0, wxEXPAND | wxALL, 1);
	SetSizer(base_sizer);
}

void EditText::on_save_button_clicked(wxCommandEvent& event)
{
	if (m_editor->SaveFile(m_address))
	{
		wxWindow* prnt = GetParent();
		wxCommandEvent* event = new wxCommandEvent(wxEVT_BUTTON, EndEdit);
		wxQueueEvent(prnt, event);
	}
}

void EditText::on_cancel_button_clicked(wxCommandEvent& event)
{
	wxWindow* prnt = GetParent();
	wxCommandEvent* evt = new wxCommandEvent(wxEVT_BUTTON, EndEdit);
	wxQueueEvent(prnt, evt);
}