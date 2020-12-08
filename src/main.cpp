#include "KMatch.hpp"

#include <iostream>
#include <Windows.h>

int main() {
    std::cout << "Starting KMatch..." << std::endl;
    KMatch kmatch = KMatch();
    if (kmatch.initialize() != 0) {
        std::cout << "Error initializing KMatch. Please try again." << std::endl;
        return -1;
    }

    // For Windows console
    SetConsoleOutputCP(CP_UTF8);
    return kmatch.mainMenu();
}