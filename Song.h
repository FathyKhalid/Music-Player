#ifndef _SONG_H_
#define _SONG_H_
#include <iostream>
#include <list>
#include <iomanip>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating);

    std::string get_name() const;

    std::string get_artist() const;
    
    int get_rating() const;
    
    bool operator<(const Song &rhs) const;
    
    bool operator==(const Song &rhs) const;
};


#endif