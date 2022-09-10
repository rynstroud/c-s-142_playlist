//
//  Song.h
//  Main Lab 8: Playlist
//
//  Created by Ryn Stroud on 11/16/19.
//  Copyright © 2019 Ryn Stroud. All rights reserved.
//

#ifndef Song_h
#define Song_h
#include <iostream>

using namespace std;

class Song {
public:
    Song();
    Song(string title, string firstLine, int timesPlayed = 0);
    void SetTitle(string title);
    void SetFirstLine(string firstLine);
    void IncTimesPlayed();
    string GetTitle();
    string GetFirstLine();
    void PrintFirstLine();
    int GetTimesPlayed();
private:
    string title;
    string firstLine;
    int timesPlayed;
};

#endif /* Song_h */
