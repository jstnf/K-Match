#ifndef __TRACK_H
#define __TRACK_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Track
{
    private:
        string trackID;
        string trackName;
        string trackAlbumID;
        int trackDuration;
        int trackPopularity;

    public:
        //Default Constructor
        Track(string trackInformation)
        {
            stringstream trackStream(trackInformation);
            
            trackStream >> trackID;
            trackStream >> trackName;
            trackStream >> trackAlbumID;
            trackStream >> trackDuration;
            trackStream >> trackPopularity;
        } 

        //Accessor Functions
        string getTrackName() 
        {
            return trackName;
        }

        string getTrackAlbumID() 
        {
            return trackAlbumID;
        }

        string getTrackID()
        {
            return trackID;
        }

        int getTrackDuration() 
        {
            return trackDuration;
        }

        int getTrackPopularity() 
        {
            return trackPopularity;
        }
        
};

#endif