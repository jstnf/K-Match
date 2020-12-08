PROJECT(KMatch)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

SET(SOURCE_FILES src/main.cpp
        src/ObjectManager.cpp
        src/algorithm/TrackSort.cpp
        src/io/ObjectLoader.cpp
        src/objects/SearchEngine.cpp)

ADD_EXECUTABLE(kmatch ${SOURCE_FILES})
