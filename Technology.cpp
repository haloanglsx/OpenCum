#include "Technology.h"
#include <iostream>

Technology::Technology(const std::string& name, const std::string& type)
    : name(name), type(type) {}

void Technology::display() const {
    std::cout << "_______________\nName: " << name << "\nType: " << type << std::endl;
}

std::string Technology::getName() const {
    return name;
}

FrontendTechnology::FrontendTechnology(const std::string& name, const std::string& framework)
    : Technology(name, "Frontend"), framework(framework) {}

void FrontendTechnology::display() const {
    Technology::display();
    std::cout << "Framework: " << framework << std::endl;
}

std::string FrontendTechnology::serialize() const {
    return "Frontend: " + getName() + ", Framework: " + framework;
}

BackendTechnology::BackendTechnology(const std::string& name, const std::string& language)
    : Technology(name, "Backend"), language(language) {}

void BackendTechnology::display() const {
    Technology::display();
    std::cout << "Language: " << language << std::endl;
}

std::string BackendTechnology::serialize() const {
    return "Backend: " + getName() + ", Language: " + language;
}
