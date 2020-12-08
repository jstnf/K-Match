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
        void setNextHandler(handler *request);
        void handleRequest(char c);
};
#endif