#include "../include/System.h"

// ------------ System class constructor ------------

System::System() : systemSongs(), systemPlaylists() {}

// -------- Add and remove songs from system --------

void System::addSongToSystem(Music& song) // Add
{
    // Check if the song already exists
    if (existSong(song))
    {
        std::cout << std::endl;
        std::cout << "The music already exists on the system." << std::endl;
        std::cout << std::endl;

        return;
    }

    systemSongs.push_back(song);

    std::cout << std::endl;
    std::cout << "Song '" << song.getMusicTitle() << "' added to system" << std::endl;
    std::cout << std::endl;
}

void System::removeSongFromSystem(Music& song) // Remove
{
    // Check if the System is empty before attempting removal
    if (isSongsEmpty())
    {
        std::cout << std::endl;
        std::cout << "There are no songs registered." << std::endl;
        std::cout << std::endl;

        return;
    }

    // Check if song exist
    if (existSong(song))
    {
        // Delete song from system
        systemSongs.erase (std::remove_if(systemSongs.begin(), systemSongs.end(), [&song](Music& item)
        {
            return item.getMusicTitle() == song.getMusicTitle() && item.getArtistName() == song.getArtistName();
        }), systemSongs.end());

        // Loop through playlists
        for (Playlist& playlist : systemPlaylists)
        {
            // Delete song from playlist
            if (playlist.isSongInPlaylist(song))
            {
                playlist.removeSong(song);
            }
        }

        std::cout << std::endl;
        std::cout << "Song '" << song.getMusicTitle() << "' removed from system and all playlists." << std::endl;
        std::cout << std::endl;
    }
    else // If song is not in
    {
        std::cout << std::endl;
        std::cout << "Song not found." << std::endl;
        std::cout << std::endl;

        return;
    }
}

// ------ Add and remove playlists from system ------

void System::addPlaylistToSystem(Playlist& playlist) // Add
{
    // // Check if the playlist already exists
    if (existPlaylist(playlist))
    {
        std::cout << std::endl;
        std::cout << "The playlist already exists on the system." << std::endl;
        std::cout << std::endl;

        return;
    }

    systemPlaylists.push_back(playlist);

    std::cout << std::endl;
    std::cout << "Playlist '" << playlist.getPlaylistName() << "' added to system" << std::endl;
    std::cout << std::endl;
}

void System::removePlaylistFromSystem(Playlist& playlist) // Remove
{
    // Check if the System is empty before attempting removal
    if (isPlaylistsEmpty())
    {
        std::cout << std::endl;
        std::cout << "There are no playlists registered." << std::endl;
        std::cout << std::endl;

        return;
    }

    // Check if playlist exist
    if (existPlaylist(playlist))
    {
        // Delete playlist from system
        systemPlaylists.erase (std::remove_if(systemPlaylists.begin(), systemPlaylists.end(), [&playlist](Playlist& item)
        {
            return item.getPlaylistName() == playlist.getPlaylistName();
        }), systemPlaylists.end());

        std::cout << std::endl;
        std::cout << "Playlist '" << playlist.getPlaylistName() << "' removed from system." << std::endl;
        std::cout << std::endl;
    }
    else // If is not in
    {
        std::cout << std::endl;
        std::cout << "Playlist not found." << std::endl;
        std::cout << std::endl;

        return;
    }
}

// ------- Add and remove songs from playlist -------

void System::addSongToPlaylist(Music& song, Playlist& playlist) // Add
{
    // Check if song and playlist exist
    if (existSong(song) && existPlaylist(playlist))
    {
        // Check if song is already on the playlist
        if (playlist.isSongInPlaylist(song))
        {
            std::cout << std::endl;
            std::cout << "This song is already on the playlist." << std::endl;
            std::cout << std::endl;

            return;
        }
        else // If is not in
        {
            playlist.addSong(song);

            std::cout << std::endl;
            std::cout << "Song '" << song.getMusicTitle() << "' added to playlist '" << playlist.getPlaylistName() << "'." << std::endl;
            std::cout << std::endl;
        }
    }
    else // If song or playlist was not found
    {
        std::cout << std::endl;
        std::cout << "Song or Playlist not found." << std::endl;
        std::cout << std::endl;

        return;
    }
}

void System::removeSongFromPlaylist(Music &song, Playlist &playlist) // Remove
{
    // Check if song and playlist exist
    if (existSong(song) && existPlaylist(playlist))
    {
        // Check if song is already on the playlist
        if (playlist.isSongInPlaylist(song))
        {
            playlist.removeSong(song);

            std::cout << std::endl;
            std::cout << "Song '" << song.getMusicTitle() << "' removed from playlist '" << playlist.getPlaylistName() << "'." << std::endl;
            std::cout << std::endl;
        }
        else // If is not in
        {
            std::cout << std::endl;
            std::cout << "This song is not on the playlist." << std::endl;
            std::cout << std::endl;

            return;
        }
    }
    else // If song or playlist was not found
    {
        std::cout << std::endl;
        std::cout << "Song or Playlist not found." << std::endl;
        std::cout << std::endl;

        return;
    }
}

// -------- Check if System vectors are empty -------

bool System::isSongsEmpty() // Songs
{
    return systemSongs.empty();
}

bool System::isPlaylistsEmpty() // Playlist
{
    return systemPlaylists.empty();
}

// -------- Check if music or playlist exist --------

bool System::existSong(Music& song) // Music
{
    // Loop through  the system songs
    for (Music& systemSong : systemSongs)
    {
        // Check if music title and artist name are equal to the current song on the loop
        if (systemSong.getMusicTitle() == song.getMusicTitle() && systemSong.getArtistName() == song.getArtistName())
        {
            return true;
        }
    }

    return false;
}

bool System::existPlaylist(Playlist& playlist) // Playlist
{
    // Loop through the system playlists
    for (Playlist& systemPlaylist : systemPlaylists)
    {
        // Check if playlist title are equal to the current playlist on the loop
        if (systemPlaylist.getPlaylistName() == playlist.getPlaylistName())
        {
            return true;
        }
    }

    return false;
}

//------- List all system songs and playlists -------

void System::printSystemSongs() // Songs
{
    std::cout << std::endl;
    std::cout << "System Songs: " << std::endl;
    std::cout << std::endl;

    // Loop through the system songs
    for (Music song : systemSongs)
    {
        std::cout << "| " << song.getMusicTitle() << " - " << song.getArtistName() << std::endl;
    }
}

void System::printSystemPlaylists() // Playlists
{
    std::cout << std::endl;
    std::cout << "System Playlists: " << std::endl;
    std::cout << std::endl;

    // Loop through the system playlists
    for (Playlist playlist : systemPlaylists)
    {
        std::cout << "| " << playlist.getPlaylistName() << std::endl;
    }
}

// ---- Search for song or playlist by the name -----

Playlist& System::searchPlaylistByName(std::string& playlistName)
{
    // Loop through the system playlists
    for (Playlist& playlist : systemPlaylists)
    {
        // Check if playlist title are equal to the current playlist on the loop
        if (playlist.getPlaylistName() == playlistName)
        {
            return playlist;
        }
    }

    // Error message
    std::cout << std::endl;
    throw std::runtime_error("Playlist not found.");
}

Music& System::searchSongByName(std::string& songName)
{
    // Loop through  the system songs
    for (Music& song : systemSongs)
    {
        // Check if song title are equal to the current song on the loop
        if (song.getMusicTitle() == songName)
        {
            return song;
        }
    }

    // Error message
    std::cout << std::endl;
    throw std::runtime_error("Song not found.");
}
