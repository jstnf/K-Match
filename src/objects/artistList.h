#ifndef __ARTISTLIST_H
#define __ARTISTLIST_H

#include "artist.h"

#include <string>
#include <vector>
#include <fstream>

class ArtistList
{
    public:

    ArtistList(string filename)
    {
        fstream artistFile(filename);
        string lineContent;

        while(!artistFile.eof())
        {
            getline(artistFile, lineContent);

            Artist a(lineContent);
            vArtist.push_back(a);
        }
        artistFile.close();

        sort(vArtist.begin(), vArtist.end(), [](Artist &a1, Artist &a2 )
        {
            return a1.getArtistName() < a2.getArtistName();
        });
    }

    vector<Artist> getAlphaSortArtistA2Z()
    {
        return vArtist;
    }

    vector<Artist> getAlphaSortArtistZ2A()
    {
        reverse(vArtist.begin(), vArtist.end());
        return vArtist;
    }

    void printArtistVector(Artist newArtist)
    {
        cout << "Artist ID: " << newArtist.getArtistID() << endl;
        cout << "Artist Name: " << newArtist.getArtistName() << endl;
        cout << endl;
    }

    private:
    vector<Artist> vArtist;
};

#endif