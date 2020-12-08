#include "searchFunctionality.hpp"
#include "../handler.hpp"

void menuSearch::setNextHandler(handler *request){
    nextHandler = request;
}

void menuSearch::handleRequest(char c){
    char input = c;
    std::string response = "";         
    if(input == '1'){
        while(response != "0")
        {
            std::cout << std::endl;
            std::cout << "---------------------------------------------------------------" << std::endl;
            std::cout << "   Please enter in the song or artist you are searching for " << std::endl;
            std::cout << "   or enter 0 to return to the main menu." << std::endl;
            std::cout << "---------------------------------------------------------------" << std::endl;

            std::cin >> response;


        }
    }
    else if (input == '0'){
        return;
    }
    else if (input != NULL){
        nextHandler->handleRequest(input);
    }
}