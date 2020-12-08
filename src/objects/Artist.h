#ifndef __ARTIST_H__
#define __ARTIST_H__

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Artist
{
  public:
    Artist(string artistInfo)
    {
      stringstream artistStream(artistInfo);
      artistStream >> artistID;
      artistStream >> artistName;
    }

    string getArtistID()
    {
      return artistID;
    }

    string getArtistName()
    {
      return artistName;
    }

  private:
    string artistID;
    string artistName;
    vector<Artist> vArtist;
};

#endif