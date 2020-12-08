#ifndef __SAVED_DATA_FUNCTIONALITY__
#define __SAVED_DATA_FUNCTIONALITY__

#include "mainMenu.hpp"
#include "handler.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class menuSavedData : public handler {
    private:
        handler *nextHandler;
    public:
        void setNextHandler(handler *request){
            nextHandler = request;
        }
        void handleRequest(char c){
            char input = c;
            if(input == '2'){
                cout << endl;
                cout << "---------------------------------------------------------------" << endl;
                cout << "Saved Data: " << endl;
                cout << "---------------------------------------------------------------" << endl;
            }
            else if (input != NULL){
                nextHandler->handleRequest(input);
            }
    }
};
#endif