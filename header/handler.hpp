#ifndef __HANDLER_HPP_
#define __HANDLER_HPP_

#include "mainMenu.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class handler : public mainMenu {
    private:
        handler *nextRequest;
    public: 
        handler(){nextRequest = NULL;}
        virtual void handleRequest(char c) = 0;
        void setNextHandler(handler *nextHandler){ nextRequest = nextHandler; }
};


#endif