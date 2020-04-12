#include "textEntryDialog.h"

enum {
    SAVE_BUTTON = 33,
    ALIGN_RIGHT_BUTTON,
    ALIGN_LEFT_BUTTON
};

textEntryDialog::textEntryDialog(wxWindow *parent, wxString title, wxSize size)
    :wxDialog(parent, wxID_ANY, title, wxDefaultPosition, size)
{
    auto textPanel = new wxPanel(this, wxID_ANY, wxPoint(0,0), wxSize(400, 400), wxALIGN_TOP);
    textEntry = new wxTextCtrl(textPanel, wxID_ANY, "", wxDefaultPosition, wxSize(400, 400), wxTE_MULTILINE|wxTE_RICH2|wxTE_RIGHT);
    auto controlPanel = new wxPanel(this, wxID_ANY, wxPoint(0,400), wxSize(400, 100), wxALIGN_BOTTOM);
    auto saveButton = new wxButton(controlPanel, SAVE_BUTTON, "save", wxPoint(20, 20), wxSize(80,30), wxALIGN_RIGHT|wxBU_TOP);
    auto alignLeftButton = new wxButton(controlPanel, ALIGN_LEFT_BUTTON, "align left", wxPoint(140, 20), wxSize(80, 30), wxBU_TOP);
    auto alignRightButton = new wxButton(controlPanel, ALIGN_RIGHT_BUTTON, "align right", wxPoint(240, 20), wxSize(80, 30), wxBU_TOP);
    saveButton->Bind(wxEVT_BUTTON, &textEntryDialog::OnSaveButtonClicked, this, SAVE_BUTTON);
    alignLeftButton->Bind(wxEVT_BUTTON, &textEntryDialog::OnAlignLeftButtonClicked, this, ALIGN_LEFT_BUTTON);
    alignRightButton->Bind(wxEVT_BUTTON, &textEntryDialog::OnAlignRightButtonClicked, this, ALIGN_RIGHT_BUTTON);

}

void textEntryDialog::OnSaveButtonClicked(wxCommandEvent& event)
{
    
    if (textEntry->SaveFile("text01.txt", wxTEXT_TYPE_ANY)) wxMessageBox("saved successfully!");
}

void textEntryDialog::OnAlignLeftButtonClicked(wxCommandEvent& event)
{
    textEntry->SetWindowStyleFlag(wxTE_MULTILINE | wxTE_RICH2 | wxTE_LEFT);
    textEntry->SetFocus();
}

void textEntryDialog::OnAlignRightButtonClicked(wxCommandEvent& event)
{
    textEntry->SetWindowStyleFlag(wxTE_MULTILINE | wxTE_RICH2 | wxTE_RIGHT);
    textEntry->SetFocus();
}
