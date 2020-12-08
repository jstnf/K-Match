#ifndef __TRACKSORT_H__
#define __TRACKSORT_H__

#include "../objects/Track.h"

#include <algorithm>
#include <vector>

class TrackSort {
  protected:
    virtual bool operator()(const Track& t1, const Track& t2) = 0;
  public:
    void sort(std::vector<Track*> &vect) {
        std::sort(vect.begin(), vect.end(), this);
    }
};

class PopularitySort : public TrackSort {
  protected:
    virtual bool operator()(const Track& t1, const Track& t2);
};

class AlphabeticalSort : public TrackSort {
  protected:
    virtual bool operator()(const Track& t1, const Track& t2);
};

#endif