#include "userSavedDataFunctionality.hpp"
#include "../handler.hpp"

void menuSavedData::setNextHandler(handler *request){
    nextHandler = request;
}

void menuSavedData::handleRequest(char c){
    char input = c;
    std::string response = "";
    if(input == '2'){
        while(response!="0")
        {
            std::cout << std::endl;
            std::cout << "---------------------------------------------------------------" << std::endl;
            std::cout << "Saved Data: " << std::endl;
            std::cout << "Type 0 to exit." << std::endl;
            std::cout << "---------------------------------------------------------------" << std::endl;
            std::cin >> response;
        }
    }
    else if (input != NULL){
        nextHandler->handleRequest(input);
    }
}