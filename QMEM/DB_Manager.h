#pragma once
#include "sqlite3.h"
#include <iostream>
#include <vector>

struct Result;

class DB_Manager
{
    public:
		DB_Manager();
        ~DB_Manager();
        bool init_db();
        int clean_db() const;
        int add_record(const char *name, const char* address) const;
        int init_table() const;
        std::vector<Result> retrieve_results() const;

    private:
        sqlite3 *db;

};

struct Result
{
	std::string name;
	std::string address;
};

