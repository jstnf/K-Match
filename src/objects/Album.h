#ifndef __ALBUM_H__
#define __ALBUM_H__

#include <string>
#include <vector>

class Album {
  private:
    std::string id;
    std::string name;
    std::vector<std::string>* artistIds;

  public:
    Album(std::string id, std::string name) : id(id), name(name) {
        artistIds = new std::vector<std::string>();
    }

    ~Album() {
        delete artistIds;
    }

    void addArtist(std::string artistId) {
        artistIds->push_back(artistId);
    }

    std::string getId() {
        return id;
    }

    std::string getName() {
        return name;
    }

    std::vector<std::string>* getArtistIds() {
        return artistIds;
    }
};

#endif