#pragma once

#include <string>
#include "DatabaseAdapter.hpp"

class Model {
public:
    Model(DatabaseAdapter& dbAdapter) : databaseAdapter(dbAdapter) {}

    std::string getData() const {
       
         std::string getQuery = "Select * from mytable";
        
        return databaseAdapter.executeQuery(getQuery);
    }

    std::string  setData(const std::string& newData) {
         std::string insertQuery = "INSERT INTO mytable (data) VALUES ('" + newData  +"')";
        
        return databaseAdapter.executeQuery(insertQuery);
    }
       


    std::string  updateData(const std::string& newData) {
        std::string updateQuery = "UPDATE mytable SET column1 = '" + newData + "' WHERE id = 1";
        
        return databaseAdapter.executeQuery(updateQuery);
    }

    std::string  deleteData() {
        std::string deleteQuery = "DELETE FROM mytable WHERE id = 1";
        return databaseAdapter.executeQuery(deleteQuery);
    }

private:
    std::string data;
    DatabaseAdapter& databaseAdapter;
};