#ifndef SYSTEM_H
#define SYSTEM_H

#include "Playlist.h"

class System
{

private: // private member variables to store system musics and playlists

    std::vector <Music> systemSongs;
    std::vector <Playlist> systemPlaylists;

public: // Public methods

    // ------------ System class constructor ------------

    System();

    // -------- Add and remove songs from system --------

    void addSongToSystem(Music& song);
    void removeSongFromSystem(Music& song);

    // ------ Add and remove playlists from system ------

    void addPlaylistToSystem(Playlist& playlist);
    void removePlaylistFromSystem(Playlist& playlist);

    // ------- Add and remove songs from playlist -------

    void addSongToPlaylist(Music& song, Playlist& playlist);
    void removeSongFromPlaylist(Music& song, Playlist& playlist);

    // -------- Check if System vectors are empty -------

    bool isSongsEmpty();
    bool isPlaylistsEmpty();

    // -------- Check if music or playlist exist --------

    bool existSong(Music& song);
    bool existPlaylist(Playlist& playlist);

    //------- List all system songs and playlists -------

    void printSystemSongs();
    void printSystemPlaylists();

    // ---- Search for song or playlist by the name -----

    Music& searchSongByName(std::string& songName);
    Playlist& searchPlaylistByName(std::string& playlistName);
};

#endif //SYSTEM_H
