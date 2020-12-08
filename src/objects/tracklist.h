#ifndef __TRACKLIST_H
#define __TRACKLIST_H

#include "Track.h"

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <sstream>

using namespace std;

#define POPULAR 80

class TrackList
{
public:


TrackList(string fileName)
{
    fstream trackFile(fileName);

    string myString;

    while(!trackFile.eof())
    {
        getline(trackFile, myString);

        Track s(myString);
        vTracks.push_back(s);
    }

    trackFile.close();

    sort(vTracks.begin(), vTracks.end(), [](Track &s1, Track &s2)
    {
        return s1.getTrackName() < s2.getTrackName();
    });
}

vector<Track> getAlphaSortTracksZ2A()
{
    return vTracks;
}

vector<Track> getAlphaSortTracksA2Z()
{
    reverse(vTracks.begin(), vTracks.end());
    return vTracks;
}

vector<Track> getMostPopTracks()
{
    vector<Track> toReturn;

    for(Track s : this->vTracks)
    {
        if (s.getTrackPopularity() >= POPULAR)
        {
            toReturn.push_back(s);
        }
    }
    return toReturn;
}

vector<Track> sortLeastToMostPop()
{
    sort(vTracks.begin(), vTracks.end(), [](Track &s1, Track &s2)
    {
        return s1.getTrackPopularity() < s2.getTrackPopularity();
    });

    return vTracks;
}

vector<Track> sortShortestToLongest()
{
    sort(vTracks.begin(), vTracks.end(), [](Track &s1, Track &s2)
    {
        return s1.getTrackDuration() < s2.getTrackDuration();
    });
    
    return vTracks;
}

vector<Track> sortLongestToShortest()
{
    sort(vTracks.begin(), vTracks.end(), [](Track &s1, Track &s2)
    {
        return s1.getTrackDuration() > s2.getTrackDuration();
    });
    
    return vTracks;
}

void printTrackVector(Track firstTrack)
{
    cout << "Track Name: " << firstTrack.getTrackName() << endl;
    cout << "Track Album: " << firstTrack.getTrackAlbumID() << endl;
    cout << "Track ID: " << firstTrack.getTrackID() << endl;
    cout << "Track Duration: " << firstTrack.getTrackDuration() << endl;
    cout << "Track Popularity (1-100): " << firstTrack.getTrackPopularity() << endl;
    cout << endl;
}

    //private:
    vector<Track> vTracks;
    vector<Track> vSearchedTrack;
};

#endif