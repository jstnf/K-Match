#include "../header/mainMenu.hpp"
#include "../header/handler.hpp"
#include "../header/recommendFunctionality.hpp"

using namespace std;

void menuRecommend::setNextHandler(handler *request){
            nextHandler = request;
}

void menuRecommend::handleRequest(char c){
    char input = c;
    std::string response = "";
        if(input == '3'){
            while(response != "0")
            {
                cout << endl;
                cout << "---------------------------------------------------------------" << endl;
                cout << "Recommended items:" << endl;
                cout << "Type 0 to exit." << endl;
                cout << "---------------------------------------------------------------" << endl;
                cin >> response;
            }
        }
        else if (input != NULL){
            nextHandler->handleRequest(input);
        }
}