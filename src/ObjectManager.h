#ifndef __OBJECTMANAGER_H__
#define __OBJECTMANAGER_H__

#include "objects/Album.h"
#include "objects/Artist.h"
#include "objects/Track.h"

#include <unordered_map>
#include <vector>

class ObjectManager {
  private:
    std::unordered_map<std::string, Album*>* albums;
    std::unordered_map<std::string, Artist*>* artists;
    std::unordered_map<std::string, Track*>* tracks;
    std::unordered_map<std::string, std::vector<std::string>>* albumArtists;
    std::unordered_map<std::string, std::vector<std::string>>* trackArtists;

  public:
    ObjectManager();
    ~ObjectManager();
    void add(Album* album);
    void add(Artist* artist);
    void add(Track* track);
    void addTrackArtist(std::string trackId, std::string artistId);
    void addAlbumArtist(std::string albumId, std::string artistId);
    Album* getAlbum(std::string id);
    Artist* getArtist(std::string id);
    Track* getTrack(std::string id);
    std::vector<std::string> getTrackArtists(std::string trackId);
    std::vector<std::string> getAlbumArtists(std::string albumId);

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