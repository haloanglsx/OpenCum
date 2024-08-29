#include <iostream>
#include "TechnologyManager.h"

int main() {
    TechnologyManager manager;

    int choice;
    do {
        std::cout << "1. Add Technology\n";
        std::cout << "2. Display All Technologies\n";
        std::cout << "3. Edit Technology\n";
        std::cout << "4. Delete Technology\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                std::string name, type;
                std::cout << "Enter technology name: ";
                std::getline(std::cin, name);
                std::cout << "Enter technology type (Frontend/Backend): ";
                std::getline(std::cin, type);
                manager.addTechnology(name, type);
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
                manager.editTechnology(index);
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
