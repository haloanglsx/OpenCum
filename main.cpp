#include <istream>
#include <TechnologyManager.h>

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
            case 2:
                manager.dispayALL();
                break;
            case 3: {
                int index;
                sdt::cout << "Enter index technology to edit :";
                std::cin >> index;
                std::cin.ignore();
                manager.editTechnology(index);
                break;
            }
            case 4: {
                int index;
                std::cout << "Enter index technology delete :";
                std::cin >> index;
                std::cin.ignore();
                manager.deleteTechnology(index);
                break;
            }
            case 5:
                std::cout << "Exiting...";
                break;
            default:
                std::cout << "Invalid choice. please try again..\n";
                break;
        }
    }while (choice !=5);
return 0

}