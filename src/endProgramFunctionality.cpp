#include "../header/mainMenu.hpp"
#include "../header/handler.hpp"
#include "../header/endProgramFunctionality.hpp"

using namespace std;

void menuEndProgram::setNextHandler(handler *request){
            nextHandler = request;
}
void menuEndProgram::handleRequest(char c){
    char input = c;
        if(input == '0'){
            cout << endl;
            cout << "---------------------------------------------------------------" << endl;
            cout << "                       Ending program" << endl;
            cout << "---------------------------------------------------------------" << endl;
        }
        else if (input != NULL){
            cout << "Please enter a valid option" << endl;

        }
}