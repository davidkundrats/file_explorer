#include <iostream> 
#include <filesystem>
#include "navigation.h"
void switch_logic();

void switch_logic(){ 
    int choice;
    do {
        std::cout << "Enter your choice: " << '\n';
        std::cout << "1. Change current path" << '\n';
        std::cout << "2. Change current path upward" << '\n';
        std::cout << "3. Display current directory contents" << '\n';
        std::cout << "4. Exit" << std::endl;
        std::cin >> choice;
        switch(choice){
            case 1:
                changePWD();
                break;
            case 2:
                changePWD_upward();
                break;
            case 3:
                display_directory_contents();
                break;
            case 4:
                std::cout << "Exiting..." << '\n';
                break;
            default:
                std::cout << "Invalid choice." << '\n';
                break;
        }
    }
    while(choice != 4);

}
