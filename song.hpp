#ifndef __SONG_HPP__
#define __SONG_HPP__

#include <string>
#include <iostream>

using namespace std;


class Song 
{
    private:
        string songName;
        string songArtist;
        string songGenre;
        int songLength;

    public:
        void setSongName(string sName);
        void setSongArtist(string sArtist);
        void setSongGenre(string sGenre);
        void setSongLength(int sLength);

}

#endif