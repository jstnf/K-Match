#ifndef __ALBUMARTISTLIST_H__
#define __ALBUMARTISTLIST_H__

#include "albumartist.h"

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class aAlbumList
{
    public: 
    aAlbumList(string filename)
    {
        fstream aAlbumFile(filename);
        string lineContent;

        while(!aAlbumFile.eof())
        {
            getline(aAlbumFile, lineContent);

            AlbumArtist a(lineContent);
            vAA.push_back(a);
        }

        aAlbumFile.close();

        sort(vAA.begin(), vAA.end(), [](AlbumArtist &a1, AlbumArtist &a2)
        {
            return a2.getAAlbumID() < a2.getAArtistID();
        });
    }

    vector<AlbumArtist> getAAID()
    {
        return vAA;
    }

    vector<AlbumArtist> sortAAID()
    {
        reverse(vAA.begin(), vAA.end());
        return vAA;
    }

    void printAAVector(AlbumArtist newAArtist)
    {
        cout << "Album ID: " << newAArtist.getAAlbumID() << endl;
        cout << "Album Artist ID: " << newAArtist.getAArtistID() << endl;
    }

    private:
    vector<AlbumArtist> vAA;
};

#endif