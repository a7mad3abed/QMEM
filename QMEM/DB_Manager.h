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
        int remove_record(const char* name);
        std::vector<Result> retrieve_results() const;
        static DB_Manager& instance();

protected:
    explicit DB_Manager();

    private:
		std::vector<Result> results;
        ~DB_Manager();
        DB_Manager(const DB_Manager&);
        DB_Manager& operator=(const DB_Manager& dbM);
        sqlite3 *db;

};

struct Result
{
	std::string name;
	std::string address;
    std::string date;
    std::string id;
};

