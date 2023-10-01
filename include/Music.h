#ifndef MUSIC_H
#define MUSIC_H

#include <string>
#include <utility>

class Music
{

private: // Private member variables to store music information

    std::string musicTitle;
    std::string artistName;

public: // Public methods

    // ----------- Music class constructor -----------

    Music(std::string title, std::string artist);

    // -------- Music title getter and setter --------

    std::string getMusicTitle(); // Getter
    void setMusicTitle(std::string title); // Setter

    // -------- Artist name getter and setter --------

    std::string getArtistName(); // Getter
    void setArtistName(std::string name); // Setter
};

#endif //MUSIC_H
