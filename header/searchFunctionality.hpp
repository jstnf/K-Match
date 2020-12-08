#ifndef __SEARCH_FUNCTIONALITY__
#define __SEARCH_FUNCTIONALITY__

#include "mainMenu.hpp"
#include "handler.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class menuSearch : public handler {
    private:
        handler *nextHandler;
    public:
        void setNextHandler(handler *request){
            nextHandler = request;
        }
        void handleRequest(char c){
            char input = c;
            if(input == '1'){
                cout << "---------------------------------------------------------------" << endl;
                cout << "Please enter in the song or artist you are searching for: " << endl;
                cout << "---------------------------------------------------------------" << endl;
            }
            else if (input != NULL){
                nextHandler->handleRequest(input);
            }
    }
};
#endif