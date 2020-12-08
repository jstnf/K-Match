#include "menu/handler.hpp"
#include "menu/handler/endProgramFunctionality.hpp"
#include "menu/handler/searchFunctionality.hpp"
#include "menu/handler/userSavedDataFunctionality.hpp"

#include <iostream>

int main() {
    char menuInput = ' ';
    menuSearch *search = new menuSearch();
    menuSavedData *savedData = new menuSavedData();
    menuEndProgram *endProgram;
    while (menuInput != '0'){
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << "Welcome to K-Match!" << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << "Type 1 to search for songs or artists" << std::endl;
        std::cout << "Type 2 to view your saved songs and artists" << std::endl;
        std::cout << "Type 0 to end program" << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << "Enter input: "; 
        std::cin >> menuInput;
        std::cout << std::endl;

        search->setNextHandler(savedData);
        savedData->setNextHandler(endProgram);
        
        search->handleRequest(menuInput);
    }

    return 0;
}