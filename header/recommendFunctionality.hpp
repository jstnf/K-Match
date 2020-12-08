#ifndef __RECOMMEND_FUNCTIONALITY__
#define __RECOMMEND_FUNCTIONALITY__

#include "mainMenu.hpp"
#include "handler.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class menuRecommend : public handler {
    private:
        handler *nextHandler;
    public:
        void setNextHandler(handler *request);
        void handleRequest(char c);
};
#endif