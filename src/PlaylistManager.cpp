// ------------------------------ Includes -----------------------------

#include "../include/System.h"

#include <thread>
#include <chrono>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
#else
    #include <sys/ioctl.h>
    #include <unistd.h>
#endif

// ------------------------ Functions prototypes -----------------------

void addSongSystem(System& mainSystem);
void delSongSystem(System& mainSystem);

void addPlaylistSystem(System& mainSystem);
void delPlaylistSystem(System& mainSystem);

void addSongSystemPlaylist(System& mainSystem);
void delSongSystemPlaylist(System& mainSystem);

void printSongsAndPlaylists(System& mainSystem);
void printPlaylistsSongs(System& mainSystem);

void playSong(System& mainSystem);

bool isBlankOrSpaces(const std::string& input);
void clearScreen();

int getTermWidth();
void printHeader();
void printFunctionHeader(const std::string& funcName);

void runMenu(System& mainSystem);

// ---------------------------- Main function --------------------------

int main(int argc, char* args[])
{
    System playlistManagerSystem; // Main system

    // adding some musics and playlists to the system

    Music songs[10] = {
            Music("Seek and Destroy", "Metallica"),
            Music("Hail and Kill", "Manowar"),
            Music("Master of Puppets", "Metallica"),
            Music("The Unforgiven", "Metallica"),
            Music("The Trooper", "Iron Maiden"),
            Music("Ride the Lightning", "Metallica"),
            Music("Fade to Black", "Metallica"),
            Music("Courage", "Manowar"),
            Music("Sad But True", "Metallica"),
            Music("Master of Puppets", "Metallica")
    };

    Playlist playlist1("Rock"); // New playlist

    // Loop through the songs array
    for (auto & song : songs)
    {
        playlistManagerSystem.addSongToSystem(song); // Add to system
    }

    // Loop through the songs array
    for (auto & song : songs) // Add to playlist
    {
        playlist1.addSong(song);
    }

    playlistManagerSystem.addPlaylistToSystem(playlist1); // Adding playlist to system

    // end

    runMenu(playlistManagerSystem);

    return 0;
}

// -------------------- Functions implementation --------------------

void addSongSystem(System& mainSystem) // Add a song to system
{
    std::string songName, artistName;

    std::cout << "Enter the song name: ";
    std::getline (std::cin, songName);

    std::cout << "Enter the artist name: ";
    std::getline (std::cin, artistName);

    // Check if input is valid (blank or empty)
    if (!isBlankOrSpaces(songName) && !isBlankOrSpaces(artistName))
    {
        Music newSong(songName, artistName);

        mainSystem.addSongToSystem(newSong);
    }
    else
    {
        std::cout << std::endl;
        std::cout << "The entry cannot be left blank." << std::endl;
        std::cout << std::endl;
    }
}

void delSongSystem(System& mainSystem) // Delete a song to system
{
    std::string songName;

    mainSystem.printSystemSongs(); // Print current system songs

    std::cout << std::endl;

    std::cout << "Enter the song name: ";
    std::getline (std::cin, songName);

    // Check if input is valid (blank or empty)
    if (!isBlankOrSpaces(songName))
    {
        // Search for the song on the system
        Music foundSong = mainSystem.searchSongByName(songName);

        // Remove the song if it exists
        if (foundSong.getMusicTitle() == songName)
        {
            mainSystem.removeSongFromSystem(foundSong);
        }
    }
    else
    {
        std::cout << std::endl;
        std::cout << "The entry cannot be left blank." << std::endl;
        std::cout << std::endl;
    }
}

void addPlaylistSystem(System& mainSystem) // Add a playlist to system
{
    std::string playlistName;

    std::cout << "Enter the playlist name: ";
    std::getline (std::cin, playlistName);

    // Check if input is valid (blank or empty)
    if (!isBlankOrSpaces(playlistName))
    {
        Playlist newPlaylist(playlistName);

        mainSystem.addPlaylistToSystem(newPlaylist);
    }
    else
    {
        std::cout << std::endl;
        std::cout << "The entry cannot be left blank." << std::endl;
        std::cout << std::endl;
    }
}

void delPlaylistSystem(System& mainSystem) // Delete a playlist from system
{
    std::string playlistName;

    mainSystem.printSystemPlaylists(); // print current system playlists

    std::cout << std::endl;

    std::cout << "Enter the playlist name: ";
    std::getline (std::cin, playlistName);

    // Check if input is valid (blank or empty)
    if (!isBlankOrSpaces(playlistName))
    {
        // Search for the playlist on the system
        Playlist foundPlaylist = mainSystem.searchPlaylistByName(playlistName);

        // Remove the playlist if it exists
        if (foundPlaylist.getPlaylistName() == playlistName)
        {
            mainSystem.removePlaylistFromSystem(foundPlaylist);
        }
    }
    else
    {
        std::cout << std::endl;
        std::cout << "The entry cannot be left blank." << std::endl;
        std::cout << std::endl;
    }
}

void addSongSystemPlaylist(System& mainSystem) // Add song to playlist
{
    std::string songName, playlistName;

    mainSystem.printSystemSongs(); // Print current system songs
    mainSystem.printSystemPlaylists(); // Print current system playlists

    std::cout << std::endl;

    std::cout << "Enter the song name: ";
    std::getline (std::cin, songName);

    std::cout << "Enter the playlist name: ";
    std::getline (std::cin, playlistName);

    // Check if input is valid (blank or empty)
    if (!isBlankOrSpaces(songName) && !isBlankOrSpaces(playlistName))
    {
        // Search for the song and playlist on the system
        Music& foundSong = mainSystem.searchSongByName(songName);
        Playlist& foundPlaylist = mainSystem.searchPlaylistByName(playlistName);

        // Add the song to the playlist if it exists
        if (foundSong.getMusicTitle() == songName && foundPlaylist.getPlaylistName() == playlistName)
        {
            mainSystem.addSongToPlaylist(foundSong, foundPlaylist);
        }
    }
    else
    {
        std::cout << std::endl;
        std::cout << "The entry cannot be left blank." << std::endl;
        std::cout << std::endl;
    }
}

void delSongSystemPlaylist(System& mainSystem) // Delete song from playlist
{
    std::string songName, playlistName;

    mainSystem.printSystemSongs(); // Print current system songs
    mainSystem.printSystemPlaylists(); // Print current system playlists

    std::cout << std::endl;

    std::cout << "Enter the song name: ";
    std::getline (std::cin, songName);

    std::cout << "Enter the playlist name: ";
    std::getline (std::cin, playlistName);

    // Check if input is valid (blank or empty)
    if (!isBlankOrSpaces(songName) && !isBlankOrSpaces(playlistName))
    {
        // Search for the song and playlist on the system
        Music foundSong = mainSystem.searchSongByName(songName);
        Playlist foundPlaylist = mainSystem.searchPlaylistByName(playlistName);

        // Remove the song from the playlist if it exists
        if (foundSong.getMusicTitle() == songName && foundPlaylist.getPlaylistName() == playlistName)
        {
            mainSystem.removeSongFromPlaylist(foundSong, foundPlaylist);
        }
    }
    else
    {
        std::cout << std::endl;
        std::cout << "The entry cannot be left blank." << std::endl;
        std::cout << std::endl;
    }
}

void printSongsAndPlaylists(System& mainSystem) // Print all system songs and playlists
{
    mainSystem.printSystemSongs();
    mainSystem.printSystemPlaylists();
}

void printPlaylistsSongs(System& mainSystem) // print songs from a playlist
{
    std::string playlistName;

    mainSystem.printSystemPlaylists(); // Print current system playlists

    std::cout << std::endl;
    std::cout << "Enter the playlist name: ";
    std::getline (std::cin, playlistName);

    // Check if input is valid (blank or empty)
    if (!isBlankOrSpaces(playlistName))
    {
        // Search for the playlist on the system
        Playlist foundPlaylist = mainSystem.searchPlaylistByName(playlistName);

        // Print the songs from the playlist if it exists
        if (foundPlaylist.getPlaylistName() == playlistName)
        {
            std::cout << std::endl;
            foundPlaylist.listSongs();
        }
    }
    else
    {
        std::cout << std::endl;
        std::cout << "The entry cannot be left blank." << std::endl;
        std::cout << std::endl;
    }
}

void playSong(System& mainSystem)
{
    std::string playlistName;
    int durationInSeconds = 20;

    mainSystem.printSystemPlaylists(); // Print current system playlists

    std::cout << std::endl;

    std::cout << "Enter the playlist name: ";
    std::getline(std::cin, playlistName);

    std::cout << std::endl;

    // Check if input is valid (blank or empty)
    if (isBlankOrSpaces(playlistName))
    {
        std::cout << "The entry cannot be left blank." << std::endl;
        return;
    }

    // Search for the playlist on the system
    Playlist foundPlaylist = mainSystem.searchPlaylistByName(playlistName);

    // Check if the founded playlist is equal to the input playlist
    if (foundPlaylist.getPlaylistName() != playlistName)
    {
        std::cout << "Playlist not found." << std::endl;
        return;
    }

    // Loop through the playlist songs
    for (Music& song : foundPlaylist.getSongs())
    {
        std::cout << "Now playing: " << song.getMusicTitle() << " [ ";
        std::cout.flush();

        // Display the progress bar
        for (int i = 0; i <= 20; ++i)
        {
            std::cout << "\u2588";
            std::cout.flush();

            std::this_thread::sleep_for(std::chrono::milliseconds((durationInSeconds * 1000) / 20));
        }

        std::cout << " ] ";

        std::cout << "\033[2K\r"; // Clean up the progress bar
    }
}

bool isBlankOrSpaces(const std::string& input) // Check if the input is black or empty
{
    return input.empty() || std::all_of(input.begin(), input.end(), [](char c) { return std::isspace(static_cast<unsigned char>(c)); });
}

void clearScreen() // Clean up the screen content
{
    #ifdef _WIN32
        std::system("cls"); // For Windows
    #else
        std::system("clear"); // For Unix/Linux
    #endif
}

int getTermWidth() // Gets the current terminal width
{
    #ifdef _WIN32
        CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
            return csbi.srWindow.Right - csbi.srWindow.Left + 1;
    #else
        struct winsize size{};
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
        return size.ws_col;
    #endif
}

void printHeader() // Print the program header
{
    std::string header = "PLAYLIST MANAGER"; // Program title
    std::string subheader = "Project By - Breno Barbosa de Oliveira"; // My name :)
    auto terminal_width = static_cast<size_t>(getTermWidth());

    // Print a centralized title
    std::ostringstream line;
    line << std::setfill('-') << std::setw(static_cast<int>(terminal_width)) << "";
    std::cout << line.str() << std::endl;

    std::cout << std::setfill(' ') << std::setw(static_cast<int>((terminal_width + header.length()) / 2)) << header << std::endl;
    std::cout << line.str() << std::endl;

    std::cout << std::setfill(' ') << std::setw(static_cast<int>((terminal_width + subheader.length()) / 2)) << subheader << std::endl;
    std::cout << line.str() << std::endl;

    std::cout << std::endl;
}

void printFunctionHeader(const std::string& funcName) // Prints the current function header
{
    int termWidth = getTermWidth(); // Terminal width
    int headerWidth = static_cast<int>(funcName.size()) + 4; // Header width

    int leftSpaces = std::floor((termWidth - headerWidth) / 2.0); // Left spaces
    int rightSpaces = termWidth - headerWidth - leftSpaces; // Right spaces

    // Print a centralized title
    std::cout << std::string(termWidth, '=') << std::endl;
    std::cout << std::string(leftSpaces, ' ') << funcName << std::string(rightSpaces, ' ') << std::endl;
    std::cout << std::string(termWidth, '=') << std::endl;
    std::cout << std::endl;
}

void runMenu(System& mainSystem) // System menu
{
    int choice; // User choice

    do
    {
        clearScreen();
        printHeader();

        // ----------------- Options -------------------

        std::cout << std::endl;
        std::cout << "1. Add Song to System" << std::endl;
        std::cout << "2. Delete Song from System" << std::endl;
        std::cout << "3. Add Playlist to System" << std::endl;
        std::cout << "4. Delete Playlist from System" << std::endl;
        std::cout << "5. Add Song to Playlist" << std::endl;
        std::cout << "6. Delete Song from Playlist" << std::endl;
        std::cout << "7. Print Songs and Playlists" << std::endl;
        std::cout << "8. Print Playlist Songs" << std::endl;
        std::cout << "9. Run Playlist" << std::endl;
        std::cout << "0. Quit" << std::endl;
        std::cout << std::endl;

        std::cout << "Enter your choice: ";

        bool validInput = false; // Input status

        // while the input is invalid
        while (!validInput)
        {
            // check if the input is valid
            if (!(std::cin >> choice) || choice < 0 || choice > 9)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "\033[A\033[K"; // Clean up the line
                std::cout << "Invalid input. Please enter a valid choice: ";
            }
            else
            {
                validInput = true;
            }
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        clearScreen();

        // ----------------- Execute functions -------------------

        switch (choice)
        {
            case 1:
                printFunctionHeader("ADD SONG TO SYSTEM");
                addSongSystem(mainSystem);
                break;
            case 2:
                printFunctionHeader("DELETE SONG FROM SYSTEM");
                delSongSystem(mainSystem);
                break;
            case 3:
                printFunctionHeader("ADD PLAYLIST TO SYSTEM");
                addPlaylistSystem(mainSystem);
                break;
            case 4:
                printFunctionHeader("DELETE PLAYLIST FROM SYSTEM");
                delPlaylistSystem(mainSystem);
                break;
            case 5:
                printFunctionHeader("ADD SONG TO PLAYLIST");
                addSongSystemPlaylist(mainSystem);
                break;
            case 6:
                printFunctionHeader("DELETE SONG FROM PLAYLIST");
                delSongSystemPlaylist(mainSystem);
                break;
            case 7:
                printFunctionHeader("SYSTEM SONGS AND PLAYLISTS");
                printSongsAndPlaylists(mainSystem);
                break;
            case 8:
                printFunctionHeader("PLAYLIST SONGS");
                printPlaylistsSongs(mainSystem);
                break;
            case 9:
                printFunctionHeader("RUN PLAYLIST");
                playSong(mainSystem);
                break;
            case 0:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }

        std::cout << std::endl;
        std::cout << "Press Enter to return to the menu " << "\u21B5 ";

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        clearScreen();
    }
    while (choice != 0);
}
