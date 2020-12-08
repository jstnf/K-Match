#ifndef __KMATCH_H__
#define __KMATCH_H__

#include "io/ObjectLoader.h"
#include "algorithm/SearchEngine.h"

class KMatch {
  private:
    ObjectManager* om;
    SearchEngine* se;

  public:
    int initialize();
    int mainMenu();

    ObjectManager* getObjectManager() {
        return om;
    }

    SearchEngine* getSearchEngine() {
        return se;
    }
};

#endif