#include "DB_Manager.h"

DB_Manager::DB_Manager()
{
    init_db();
}

DB_Manager::~DB_Manager()
{
    sqlite3_close(db);
}


bool DB_Manager::init_db()
{
    if ((sqlite3_open("Qmem.db", &db)) != SQLITE_OK) {
        return false;
    }


    if (init_table() == SQLITE_DONE)
    {
        return true;
    } else return false;
}

int DB_Manager::init_table() const
{
    int rc = 0;
    sqlite3_stmt* stmt;
    const char* zSql = "CREATE TABLE if not exists Learn_Text (\
                        id INTEGER PRIMARY KEY,\
                        name TEXT UNIQUE NOT NULL,\
                        address TEXT,\
                        Timestamp DATETIME DEFAULT CURRENT_TIMESTAMP);";
    sqlite3_prepare_v2(db, zSql, -1, &stmt, 0);
    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    return rc;
}

int DB_Manager::add_record(const char *name, const char *address) const
{
    const char* zSql = "insert into Learn_Text (name, address) values (?, ?);";
    sqlite3_stmt* stmt;
    int rc = 0;

    sqlite3_prepare_v2(db, zSql, -1, &stmt, 0);
    sqlite3_bind_text(stmt, 1, name, -1, nullptr);
    sqlite3_bind_text(stmt, 2, address, -1, nullptr);
    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    return rc;
}

int DB_Manager::remove_record(const char* name)
{
    const char* zSql = "DELETE FROM Learn_Text WHERE name=?";
    sqlite3_stmt* stmt;
    int rc = 0;
	
    sqlite3_prepare_v2(db, zSql, -1, &stmt, 0);
    sqlite3_bind_text(stmt, 1, name, -1, nullptr);

    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    return rc;
}




int DB_Manager::clean_db() const
{
    sqlite3_stmt* stmt;
    int rc = 0;
    const char* zSql = "DROP TABLE IF EXISTS Learn_Text;";
    sqlite3_prepare_v2(db, zSql, -1, &stmt, 0);
    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    return rc;
}



std::vector<Result> DB_Manager::retrieve_results() const
{
    sqlite3_stmt* stmt;
    std::vector<Result> results;

    const char* zSql = "select * from Learn_Text;";


    sqlite3_prepare_v2(db, zSql, -1, &stmt, nullptr);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        Result newResult;
        for (auto i = 0; i < sqlite3_column_count(stmt); i++)
        {

            if (i == 0)
            {
                newResult.id = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));
            }
            if (i == 1)
            {
                newResult.name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));
            }
            if(i == 2) newResult.address = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));
            if (i == 3) newResult.date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));
        }
        results.push_back(newResult);

    }
    return results;

}

DB_Manager& DB_Manager::instance()
{
    static DB_Manager singleton;
    return singleton;
}

