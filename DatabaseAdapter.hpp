#pragma once

#include <C:\Program Files\PostgreSQL\15\include\libpq-fe.h>
#include<iostream>

/// @brief 
class DatabaseAdapter {
public:
    DatabaseAdapter() {
        // Bazaga bog'lanishni boshlash
        connection = PQconnectdb("host=localhost user=postgres password=1111 dbname=postgres port=5432");
        if (PQstatus(connection) != CONNECTION_OK) {
            std::cerr << "Bazaga bog'lanishda xato: " << PQerrorMessage(connection) << std::endl;
            PQfinish(connection);
            exit(1);
        }
    }

    ~DatabaseAdapter() {
        // Bazadan chiqish
        PQfinish(connection);
    }

    std::string executeQuery(const std::string& query) {
        std::string result;

        // So'rovni bazaga jo'natish
        PGresult* res = PQexec(connection, query.c_str());
        if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            std::cerr << "So'rovni bajarishda xato: " << PQresultErrorMessage(res) << std::endl;
            PQclear(res);
            return result;
        }

        // Natijani olish
        int numRows = PQntuples(res);
        int numCols = PQnfields(res);
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                result += PQgetvalue(res, i, j);
                if (j != numCols - 1) {
                    result += ", ";
                }
            }
            result += "\n";
        }

        // Resurslarni tozalash
        PQclear(res);

        return result;
    }

private:
    PGconn* connection;
};