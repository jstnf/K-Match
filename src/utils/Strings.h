#ifndef __KMUTILS_H__
#define __KMUTILS_H__

#include <string>
#include <vector>

class Strings {
  public:
    // https://stackoverflow.com/questions/16286095/similar-function-to-javas-string-split-in-c
    static std::vector<std::string> split(const std::string& str, const std::string& separator) {
        char* cstr = const_cast<char*>(str.c_str());
        char* current;
        std::vector<std::string> arr;
        current = strtok_s(cstr, separator.c_str());
        while (current != NULL){
            arr.push_back(current);
            current = strtok(NULL, sep.c_str());
        }
        return arr;
    }
};

#endif