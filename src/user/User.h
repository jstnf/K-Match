#ifndef __USER_H__
#define __USER_H__

#include <string>

class User {
  private:
    std::string id;

  public:
    User(std::string id) : id(id) { }

    std::string getId() const {
        return id;
    }
};

#endif