#ifndef __MAINMENU_HPP__
#define __MAINMENU_HPP__
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class mainMenu {
    private: 
        int choice;
    public:
        void display();
        void getInput();
        char getRequest();
};

#endif