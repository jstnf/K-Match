#include "ObjectManager.h"

ObjectManager::ObjectManager() {
    albums = new std::unordered_map<std::string, Album*>();
    artists = new std::unordered_map<std::string, Artist*>();
    tracks = new std::unordered_map<std::string, Track*>();
}

ObjectManager::~ObjectManager() {
    delete albums;
    delete artists;
    delete tracks;
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

Album* ObjectManager::getAlbum(std::string id) {
    return albums->at(id);
}

Artist* ObjectManager::getArtist(std::string id) {
    return artists->at(id);
}

Track* ObjectManager::getTrack(std::string id) {
    return tracks->at(id);
}