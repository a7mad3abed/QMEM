#pragma once
#include "wx/wx.h"
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

private :
    wxSimplebook* m_book;
};

