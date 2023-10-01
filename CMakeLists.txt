cmake_minimum_required(VERSION 3.0)

# Project name
project(playlistManager)

# Source files
set(SOURCES
src/PlaylistManager.cpp
src/Music.cpp
src/Playlist.cpp
src/System.cpp)

# Inclusion directories
include_directories(include)

# Add the "-g" debug flag when compiling with GCC or Clang
if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
endif()

# Add the "/DEBUG" debug flag when compiling with MSVC
if(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /DEBUG")
endif()

# Create executable
add_executable(manager ${SOURCES})
target_link_libraries(manager PRIVATE ${CURSES_LIBRARIES})
