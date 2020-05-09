#include "Results_Dlg.h"
#include <sstream>

Results_Dlg::Results_Dlg(wxWindow *parent, const wxString &title)
	:wxWindow(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
	
    DB_Manager::instance()->init_db();
    results = DB_Manager::instance()->retrieve_results();

	std::ostringstream oss;
	result_show = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(400,300), wxTE_MULTILINE|wxTE_READONLY);

	for (auto i = 0; i < results.size(); i++)
	{
		wxString m_name = results[i].name;
		wxString m_address = results[i].address;
		oss << m_name << "\t" << m_address << std::endl;
	}
	result_show->WriteText(oss.str());
	auto sizer = new wxBoxSizer(wxHORIZONTAL);
	sizer->Add(result_show, 1, wxEXPAND | wxALL, 10);
	SetSizer(sizer);

}

Results_Dlg::~Results_Dlg()
{
}

void Results_Dlg::update_results()
{
    std::ostringstream oss;

    DB_Manager::instance()->init_db();
    results = DB_Manager::instance()->retrieve_results();

    for (auto i = 0; i < results.size(); i++)
    {
        wxString m_name = results[i].name;
        wxString m_address = results[i].address;
        oss << m_name << "\t" << m_address << std::endl;
    }
    result_show->Clear();
    result_show->WriteText(oss.str());
}
