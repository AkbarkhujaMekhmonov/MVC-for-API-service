#include <iostream>
#include <string>
#include "Controller.hpp"
#include "Router.hpp"
#include "View.hpp"
#include "DatabaseAdapter.hpp"
#include "Model.hpp"

int main() {
    Router router;
    DatabaseAdapter database;
    Model model(database); 
    Controller controller(model);
    View view;

    // GET r 
    router.addRoute("/api/resource", [&]() {
        std::string data = controller.handleGetRequest();
        view.displayData(data);
    });

    // POST  r
    router.addRoute("/api/resource", [&]() {
        std::string requestData = "New data";
        std::string success = controller.handlePostRequest(requestData);
        if (success!="") {
            view.displaySuccess("POST");
        } else {
            view.displayError("POST");
        }
    });

    // PUT r
    router.addRoute("/api/resource", [&]() {
        std::string requestData = "Updated data";
        std::string success = controller.handlePutRequest(requestData);
        if (success!="") {
            view.displaySuccess("PUT");
        } else {
            view.displayError("PUT");
        }
    });

    // DELETE r 
    router.addRoute("/api/resource", [&]() {
        std::string success = controller.handleDeleteRequest();
        if (success!="") {
            view.displaySuccess("DELETE");
        } else {
            view.displayError("DELETE");
        }
    });

    // Route the request
    std::string requestMethod = "GET";
    router.routeRequest("/api/resource");

    return 0;
}