#ifndef __ALBUMARTIST_H__
#define __ALBUMARTIST_H__

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class AlbumArtist
{
    private:
    vector<AlbumArtist> vAA;
    string aAlbumID;
    string aArtistID;

    public:
    AlbumArtist(string albumArtistInfo)
    {
        stringstream aalbumStream(albumArtistInfo);
        aalbumStream >> aAlbumID;
        aalbumStream >> aArtistID;
    }

    string getAAlbumID()
    {
        return aAlbumID;
    }

    string getAArtistID()
    {
        return aArtistID;
    }
};

#endif