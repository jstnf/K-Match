#ifndef __TRACK_H__
#define __TRACK_H__

#include <string>
#include <vector>

class Track {
  private:
    std::string id;
    std::string name;
    std::vector<std::string>* artistIds;
    std::string albumId;
    int durationMs;
    int popularity;
    
  public:
    Track(std::string name, std::string albumId, int durationMs, int popularity) : name(name), albumId(albumId), durationMs(durationMs), popularity(popularity) {
        artistIds = new std::vector<std::string>();
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

    std::string getAlbumId() {
        return albumId;
    }

    int getDurationMs() {
        return durationMs;
    }

    int getPopularity() {
        return popularity;
    }
};

#endif