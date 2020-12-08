#ifndef __ALBUM_H
#define __ALBUM_H

#include "album.h"

#include <string>
#include <vector>
#include <fstream>

using namespace std;

class AlbumList
{
    public:

    AlbumList(string filename)
    {
        fstream albumFile(filename);
        string lineContent;

        while(!albumFile.eof())
        {
            getline(albumFile, lineContent);

            Album a(lineContent);
            vAlbum.push_back(a);
        }
        albumFile.close();

        sort(vAlbum.begin(), vAlbum.end(), [](Album &a1, Album &a2 )
        {
            return a1.getAlbumName() < a2.getAlbumName();
        });
    }

    vector<Album> getAlphaSortAlbumA2Z()
    {
        return vAlbum;
    }

    vector<Album> getAlphaSortAlbumZ2A()
    {
        reverse(vAlbum.begin(), vAlbum.end());
        return vAlbum;
    }

    vector<Album> sortNewestToOldest()
    {
        sort(vAlbum.begin(), vAlbum.end(), [](Album &a1, Album &a2 )
        {
            return a1.getAlbumRelease() < a2.getAlbumRelease();
        });
        return vAlbum;
    }


    vector<Album> sortOldestToNewest()
    {
        sort(vAlbum.begin(), vAlbum.end(), [](Album &a1, Album &a2 )
        {
            return a1.getAlbumRelease() > a2.getAlbumRelease();
        });

        return vAlbum;
    }    

    void printArtistVector(Album newAlbum)
    {
        cout << "Artist ID: " << newAlbum.getAlbumID() << endl;
        cout << "Artist Name: " << newAlbum.getAlbumName() << endl;
        cout << endl;
    }

    private:
    vector<Album> vAlbum;
};

#endif