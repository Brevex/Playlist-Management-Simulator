#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Music.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdexcept>

class Playlist
{

private: // private member variables to store playlist information

    std::string playlistName;
    std::vector <Music> songs;

public: // Public methods

    // ------------ Playlist class constructor ------------

    explicit Playlist(std::string name);

    // ---------- Playlist music vector getter  -----------

    std::vector <Music>& getSongs();

    // --------- Playlist name getter and setter ----------

    std::string getPlaylistName(); // Getter
    void setPlaylistName(std::string name); // Setter

    // -------- Add and remove songs from playlist --------

    void addSong(Music& song);
    void removeSong(Music& song);

    // ---------------- List playlist songs ---------------

    void listSongs();

    // ---------- Check if the playlist is empty ----------

    bool isEmpty();

    // ------- Check if music exist in the playlist -------

    bool isSongInPlaylist(Music& song);
};

#endif //PLAYLIST_H
