#include "../include/Playlist.h"

// ------------ Playlist class constructor ------------

Playlist::Playlist(std::string name) : playlistName(std::move(name)), songs() {}

// ---------- Playlist music vector getter  -----------

std::vector <Music>& Playlist::getSongs()
{
    return songs;
}

// --------- Playlist name getter and setter ----------

std::string Playlist::getPlaylistName() // Getter
{
    return playlistName;
}

void Playlist::setPlaylistName(std::string name) // Setter
{
    playlistName = std::move(name);
}

// -------- Add and remove songs from playlist --------

void Playlist::addSong(Music& song) // Add song
{
    songs.push_back(song);
}

void Playlist::removeSong(Music& song) // Remove
{
    // Check if the playlist is empty before attempting removal
    if (isEmpty())
    {
        std::cout << std::endl;
        throw std::runtime_error("The playlist is empty.");
    }

    // Delete song from playlist
    songs.erase(std::remove_if(songs.begin(), songs.end(), [&song](Music& item)
    {
        return item.getMusicTitle() == song.getMusicTitle() && item.getArtistName() == song.getArtistName();
    }), songs.end());
}

// ---------------- List playlist songs ---------------

void Playlist::listSongs()
{
    std::cout << "Playlist: " << playlistName << std::endl;
    std::cout << std::endl;

    // Check if the playlist is empty
    if (isEmpty())
    {
        std::cout << "The playlist is empty." << std::endl;
        std::cout << std::endl;
    }
    else
    {
        // Loop on songs vector
        for (Music& song : songs)
        {
            std::cout << "| " << song.getMusicTitle() << " - " << song.getArtistName() << std::endl;
        }

        std::cout << std::endl;
    }
}

// ---------- Check if the playlist is empty ----------

bool Playlist::isEmpty()
{
    return songs.empty();
}

// ------- Check if music exist in the playlist -------

bool Playlist::isSongInPlaylist(Music& song)
{
    // Loop through the songs
    for (Music& playlistSong : songs)
    {
        // Check if music title and artist name are equal to the current song on the loop
        if(playlistSong.getMusicTitle() == song.getMusicTitle() && playlistSong.getArtistName() == song.getArtistName())
        {
            return true;
        }
    }

    return false;
}
