#pragma once

#include <iostream>
#include <string>

class View {
public:
    void displayData(const std::string& data) const {
        std::cout << "Response: " << data << std::endl;
    }

    void displaySuccess(const std::string& operation) const {
        std::cout << operation << " operation successful." << std::endl;
    }

    void displayError(const std::string& operation) const {
        std::cout << "Error occurred during " << operation << " operation." << std::endl;
    }
};