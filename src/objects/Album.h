#ifndef __ALBUM_H__
#define __ALBUM_H__

#include "KMObject.h"

#include <ctime>

class Album : public KMObject {
  private:
    const std::time_t releaseTime;

  public:
    Album(std::string id, std::string name, std::time_t releaseTime) : KMObject(id, name), releaseTime(releaseTime) { }

    std::time_t getReleaseTime() const {
        return releaseTime;
    }
};

#endif