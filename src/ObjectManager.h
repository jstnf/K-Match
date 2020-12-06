#ifndef __OBJECTMANAGER_H__
#define __OBJECTMANAGER_H__

#include "objects/Album.h"
#include "objects/Artist.h"
#include "objects/Track.h"

#include <unordered_map>

class ObjectManager {
  private:
    std::unordered_map<std::string, Album*>* albums;
    std::unordered_map<std::string, Artist*>* artists;
    std::unordered_map<std::string, Track*>* tracks;

  public:
    ObjectManager();
    ~ObjectManager();
    void add(Album* album);
    void add(Artist* artist);
    void add(Track* track);
    Album* getAlbum(std::string id);
    Artist* getArtist(std::string id);
    Track* getTrack(std::string id);

    std::unordered_map<std::string, Album*>* getAlbums() {
        return albums;
    }

    std::unordered_map<std::string, Artist*>* getArtists() {
        return artists;
    }

    std::unordered_map<std::string, Track*>* getTracks() {
        return tracks;
    }
};

#endif