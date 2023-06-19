#pragma once

#include <functional>
#include <map>
#include <string>

class Router {
public:
    void addRoute(const std::string& route, std::function<void()> handler) {
        routes[route] = handler;
    }

    void routeRequest(const std::string& route) {
        if (routes.find(route) != routes.end()) {
            routes[route]();
        } else {
            std::cout << "Route not found." << std::endl;
        }
    }

private:
    std::map<std::string, std::function<void()>> routes;
};
