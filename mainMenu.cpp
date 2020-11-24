#ifndef __MAINMENU_CPP__
#define __MAINMENU_CPP__

#include "mainMenu.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void mainMenu::display(){
    cout << "--------------------------------------------" << endl;
    cout << "Welcome to K-Match!" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Type 1 to search for songs or artists" << endl;
    cout << "Type 2 to view your saved songs and artists" << endl;
    cout << "Type 3 for song recommendations" << endl;
    cout << "Type 0 to end program" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Enter input: " << endl;
    cout << "--------------------------------------------" << endl;
}

void mainMenu::getInput(){
    char input;
    cin >> input;
    this->choice = input;
}

#endif