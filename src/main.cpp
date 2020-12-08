#include "algorithm/SearchEngine.h"
#include "io/ObjectLoader.h"

#include <iostream>
#include <Windows.h>

void search(ObjectManager* om, SearchEngine* se, std::string keyword);

int main() {
    ObjectManager* om = new ObjectManager();
    ObjectLoader* ol = new ObjectLoader(om);
    if (!ol->loadObjects()) {
        std::cout << "Unable to load Spotify objects! Please ensure the proper files are available and try again." << std::endl;
        return 1;
    }
    delete ol;

    std::cout << "Hello world!" << std::endl;

    SearchEngine* se = new SearchEngine(om);

    // Test code below
    SetConsoleOutputCP(CP_UTF8);

    std::string str;
    int searches = 0;
    while (searches < 3) {
        getline(std::cin, str);
        search(om, se, str);
        searches++;
    }

    delete se;
    delete om;
    std::cout << "Goodbye! :)" << std::endl;
    return 0;
}

void search(ObjectManager* om, SearchEngine* se, std::string keyword) {
    TrackSort* sorter = new PopularitySort(); // Change the sort here

    std::vector<Track*> results = se->search(keyword, *sorter);
    for (auto it = results.begin(); it != results.end(); it++) {
        Track* t = *it;
        std::cout << "[" << t->getPopularity() << "] " << t->getName() << " - ";
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
    }
}