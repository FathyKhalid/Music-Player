#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>
#include <algorithm>
#include "Song.h"

// Functions Prototype --------------------------------------------------------------
void display_menu();
void play_current_song(const Song &song);
void display_playlist(const std::list<Song> &playlist, const Song &current_song);
// ----------------------------------------------------------------------------------

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };

    std::list<Song>::iterator current_song = playlist.begin();
    display_playlist(playlist, *current_song);
    
    char selection{};
    do {
        display_menu();
        std::cin >> selection;
        selection = std::toupper(selection);

        // Playing First Song ---------------------------------------------------------
        if (selection == 'F') {
            std::cout << "Playing first song" << std::endl;
            current_song = playlist.begin();
            play_current_song(*current_song);
        }

        // Playing Next Song
        else if (selection == 'N') {
            std::cout << "Playing next song" << std::endl;
            current_song++;
            if (current_song == playlist.end()) {
                std::cout << "Wrapping to start of playlist" << std::endl;
                current_song = playlist.begin();
            }
            play_current_song(*current_song);
        }

        // Playing Previous Song -----------------------------------------------------
        else if (selection == 'P') {
            std::cout << "Playing previous song" << std::endl;
            if (current_song == playlist.begin()) {
                std::cout << "Wrapping to end of playlist" << std::endl;
                current_song = playlist.end();
            }
            current_song--;
            play_current_song(*current_song);
        
        // Playing a Specific Song ---------------------------------------------------
        } else if (selection == 'W'){
            std::string name , artist;
            int rating;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize> ::max(), '\n');
            std::cout << "Enter song name:";
            getline(std::cin, name);
            std::cout << "Enter song artist: ";
            getline(std::cin, artist);
            std::cout << "Enter your rating (1-5): ";
            std::cin >>rating;
            std::list<Song>::iterator it = std::find(playlist.begin(),playlist.end(), Song{name, artist, rating});
            if (it == playlist.end())
            {
                std::cout<<"\nSong Not Found!"<<std::endl;
            }
            else {
                current_song = it;
                play_current_song(*current_song);
            }

        // Adding and Playing New Song -----------------------------------------------------------
        }else if (selection == 'A') {
            std::string name, artist;
            int rating;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Adding and playing new song" << std::endl;
            std::cout << "Enter song name:";
            getline(std::cin, name);
            std::cout << "Enter song artist: ";
            getline(std::cin, artist);
            std::cout << "Enter your rating (1-5): ";
            std::cin >> rating;
            auto it = std::find(playlist.begin(), playlist.end(), Song{name, artist, rating});
            if (it == playlist.end())
            {
                playlist.insert(current_song, Song{name, artist, rating});
                current_song--;
                play_current_song(*current_song);
            }
            else {
                std::cout << "\nSong Already Exist!" << std::endl;
            }

        // Displaying The Playlist --------------------------------------------------------------
        } else if (selection == 'L') {
            std::cout << std::endl;
            display_playlist(playlist, *current_song);  

        // Save a New Song at the End of Playlist -----------------------------------------------
        } else if (selection == 'S'){
            std::string name, artist;
            int rating;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize> ::max(),'\n');
            std::cout << "Adding a New Song" << std::endl;
            std::cout << "Enter song name:";
            getline(std::cin, name);
            std::cout << "Enter song artist: ";
            getline(std::cin, artist);
            std::cout << "Enter your rating (1-5): ";
            std::cin >> rating;
            auto it = std::find(playlist.begin(), playlist.end(), Song{name, artist, rating});
            if (it == playlist.end())
            {
                std::list<Song>::iterator it = playlist.end();
                playlist.insert(it,Song{name,artist,rating});
                std::cout << "\nSuccessfully Added to The Playlist!"<<std::endl;
            }
            else {
                std::cout << "\nSong Already Exist!" << std::endl;
            }
        // Quitting The Program -----------------------------------------------------------------
        } else if (selection == 'Q')
            std::cout << "Quitting" << std::endl;
        
        // Taking care of the Wrong Input ------------------------------------------------------
        else
            std::cout << "\nIllegal choice, try again...\n";
        
    } while (selection != 'Q');

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next Song" << std::endl;
    std::cout << "P - Play Previous Song" << std::endl;
    std::cout << "W - Play Specific Song" <<std::endl;
    std::cout << "A - Add and Play a New Song at Current Location" << std::endl;
    std::cout << "S - Save a New Song" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    std::cout << "Playing: " << std::endl;
    std::cout << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    for (const Song &song: playlist) {
        std::cout << song << std::endl;
    }
    std::cout << "\nCurrent song: " << std::endl;
    std::cout << current_song << std::endl;
}