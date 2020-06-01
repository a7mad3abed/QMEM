#include "Results_Dlg.h"
#include <sstream>

Results_Dlg::Results_Dlg(wxWindow* parent, const wxString& title)
	:wxWindow(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
	wxFont f;
	f.SetFamily(wxFONTFAMILY_SCRIPT);
	f.SetSymbolicSize(wxFONTSIZE_LARGE);

	SetBackgroundColour(RGB(55, 168, 213));

	results = DB_Manager::instance().retrieve_results();

	std::ostringstream oss;
	result_show = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(400, 300), wxTE_MULTILINE | wxTE_READONLY);

	for (auto i = 0; i < results.size(); i++)
	{
		wxString m_id = results[i].id;
		wxString m_name = results[i].name;
		wxString m_address = results[i].address;
		wxString m_date = results[i].date;
		oss << m_id << "\t" << m_name << "\t" << m_address << m_date << std::endl;
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

	results = DB_Manager::instance().retrieve_results();

	for (auto i = 0; i < results.size(); i++)
	{
		wxString m_id = results[i].id;
		wxString m_name = results[i].name;
		wxString m_address = results[i].address;
		wxString m_date = results[i].date;
		oss << m_id << "   " << m_name << "   " << m_address << "    " << m_date << std::endl;
	}
	result_show->Clear();
	result_show->WriteText(oss.str());
}