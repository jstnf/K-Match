#include "io/ObjectLoader.h"

#include <iostream>
// #include <Windows.h>

int main() {
    ObjectManager* om = new ObjectManager();
    ObjectLoader* ol = new ObjectLoader(om);
    if (!ol->loadObjects()) {
        std::cout << "Unable to load Spotify objects! Please ensure the proper files are available and try again." << std::endl;
        return 1;
    }
    delete ol;

    std::cout << "Hello world!" << std::endl;

    // Test code below

    /*
    std::cout << "There are " << std::endl
              << om->getAlbums()->size() << " albums, " << std::endl
              << om->getArtists()->size() << " artists, and" << std::endl
              << om->getTracks()->size() << " tracks loaded." << std::endl;

    SetConsoleOutputCP(CP_UTF8);

    auto it = om->getTracks()->begin();
    while (it != om->getTracks()->end()) {
        Track* t = it->second;
        std::cout << t->getName() << " - ";
        auto artistVect = om->getTrackArtists(t->getId());
        auto aIt = artistVect.begin();
        while (aIt != artistVect.end()) {
            std::cout << om->getArtist(*aIt)->getName();
            aIt++;
            if (aIt != artistVect.end()) {
                std::cout << ", ";
            } else {
                std::cout << std::endl;
            }
        }
        it++;
    }
     */

    delete om;
    std::cout << "Goodbye! :)" << std::endl;
    return 0;
}