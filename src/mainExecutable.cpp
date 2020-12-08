#include "../header/endProgramFunctionality.hpp"
#include "../header/handler.hpp"
#include "../header/recommendFunctionality.hpp"
#include "../header/searchFunctionality.hpp"
#include "../header/userSavedDataFunctionality.hpp"
#include <iostream>

using namespace std;

int main() {
    char menuInput = ' ';
    menuSearch *search;
    menuSavedData *savedData;
    menuRecommend *recommend;
    menuEndProgram *endProgram;
    while (menuInput != 0){
        cout << "--------------------------------------------" << endl;
        cout << "Welcome to K-Match!" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Type 1 to search for songs or artists" << endl;
        cout << "Type 2 to view your saved songs and artists" << endl;
        cout << "Type 3 for song recommendations" << endl;
        cout << "Type 0 to end program" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Enter input: "; 
        cin >> menuInput;
        cout << endl;

        search->setNextHandler(savedData);
        savedData->setNextHandler(recommend);
        recommend->setNextHandler(endProgram);
        
        search->handleRequest(menuInput);

    }


    return 0;
}
