#include "../header/mainMenu.hpp"
#include "../header/handler.hpp"
#include "../header/userSavedDataFunctionality.hpp"

using namespace std;

void menuSavedData::setNextHandler(handler *request){
            nextHandler = request;
}

void menuSavedData::handleRequest(char c){
    char input = c;
    std::string response = "";
        if(input == '2'){
            while(response!="0")
            {
                cout << endl;
                cout << "---------------------------------------------------------------" << endl;
                cout << "Saved Data: " << endl;
                cout << "Type 0 to exit." << endl;
                cout << "---------------------------------------------------------------" << endl;
                cin >> response;
            }
        }
        else if (input != NULL){
            nextHandler->handleRequest(input);
        }
}