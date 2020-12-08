#include "ObjectManager.h"

ObjectManager::ObjectManager() {
    albums = new std::unordered_map<std::string, Album*>();
    artists = new std::unordered_map<std::string, Artist*>();
    tracks = new std::unordered_map<std::string, Track*>();
    trackArtists = new std::unordered_map<std::string, std::vector<std::string>>();
    albumArtists = new std::unordered_map<std::string, std::vector<std::string>>();
}

ObjectManager::~ObjectManager() {
    delete albums;
    delete artists;
    delete tracks;
    delete trackArtists;
    delete albumArtists;
}

void ObjectManager::add(Album* album) {
    albums->insert(std::make_pair(album->getId(), album));
}

void ObjectManager::add(Artist* artist) {
    artists->insert(std::make_pair(artist->getId(), artist));
}

void ObjectManager::add(Track* track) {
    tracks->insert(std::make_pair(track->getId(), track));
}

void ObjectManager::addTrackArtist(std::string trackId, std::string artistId) {
    auto it = trackArtists->find(trackId);
    if (it == trackArtists->end()) {
        std::vector<std::string> artistVector = std::vector<std::string>();
        artistVector.push_back(artistId);
        trackArtists->insert(std::make_pair(trackId, artistVector));
    } else {
        it->second.push_back(artistId);
    }
}

void ObjectManager::addAlbumArtist(std::string albumId, std::string artistId) {
    auto it = albumArtists->find(albumId);
    if (it == albumArtists->end()) {
        std::vector<std::string> artistVector = std::vector<std::string>();
        artistVector.push_back(artistId);
        albumArtists->insert(std::make_pair(albumId, artistVector));
    } else {
        it->second.push_back(artistId);
    }
}

Album* ObjectManager::getAlbum(std::string id) {
    return albums->at(id);
}

Artist* ObjectManager::getArtist(std::string id) {
    return artists->at(id);
}

Track* ObjectManager::getTrack(std::string id) {
    return tracks->at(id);
}

std::vector<std::string> ObjectManager::getTrackArtists(std::string trackId) {
    return trackArtists->at(trackId);
}

std::vector<std::string> ObjectManager::getAlbumArtists(std::string albumId) {
    return albumArtists->at(albumId);
}