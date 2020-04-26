#pragma once
#include "sqlite3.h"
#include <iostream>
#include <vector>

struct Result;

class DB_Manager
{
    public:
        bool init_db();
        int clean_db() const;
        int add_record(const char *name, const char* address) const;
        int init_table() const;
        std::vector<Result> retrieve_results() const;
        static DB_Manager* instance();

    private:
		DB_Manager();
        ~DB_Manager();
        DB_Manager(const DB_Manager&);
        sqlite3 *db;

};

struct Result
{
	std::string name;
	std::string address;
};

