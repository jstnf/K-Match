#ifndef __TRACKARTIST_H
#define __TRACKARTIST_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class TrackArtist
{
    private:
        string TrackID;
        string TrackSongID;
        string TrackArtistID;
        vector<Track> vTracks;
        

    public:
        //Default Constructor
        TrackArtist(string TrackArtistInformation)
        {
            stringstream TrackArtistStream(TrackArtistInformation);
            //TrackArtistStream >> TrackID;
            TrackArtistStream >> TrackSongID;
            TrackArtistStream >> TrackArtistID;
        }

        //Accessor Functions
        string getTrackArtistID() 
        {
            return TrackID;
        }

        string getTrackArtistSongID() 
        {
            return TrackSongID;
        }

        string getTrackArtistArtistID()
        {
            return TrackArtistID;
        }
};

#endif