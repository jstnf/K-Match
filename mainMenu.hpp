#ifndef __MAINMENU_HPP__
#define __MAINMENU_HPP__
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class mainMenu {
    private: 
        char choice;
    public:
        char input;
        void display();
        void getInput();
        char getRequest();
};

#endif