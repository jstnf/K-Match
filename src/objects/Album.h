#ifndef __ALBUM_H__
#define __ALBUM_H__

#include <ctime>
#include <string>

class Album {
  private:
    const std::string id;
    const std::string name;
    const std::time_t releaseTime;

  public:
    Album(std::string id, std::string name, std::time_t releaseTime) : id(id), name(name), releaseTime(releaseTime) { }

    std::string getId() const {
        return id;
    }

    std::string getName() const {
        return name;
    }

    std::time_t getReleaseTime() const {
        return releaseTime;
    }
};

#endif