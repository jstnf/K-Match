#include "KMatch.hpp"
#include "menu/handler.hpp"
#include "menu/handler/endProgramFunctionality.hpp"
#include "menu/handler/searchFunctionality.hpp"
#include "menu/handler/userSavedDataFunctionality.hpp"

#include <iostream>

int KMatch::initialize() {
    om = new ObjectManager();
    ObjectLoader* ol = new ObjectLoader(om);
    if (!ol->loadObjects()) {
        std::cout << "Unable to load Spotify objects! Please ensure the proper files are available and try again." << std::endl;
        return 1;
    }
    delete ol;

    se = new SearchEngine(om);
    return 0;
}

int KMatch::mainMenu() {
    char menuInput = ' ';
    menuSearch *search = new menuSearch();
    menuSavedData *savedData = new menuSavedData();
    menuEndProgram *endProgram = new menuEndProgram();
    while (menuInput != '0'){
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << "            Welcome to K-Match!" << std::endl;
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
