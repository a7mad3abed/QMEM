#include "textEntryDialog.h"
#include "wx/filename.h"

enum {
    SAVE_BUTTON = 33,
    ALIGN_RIGHT_BUTTON,
    ALIGN_LEFT_BUTTON
};

TextEntryDialog::TextEntryDialog(wxWindow *parent, wxString title, wxSize size)
    :wxDialog(
            parent,
            wxID_ANY,
            title,
            wxDefaultPosition,
            size)
{
    
    auto textPanel = new wxPanel(
            this,
            wxID_ANY,
            wxPoint(0,0),
            wxSize(400, 400),
            wxALIGN_TOP);
    textEntry = new wxTextCtrl(
            textPanel,
            wxID_ANY,
            "",
            wxDefaultPosition,
            wxSize(400, 400),
            wxTE_MULTILINE|wxTE_RICH2|wxTE_RIGHT);
    auto controlPanel = new wxPanel(
            this,
            wxID_ANY,
            wxPoint(0,400),
            wxSize(400, 100),
            wxALIGN_BOTTOM);
    auto controlSizer = new wxBoxSizer( wxHORIZONTAL);
    auto saveButton = new wxButton(
            controlPanel,
            SAVE_BUTTON,
            "save",
            wxDefaultPosition,
            wxDefaultSize,
            wxBU_TOP);
    auto cancelButton = new wxButton(
            controlPanel,
            wxID_CANCEL,
            "cancel",
            wxDefaultPosition,
            wxDefaultSize,
            wxBU_TOP);
    auto alignLeftButton = new wxButton(
            controlPanel,
            ALIGN_LEFT_BUTTON,
            "align left",
            wxDefaultPosition,
            wxDefaultSize,
            wxBU_TOP);
    auto alignRightButton = new wxButton(
            controlPanel,
            ALIGN_RIGHT_BUTTON,
            "align right",
            wxDefaultPosition,
            wxDefaultSize,
            wxBU_TOP);
    saveButton->Bind(
            wxEVT_BUTTON,
            &TextEntryDialog::OnSaveButtonClicked,
            this,
            SAVE_BUTTON);
    saveButton->Bind(
            wxEVT_BUTTON,
            &TextEntryDialog::OnCancelButtonClicked,
            this,
            wxID_CANCEL);
    alignLeftButton->Bind(
            wxEVT_BUTTON,
            &TextEntryDialog::OnAlignLeftButtonClicked,
            this,
            ALIGN_LEFT_BUTTON);
    alignRightButton->Bind(
            wxEVT_BUTTON,
            &TextEntryDialog::OnAlignRightButtonClicked,
            this,
            ALIGN_RIGHT_BUTTON);
    controlSizer->AddSpacer(5);
    controlSizer->Add(saveButton, wxALIGN_LEFT | wxEXPAND);
    controlSizer->AddSpacer(5);
    controlSizer->Add(cancelButton, wxALIGN_LEFT | wxEXPAND);
    controlSizer->AddSpacer(5);
    controlSizer->Add(alignLeftButton, wxALIGN_LEFT | wxEXPAND);
    controlSizer->AddSpacer(5);
    controlSizer->Add(alignRightButton, wxALIGN_LEFT | wxEXPAND);
    controlPanel->SetSizerAndFit(controlSizer);

}

void TextEntryDialog::OnSaveButtonClicked(wxCommandEvent& event)
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
    dlg.SetTextValidator(wxFILTER_ALPHANUMERIC|wxFILTER_SPACE|wxFILTER_EMPTY);
    if (dlg.ShowModal() == wxID_OK)
    {
        if((fileName = dlg.GetValue()) != "") {
            if (textEntry->SaveFile(wxString::Format("./saved mems/%s.txt", fileName), wxTEXT_TYPE_ANY)) {
                wxMessageBox("saved successfully!");
                Destroy();
            }
        }
    }
}

void TextEntryDialog::OnCancelButtonClicked(wxCommandEvent& event)
{
    Destroy();
}

void TextEntryDialog::OnAlignLeftButtonClicked(wxCommandEvent& event)
{
    textEntry->SetWindowStyleFlag(wxTE_MULTILINE | wxTE_RICH2 | wxTE_LEFT);
    textEntry->SetFocus();
}

void TextEntryDialog::OnAlignRightButtonClicked(wxCommandEvent& event)
{
    textEntry->SetWindowStyleFlag(wxTE_MULTILINE | wxTE_RICH2 | wxTE_RIGHT);
    textEntry->SetFocus();
}
