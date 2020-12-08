#ifndef __TRACK_H__
#define __TRACK_H__

#include <string>

class Track {
  private:
    const std::string id;
    const std::string name;
    const std::string albumId;
    const int durationMs;
    const int popularity;
    
  public:
    Track(std::string name, std::string albumId, int durationMs, int popularity) : name(name), albumId(albumId), durationMs(durationMs), popularity(popularity) { }

    std::string getId() const {
        return id;
    }

    std::string getName() const {
        return name;
    }

    std::string getAlbumId() const {
        return albumId;
    }

    int getDurationMs() const {
        return durationMs;
    }

    int getPopularity() const {
        return popularity;
    }
};

#endif