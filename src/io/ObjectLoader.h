#ifndef __OBJECTLOADER_H__
#define __OBJECTLOADER_H__

class ObjectLoader {
  private:
    const ObjectManager* om;

  public:
    ObjectLoader(ObjectManager* om) : om(om) { }
    bool readAlbums();
    bool readArtists();
    bool readTracks();
    bool readAlbumArtists();
    bool readTrackArtists();
};

#endif