#ifndef __ALBUM_H__
#define __ALBUM_H__

#include <ctime>
#include <string>

class Album {
  private:
    std::string id;
    std::string name;
    std::time_t releaseTime;

  public:
    Album(std::string id, std::string name, std::time_t releaseTime) : id(id), name(name), releaseTime(releaseTime) { }

    std::string getId() {
        return id;
    }

    std::string getName() {
        return name;
    }

    std::time_t getReleaseTime() {
        return releaseTime;
    }
};

#endif