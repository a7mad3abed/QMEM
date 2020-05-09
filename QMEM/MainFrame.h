#pragma once
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif // !WX_PRECOMP

#include "wx/simplebook.h"

class MainFrame : public wxFrame
{
public:
    MainFrame();

private:
    wxMenuBar* make_m_bar();

    void on_new_text_selected(wxCommandEvent& event);

    void on_exit_selected(wxCommandEvent& event);

    void on_show_lessons(wxCommandEvent& event);

	void on_show_start(wxCommandEvent& event);

	void on_child_added_new_record(wxCommandEvent& event) ;

	void on_remove_selected_button_clicked(wxCommandEvent& event) ;

    void on_open_selected_button_clicked(wxCommandEvent& event) ;

private :
    wxSimplebook* m_book;
    wxListBox* list_box;
};

