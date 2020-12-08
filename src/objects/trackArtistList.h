#ifndef __TRACKARTISTLISH_H
#define __TRACKARTISTLISH_H

#include "trackArtist.h"

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

class TrackArtistList
{
    public:
    TrackArtistList(string fileName)
{
    fstream trackFile(fileName);

    string lineContents;

    while(!trackFile.eof())
    {
        getline(trackFile, lineContents);

        TrackArtist t(lineContents);
        vTracksArtist.push_back(t);
    }

    trackFile.close();

    sort(vTracksArtist.begin(), vTracksArtist.end(), [](TrackArtist &s1, TrackArtist &s2)
    {
        return s1.getTrackArtistSongID() < s2.getTrackArtistSongID();
    });
}

vector<TrackArtist> getAlphaSortTracksZ2A()
{
    return vTracksArtist;
}

vector<TrackArtist> getAlphaSortTracksA2Z()
{
    reverse(vTracksArtist.begin(), vTracksArtist.end());
    return vTracksArtist;
}

void printTrackVector(TrackArtist firstTrack)
{
    //cout << "Track ID: " << firstTrack.getTrackArtistID() << endl;
    cout << "Track Song ID: " << firstTrack.getTrackArtistSongID() << endl;
    cout << "Track Artist ID: " << firstTrack.getTrackArtistArtistID() << endl;
    cout << endl;
}
        

    private:
    vector<TrackArtist> vTracksArtist;
};

#endif
