//
//  Song.cpp
//  Main Lab 8: Playlist
//
//  Created by Ryn Stroud on 11/16/19.
//  Copyright © 2019 Ryn Stroud. All rights reserved.
//
#include <iostream>
#include <vector>
#include <string>

#include "Song.h"

using namespace std;

Song::Song() {
    title = "Unknown";
    firstLine = "Unknown";
    timesPlayed = 0;
}
Song::Song(string title, string firstLine, int timesPlayed) { 
    this->title = title;
    this->firstLine = firstLine;
    this->timesPlayed = timesPlayed;
}

void Song::SetTitle(string title) {
    this->title = title;
}
void Song::SetFirstLine(string firstLine) {
    this->firstLine = firstLine;
}
void Song::IncTimesPlayed() {
    ++timesPlayed;
}
string Song::GetTitle() {
    return title;
}
string Song::GetFirstLine() {
    return firstLine;
}
void Song::PrintFirstLine() {
    cout << firstLine;
}
int Song::GetTimesPlayed() {
    return timesPlayed;
}
