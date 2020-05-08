#include "Results_Dlg.h"
#include <sstream>

Results_Dlg::Results_Dlg(wxWindow *parent, const wxString &title)
	:wxWindow(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
	
    DB_Manager::instance()->init_db();
    results = DB_Manager::instance()->retrieve_results();

	std::ostringstream oss;
	auto result_show = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY);

	for (auto i = 0; i < results.size(); i++)
	{
		wxString m_name = results[i].name;
		wxString m_address = results[i].address;
		oss << m_name << "\t" << m_address << std::endl;

	}
	result_show->WriteText(oss.str());

}

Results_Dlg::~Results_Dlg()
{
}
