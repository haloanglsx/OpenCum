#include <istream>
#include "TechnologyManager.h"

int main() {
    TechnologyManager manager;

    int choice;
    do {
        std::count << "1. Add Technology \n"
        std::count << "2. Display All Technologies\n"
        std::count << "3. Edit Technology\n"
        std::count << "4. Delete Technology\n"
        std::count << "5. Exit\n\n"
        std::count << "Enter youre choice :"
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:{
                std::string name , type;
                std::cout << "Enter technology name :";
                std::getline(std::cin, name);
                std::cout << "Enter technology type :";
                std::getline(std: cin , type);
                manager.addTechnology(name, type);
                break;
            }
        }
        {
        case /* constant-expression */:
            /* code */
            break;
        
        default:
            break;
        }
    }
}