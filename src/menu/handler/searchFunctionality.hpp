#ifndef __SEARCH_FUNCTIONALITY__
#define __SEARCH_FUNCTIONALITY__

#include "../handler.hpp"

#include <iostream>
#include <string>
#include <stdlib.h>

class menuSearch : public handler {
    private:
        handler *nextHandler;
    public:
        void setNextHandler(handler *request);
        void handleRequest(char c);
};
#endif