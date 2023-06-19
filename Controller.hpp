#pragma once

#include <string>
#include "Model.hpp"

class Controller {
public:
    Controller(Model& model) : model(model) {}

    std::string handleGetRequest() const {
        return model.getData();
    }

    std::string handlePostRequest(const std::string& requestData) {
        return model.setData(requestData);
    }

    std::string handlePutRequest(const std::string& requestData) {
        return model.updateData(requestData);
    }

    std::string handleDeleteRequest() {
        return model.deleteData();
    }

private:
    Model& model;
};