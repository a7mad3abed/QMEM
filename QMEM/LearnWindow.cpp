#include "LearnWindow.h"
#include "wx/tglbtn.h"
#include "wx/richtext/richtextctrl.h"
#include <iostream>

enum
{
    ALIGN_LEFT_BUTTON,
    ALIGN_RIGHT_BUTTON,
	HIDE_LEFT
};


LearnWindow::LearnWindow(wxWindow *parent, const wxString &title, const wxString &address)
	:wxFrame(
        parent,
        wxID_ANY,
        title,
        wxDefaultPosition,
        wxDefaultSize,
        wxDEFAULT_FRAME_STYLE|wxWANTS_CHARS
	)
{
    auto* top_sizer = new wxBoxSizer(wxVERTICAL);
    auto* text_sizer = new wxBoxSizer(wxHORIZONTAL);
	auto* control_sizer = new wxBoxSizer(wxHORIZONTAL);

	first_text_ = new wxTextCtrl(
        this,
        -1,
        "click open to load a learn file",
        wxDefaultPosition,
        wxSize(350, 300),
        wxTE_MULTILINE|wxTE_RICH2|wxTE_READONLY);
    first_text_->LoadFile(address, wxTEXT_TYPE_ANY);

	//firstText->LoadFile("text01.txt", wxTEXT_TYPE_ANY);
	second_text_ = new wxRichTextCtrl(
        this,
        -1,
        "",
        wxDefaultPosition,
        wxSize(350, 300),
        wxTE_MULTILINE | wxTE_RICH2);

    second_text_->Bind(wxEVT_TEXT, &LearnWindow::on_text_changed, this);
	//second_text_->GetStyle(0, orig_attr_);
	//secondText->SetEditable(false);
	//second_text_->Show(false);
    second_text_->SetFocus();


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

	hide_left = new wxToggleButton(this, HIDE_LEFT, "hide");
    hide_left->SetValue(false);
	Bind(wxEVT_TOGGLEBUTTON, &LearnWindow::on_hide_left_button_clicked, this, HIDE_LEFT);
    
	auto cancelButton = new wxButton(this, wxID_CANCEL, "Cancel");
    auto align_left_button = new wxButton(this, ALIGN_LEFT_BUTTON, "align left");
    auto align_right_button = new wxButton(this, ALIGN_RIGHT_BUTTON, "align right");
    
    align_right_button->Bind(wxEVT_BUTTON, &LearnWindow::on_align_right_button_clicked, this, ALIGN_RIGHT_BUTTON);
    align_left_button->Bind(wxEVT_BUTTON, &LearnWindow::on_align_left_button_clicked, this, ALIGN_LEFT_BUTTON);
	cancelButton->Bind(wxEVT_BUTTON, &LearnWindow::on_cancel_button_clicked, this);
    
	control_sizer->AddSpacer(10);
	control_sizer->Add(hide_left, 0, wxALL, 10);
    control_sizer->AddSpacer(5);

	control_sizer->Add(
		cancelButton,
		0,
		wxALL,
		10);

	control_sizer->Add(align_left_button, 0, wxALL, 10);
	control_sizer->Add(align_right_button, 0, wxALL, 10);

	top_sizer->Add(control_sizer, 0, wxALL | wxEXPAND);
	SetSizerAndFit(top_sizer);

};

LearnWindow::~LearnWindow()
= default;


void LearnWindow::on_hide_left_button_clicked(wxCommandEvent& event)
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


        /*
        if(lengthOftxt02 > lengthOftxt01) second_text_->SetStyle(pos2-1, pos2, wxTextAttr(*wxRED));
        
        if(lengthOftxt02 > 0 && (lengthOftxt01 >= lengthOftxt02))
        {
                    for (int i = 0 ; i < lengthOftxt02 ; i++)
                    {
                        if (txt01[i] != txt02[i]) {
                            second_text_->SetStyle(pos2-1, pos2, wxTextAttr(*wxRED));
                            //wxMessageBox(txt02[i]);
                            ::wxBell();
                        }
                        else {
                            second_text_->SetStyle(pos2-1, pos2, wxTextAttr(*wxBLACK));
                        }
                    }
        }


		if (lengthOftxt02 == 0) second_text_->SetStyle(0, 0, wxTextAttr(*wxBLACK));
		//if (lengthOftxt02 > lengthOftxt01) second_text_->SetStyle(lengthOftxt02-1, lengthOftxt02, wxTextAttr(*wxRED));
		/*if (lengthOftxt02 != 0 && lengthOftxt01 >= lengthOftxt02)
		{
            if(txt01[lengthOftxt02-1] != txt02[lengthOftxt02-1])
            {
                ::wxBell();
                wxTextAttr attr;
                second_text_->GetStyle(0, attr);
                
                attr.SetTextColour(*wxRED);
                second_text_->SetStyle(lengthOftxt02-1, lengthOftxt02, wxTextAttr(*wxRED));
            }
		}*/
        

		if ((lengthOftxt02 > 0) && (lengthOftxt01 >= lengthOftxt02))
		{
            if(txt01[lengthOftxt02 - 1] == txt02[lengthOftxt02 - 1])
            {
                //second_text_->SetStyle(lengthOftxt02, lengthOftxt02, wxTextAttr(*wxBLACK) );
                if(lengthOftxt01 == lengthOftxt02) {
                    bool typo = false;
                    for (int i = 0 ; i < lengthOftxt02 ; i++)
                    {
                        if (txt01[i] != txt02[i]) {
                            typo = true;
                            //second_text_->SetStyle(i, i, wxTextAttr(*wxRED));
                        }
                    }
                   if(!typo) 
                   {
                       //second_text_->SetStyle(0, lengthOftxt02, wxTextAttr(*wxBLACK));
                        wxMessageBox("Congratulation!");
                        Destroy();
                   }
                }
            }
		}
                         //   wxMessageBox(wxString::Format("%ld", pos2));

}

void LearnWindow::on_align_left_button_clicked(wxCommandEvent& event)
{
    
    second_text_->SetWindowStyleFlag(wxTE_MULTILINE | wxTE_RICH2| wxTE_LEFT);
}

void LearnWindow::on_align_right_button_clicked(wxCommandEvent& event)
{
    second_text_->SetWindowStyleFlag(wxTE_MULTILINE | wxTE_RICH2| wxTE_RIGHT);
}

void LearnWindow::on_bs_button_clicked(wxKeyEvent& event)
{
    if (event.GetKeyCode() == WXK_BACK)
    {
        Unbind(wxEVT_CHAR_HOOK, &LearnWindow::on_bs_button_clicked, this);
        second_text_->SetEditable(true);
        
        second_text_->Remove(second_text_->GetLastPosition() - 1,second_text_->GetLastPosition());
    }

}
