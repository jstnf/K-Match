#ifndef __END_PROGRAM__
#define __END_PROGRAM__

#include "mainMenu.hpp"
#include "handler.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class menuEndProgram : public handler {
    private:
        handler *nextHandler;
    public:
        void setNextHandler(handler *request){
            nextHandler = request;
        }
        void handleRequest(char c){
            char input = c;
            if(input == '0'){
                cout << endl;
                cout << "---------------------------------------------------------------" << endl;
                cout << "                       Ending program" << endl;
                cout << "---------------------------------------------------------------" << endl;
            }
            else if (input != NULL){
                cout << "Please enter a valid option" << endl;

            }
    }
};
#endif