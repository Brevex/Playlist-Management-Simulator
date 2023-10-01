#include "../include/Music.h"

// ---------------- Music class constructor ----------------

Music::Music(std::string title, std::string artist) : musicTitle(std::move(title)), artistName(std::move(artist)) {}

// ------------ Music title getters and setters ------------

std::string Music::getMusicTitle() // Music title getter
{
    return musicTitle;
}

void Music::setMusicTitle(std::string title) // Music title setter
{
    musicTitle = std::move(title);
}

// ------------ Artist name getters and setters ------------

std::string Music::getArtistName() // Artist name getter
{
    return artistName;
}

void Music::setArtistName(std::string name) // Music title setter
{
    artistName = std::move(name);
}
