cmake_minimum_required(VERSION 3.26)
project(lifap)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/include)
include_directories(./inc)

link_directories(/usr/lib)
link_directories(./lib)

link_libraries(sfml-graphics sfml-window sfml-system fmod fmodstudio)

SET(CMAKE_SKIP_BUILD_RPATH  FALSE)
set(CMAKE_INSTALL_RPATH "./lib")
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH FALSE)

add_executable(lifap
        SaveManager.cpp
        SaveManager.h
        Save.cpp
        Save.h
        Save.h
        main.cpp
        audio/AudioManager.cpp
        audio/AudioManager.h
        audio/EventInstance.cpp
        audio/EventInstance.h
        audio/Utils.h)

install(TARGETS lifap DESTINATION /home/flashonfire/Dev/lifap/bin)