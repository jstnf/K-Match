#ifndef __TRACK_H__
#define __TRACK_H__

#include <string>

class Track {
  private:
    std::string id;
    std::string name;
    std::string albumId;
    int durationMs;
    int popularity;
    
  public:
    Track(std::string name, std::string albumId, int durationMs, int popularity) : name(name), albumId(albumId), durationMs(durationMs), popularity(popularity) { }

    std::string getId() {
        return id;
    }

    std::string getName() {
        return name;
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