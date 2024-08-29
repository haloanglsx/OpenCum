#include "TechnologyManager.h"
#include "Technology.h"
#include <iostream>
#include <fstream>
#include <sstream>

TechnologyManager::~TechnologyManager() {
    for (Technology* tech : technologies) {
        delete tech;
    }
}

void TechnologyManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    for (const Technology* tech : technologies) {
        file << tech->serialize() << std::endl;
    }
}

void TechnologyManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type;
        std::getline(iss, type, '|');
        std::string name, detail;
        std::getline(iss, name, '|');
        std::getline(iss, detail);
        if (type == "Frontend") {
            technologies.push_back(new FrontendTechnology(name, detail));
        } else if (type == "Backend") {
            technologies.push_back(new BackendTechnology(name, detail));
        }
    }
}

void TechnologyManager::addTechnology(const std::string& name, const std::string& type) {
    if (type == "Frontend") {
        std::string framework;
        std::cout << "Enter framework: ";
        std::getline(std::cin, framework);
        technologies.push_back(new FrontendTechnology(name, framework));
    } else if (type == "Backend") {
        std::string language;
        std::cout << "Enter language: ";
        std::getline(std::cin, language);
        technologies.push_back(new BackendTechnology(name, language));
    } else {
        std::cout << "Invalid type. Technology not added." << std::endl;
    }
}

void TechnologyManager::displayAll() const {
    for (const Technology* tech : technologies) {
        tech->display();
        std::cout << std::endl;
    }
}

void TechnologyManager::editTechnology(int index) {
    if (index >= 0 && index < technologies.size()) {
        std::string name;
        std::cout << "Enter new name: ";
        std::getline(std::cin, name);
        std::string type = technologies[index]->serialize().substr(0, technologies[index]->serialize().find('|'));
        if (type == "Frontend") {
            std::string framework;
            std::cout << "Enter new framework: ";
            std::getline(std::cin, framework);
            delete technologies[index];
            technologies[index] = new FrontendTechnology(name, framework);
        } else if (type == "Backend") {
            std::string language;
            std::cout << "Enter new language: ";
            std::getline(std::cin, language);
            delete technologies[index];
            technologies[index] = new BackendTechnology(name, language);
        }
    }
}

void TechnologyManager::deleteTechnology(int index) {
    if (index >= 0 && index < technologies.size()) {
        delete technologies[index];
        technologies.erase(technologies.begin() + index);
    }
}
