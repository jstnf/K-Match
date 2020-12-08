#ifndef __ARTIST_H__
#define __ARTIST_H__

#include <string>

class Artist {
  private:
    const std::string id;
    const std::string name;

  public:
    Artist(std::string id, std::string name) : id(id), name(name) { }

    std::string getId() const {
        return id;
    }

    std::string getName() const {
        return name;
    }
};

#endif