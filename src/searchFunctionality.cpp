#include "../header/mainMenu.hpp"
#include "../header/handler.hpp"
#include "../header/searchFunctionality.hpp"

using namespace std;

void menuSearch::setNextHandler(handler *request){
            nextHandler = request;
}

void menuSearch::handleRequest(char c){
    char input = c;
    std::string response = "";         
        if(input == '1'){
            while(response != "0")
            {
                cout << endl;
                cout << "---------------------------------------------------------------" << endl;
                cout << "   Please enter in the song or artist you are searching for " << endl;
                cout << "   or enter 0 to return to the main menu." << endl;
                cout << "---------------------------------------------------------------" << endl;

                cin >> response;
                   
            }
        }
        else if (input != NULL){
            nextHandler->handleRequest(input);
        }
}