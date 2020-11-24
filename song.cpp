#ifndef __SONG_CPP__
#define __SONG_CPP__
#include "song.hpp" 
#include <iostream>
#include <string>

using namespace std;

void Song::setSongName(string sName)
{
    songName = sName;
}

void Song::setSongArtist(string sArtist)
{
    songArtist = sArtist;
}

void Song::setSongGenre(string sGenre)
{
    songGenre = sGenre;
}

void Song::setSongLength(int sLength)
{
    songLength = sLength;
}

#endif