#include "Technology.h"
#include <iostream>

Technology::Technology(const std::string& name,const std::string& type)
    : name(name) , type(type) {}
void Technology::dispay() const {
    std::cout << "Name: " << name << ", Type: " << type << std::endl;
}

FrontentTechnology::FrontentTechnology(const std::string& name, const std::string& framework)
    : Technology(name , "Frontend"), framework(framework) {}
void FrontendTechnology::diplay() const {
    Technology::dispay();
    std::cout << "Framework: " << framework << std::endl;
}

std::string FrontendTechnology::BackendTechnology(const std::string& language)
    : Technology(name , "Backend"),language(language) {}

void BackendTechnology::display() const {
    Technology::display()
    std::cout << "Language: " << language << std::endl;
}
std::string BackendTechnology::serialize() const() {
    return "Backend|" + name + "|" + language;
}