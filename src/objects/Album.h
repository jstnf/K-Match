#ifndef __ALBUM_H__
#define _ALBUM_H__

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>

using namespace std;

class Album
{
  private:
    vector<Album> vAlbum;
    string albumID;
    string albumName;
    string albumRelease;

  public:
    Album(string albumInfo)
    {
      stringstream albumStream(albumInfo);
      albumStream >> albumID;
      albumStream >> albumName;
      albumStream >> albumRelease;
    }

    string getAlbumID()
    {
      return albumID;
    }

    string getAlbumName()
    {
      return albumName;
    }

    string getAlbumRelease()
    {
      return albumRelease;
    }
};

#endif