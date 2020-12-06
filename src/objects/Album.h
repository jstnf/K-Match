#ifndef __ALBUM_H__
#define __ALBUM_H__

#include <string>

class Album {
  private:
    std::string id;
    std::string name;

  public:
    Album(std::string id, std::string name) : id(id), name(name) { }

    std::string getId() {
        return id;
    }

    std::string getName() {
        return name;
    }
};

#endif