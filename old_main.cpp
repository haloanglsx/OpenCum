#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>

class Technology {
protected:
    std::string name;
    std::string type;
    std::string description;

public:
    Technology(const std::string& n, const std::string& t, const std::string& d)
        : name(n), type(t), description(d) {}

    virtual void display() const {
        std::cout << "Name: " << name << "\nType: " << type << "\nDescription: " << description << std::endl;
    }

    virtual std::string serialize() const {
        std::ostringstream oss;
        oss << type << "|" << name << "|" << description;
        return oss.str();
    }

    virtual ~Technology() = default;
};

class FrontendTechnology : public Technology {
private:
    std::string version;
    std::string browserSupport;

public:
    FrontendTechnology(const std::string& n, const std::string& d, const std::string& v, const std::string& b)
        : Technology(n, "Front-end", d), version(v), browserSupport(b) {}

    void display() const override {
        Technology::display();
        std::cout << "Version: " << version << "\nBrowser Support: " << browserSupport << std::endl;
    }

    std::string serialize() const override {
        return "Frontend|" + Technology::serialize() + "|" + version + "|" + browserSupport;
    }
};

class BackendTechnology : public Technology {
private:
    std::string serverLanguage;
    std::string database;

public:
    BackendTechnology(const std::string& n, const std::string& d, const std::string& s, const std::string& db)
        : Technology(n, "Back-end", d), serverLanguage(s), database(db) {}

    void display() const override {
        Technology::display();
        std::cout << "Server Language: " << serverLanguage << "\nDatabase: " << database << std::endl;
    }

    std::string serialize() const override {
        return "Backend|" + Technology::serialize() + "|" + serverLanguage + "|" + database;
    }
};

class TechnologyManager {
private:
    std::vector<std::unique_ptr<Technology>> technologies;
    const std::string filename = "technologies.txt";

    void saveToFile() const {
        std::ofstream file(filename);
        for (const auto& tech : technologies) {
            file << tech->serialize() << std::endl;
        }
    }

    void loadFromFile() {
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string type, name, description, version, browserSupport, serverLanguage, database;
            std::getline(iss, type, '|');
            std::getline(iss, name, '|');
            std::getline(iss, description, '|');

            if (type == "Frontend") {
                std::getline(iss, version, '|');
                std::getline(iss, browserSupport);
                technologies.push_back(std::make_unique<FrontendTechnology>(name, description, version, browserSupport));
            } else if (type == "Backend") {
                std::getline(iss, serverLanguage, '|');
                std::getline(iss, database);
                technologies.push_back(std::make_unique<BackendTechnology>(name, description, serverLanguage, database));
            }
        }
    }

public:
    TechnologyManager() {
        loadFromFile();
    }

    void addTechnology(std::unique_ptr<Technology> tech) {
        technologies.push_back(std::move(tech));
        saveToFile();
    }

    void displayAll() const {
        for (const auto& tech : technologies) {
            tech->display();
            std::cout << "-----------------------\n";
        }
    }

    void editTechnology(int index, std::unique_ptr<Technology> tech) {
        if (index >= 0 && index < technologies.size()) {
            technologies[index] = std::move(tech);
            saveToFile();
        } else {
            std::cout << "Invalid index.\n";
        }
    }

    void deleteTechnology(int index) {
        if (index >= 0 && index < technologies.size()) {
            technologies.erase(technologies.begin() + index);
            saveToFile();
        } else {
            std::cout << "Invalid index.\n";
        }
    }
};

void menu() {
    std::cout << "1. Add Technology\n2. Display All Technologies\n3. Edit Technology\n4. Delete Technology\n5. Exit\n";
}

int main() {
    TechnologyManager manager;
    int choice;

    do {
        menu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                std::string name, description, version, browserSupport, serverLanguage, database;
                std::string type;
                std::cout << "Enter technology type (Frontend/Backend): ";
                std::getline(std::cin, type);
                std::cout << "Enter name: ";
                std::getline(std::cin, name);
                std::cout << "Enter description: ";
                std::getline(std::cin, description);

                if (type == "Frontend") {
                    std::cout << "Enter version: ";
                    std::getline(std::cin, version);
                    std::cout << "Enter browser support: ";
                    std::getline(std::cin, browserSupport);
                    manager.addTechnology(std::make_unique<FrontendTechnology>(name, description, version, browserSupport));
                } else if (type == "Backend") {
                    std::cout << "Enter server language: ";
                    std::getline(std::cin, serverLanguage);
                    std::cout << "Enter database: ";
                    std::getline(std::cin, database);
                    manager.addTechnology(std::make_unique<BackendTechnology>(name, description, serverLanguage, database));
                } else {
                    std::cout << "Invalid type.\n";
                }
                break;
            }
            case 2:
                manager.displayAll();
                break;
            case 3: {
                int index;
                std::cout << "Enter index of technology to edit: ";
                std::cin >> index;
                std::cin.ignore();
                std::string name, description, version, browserSupport, serverLanguage, database;
                std::string type;
                std::cout << "Enter new technology type (Frontend/Backend): ";
                std::getline(std::cin, type);
                std::cout << "Enter new name: ";
                std::getline(std::cin, name);
                std::cout << "Enter new description: ";
                std::getline(std::cin, description);

                if (type == "Frontend") {
                    std::cout << "Enter new version: ";
                    std::getline(std::cin, version);
                    std::cout << "Enter new browser support: ";
                    std::getline(std::cin, browserSupport);
                    manager.editTechnology(index, std::make_unique<FrontendTechnology>(name, description, version, browserSupport));
                } else if (type == "Backend") {
                    std::cout << "Enter new server language: ";
                    std::getline(std::cin, serverLanguage);
                    std::cout << "Enter new database: ";
                    std::getline(std::cin, database);
                    manager.editTechnology(index, std::make_unique<BackendTechnology>(name, description, serverLanguage, database));
                } else {
                    std::cout << "Invalid type.\n";
                }
                                 break;
            }
            case 4: {
                int index;
                std::cout << "Enter index of technology to delete: ";
                std::cin >> index;
                std::cin.ignore();
                manager.deleteTechnology(index);
                break;
            }
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 5);

    return 0;
}

               
