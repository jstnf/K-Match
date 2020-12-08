#ifndef __HANDLER_HPP_
#define __HANDLER_HPP_

#include <iostream>
#include <string>
#include <stdlib.h>

class handler {
    private:
        handler *nextRequest;
    public: 
        handler(){
            nextRequest = NULL;
        }
        ~handler(){ };
        virtual void setNextHandler(handler *nextHandler) = 0;
        virtual void handleRequest(char c) = 0;
};


#endif