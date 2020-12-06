#ifndef __ARTIST_H__
#define __ARTIST_H__

#include <string>

class Artist {
  private:
    std::string id;
    std::string name;

  public:
    Artist(std::string id, std::string name) : id(id), name(name) { }

    std::string getId() {
        return id;
    }

    std::string getName() {
        return name;
    }
};

#endif