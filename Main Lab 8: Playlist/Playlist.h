//
//  Playlist.h
//  Main Lab 8: Playlist
//
//  Created by Ryn Stroud on 11/16/19.
//  Copyright © 2019 Ryn Stroud. All rights reserved.
//
#ifndef Playlist_h
#define Playlist_h

#include <iostream>
#include "Song.h"

using namespace std;

class Playlist {
public:
    Playlist();
    Playlist(string playlistName);
    void SetName(string name);
    string GetName();
    void AddSongToPlaylist(Song* songPointer);
    void RemoveSongFromPlaylist();
    void ListSongsInPlaylist();
    void PlayPlayList();
    void AutoRemoveSong(string songName);
private:
    string playlistName;
    vector<Song*> playlistSongs;
};

#endif /* Playlist_h */
