//
//  Playlist.cpp
//  Main Lab 8: Playlist
//
//  Created by Ryn Stroud on 11/16/19.
//  Copyright © 2019 Ryn Stroud. All rights reserved.
//
#include <iostream>
#include <vector>
//#include <iomanip>
#include "Playlist.h"
#include "Song.h"

using namespace std;

Playlist::Playlist() {
    playlistName = "unassigned";
}

void Playlist::SetName(string name) {
    playlistName = name;
}

string Playlist::GetName() {
    return playlistName;
}

void Playlist::AddSongToPlaylist(Song* songPointer) {
    playlistSongs.push_back(songPointer);
}

void Playlist::ListSongsInPlaylist() {
    for (int i = 0; i < playlistSongs.size(); ++i) {
        cout << endl << i << ": " << playlistSongs.at(i)->GetTitle() << endl;
    }
}

void Playlist::PlayPlayList() {
    cout << "Playing first lines of playlist: " << playlistName << endl;
    for (int i = 0; i < playlistSongs.size(); ++i) {
        playlistSongs.at(i)->PrintFirstLine();
        cout << endl;
        playlistSongs.at(i)->IncTimesPlayed();
    }
}


void Playlist::RemoveSongFromPlaylist() {
    int songIndex = 0;
    ListSongsInPlaylist();
    cout << "Pick a song index number to remove: ";
    cin >> songIndex;
    cin.ignore();
    playlistSongs.erase(playlistSongs.begin() + songIndex);
}

void Playlist::AutoRemoveSong(string songName) {
    for (int i = 0; i < playlistSongs.size(); i++) {
        if (playlistSongs.at(i)->GetTitle() == songName) {
            playlistSongs.erase(playlistSongs.begin() + i);
            return;
        }
    }
}



