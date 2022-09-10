//
//  main.cpp
//  Main Lab 8: Playlist
//
//  Created by Ryn Stroud on 11/16/19.
//  Copyright © 2019 Ryn Stroud. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>

#include "Playlist.h"
#include "Song.h"

using namespace std;
    
void DisplayMenu() {
    cout << "add\t\tAdds a list of songs to the library\n";
    cout << "list\tLists all the songs in the library\n";
    cout << "addp\tAdds a new playlist\n";
    cout << "addsp\tAdds a song to a playlist\n";
    cout << "listp\tLists all the playlists\n";
    cout << "play\tPlays a playlist\n";
    cout << "remp\tRemoves a playlist\n";
    cout << "remsp\tRemoves a song from a playlist\n";
    cout << "remsl\tRemoves a song from the library (and all playlists)\n";
    cout << "options\tPrints this options menu\n";
    cout << "quit\tQuits the program\n\n";
}

void ListPlaylists(vector<Playlist> playlistList) {
    for (int i = 0; i < playlistList.size(); ++i) {
        cout << endl << i << ": " << playlistList.at(i).GetName() << endl;
    }
}

int ChoosePlaylist(vector<Playlist> playlistList, string playlistPrompt) {
    int playlistIndex = 0;
    
    ListPlaylists(playlistList);
    cout << playlistPrompt;
    cin >> playlistIndex;
    cin.ignore();
    cout << endl;
    
    return playlistIndex;
}

void AddSongs(vector<Song*>& songList) { //adds songs to the library
    Song* newSong = nullptr;
    const string END_LOOP = "STOP";
    string songTitle = "unassigned";
    string songFirstLine = "unassigned";
    
    cout << "Read in Song names and first lines (type \"" << END_LOOP << "\" when done): \n";
    while ((songTitle != END_LOOP) && (songFirstLine != END_LOOP)) {
        cout << "\nSong Name: ";
        getline(cin, songTitle);
        if (songTitle == END_LOOP) {
            break;
        }
        cout << "\nSong's first line: ";
        getline(cin, songFirstLine);
        newSong = new Song(songTitle, songFirstLine);
        songList.push_back(newSong);
    }
    
}

void ListAllSongs(const vector<Song*> songList) {
    for (int i = 0; i < songList.size(); ++i) {
        cout << endl << songList.at(i)->GetTitle() << ": \"";
        cout << songList.at(i)->GetFirstLine() << "\", " << songList.at(i)->GetTimesPlayed() << " play(s).\n";
    }
}

void AddPlaylist(vector<Playlist>& playlistList) {
    string playlistName = "unassigned";
    Playlist newPlaylist;
    cout << "\nPlaylist name: ";
    getline(cin, playlistName);
    newPlaylist.SetName(playlistName);
    playlistList.push_back(newPlaylist);
}

void AddSongToPlaylist(vector<Playlist>& playlistList, vector<Song*>&  songList) {
    int songIndex = 0;
    int playlistIndex = ChoosePlaylist(playlistList, "\nPick a playlist index number: ");
    for (int i = 0; i < songList.size(); ++i) {
        cout << endl << setw(3) << i << ": " << songList.at(i)->GetTitle() << endl;
    }
    cout << "\nPick a song index number: ";
    cin >> songIndex;
    cin.ignore();
    playlistList.at(playlistIndex).AddSongToPlaylist(songList.at(songIndex));
}

void RemovePlaylist(vector<Playlist>& playlistList, int playlistIndex) {
    playlistList.erase(playlistList.begin() + playlistIndex);
}

void RemoveSong(vector<Song*>& songList, vector<Playlist>& playlistList) { //removes song from library
    int songIndex = 0;
    for (int i = 0; i < songList.size(); ++i) {
        cout << endl << setw(3) << i << ": " << songList.at(i)->GetTitle() << endl;
    }
    cout << "Pick a song index number to remove: ";
    cin >> songIndex;
    cin.ignore();
    for (int i = 0; i < playlistList.size(); i++) {
        playlistList.at(i).AutoRemoveSong(songList.at(songIndex)->GetTitle());
    }
    delete songList.at(songIndex); //frees memory of the song
    songList.erase(songList.begin() + songIndex);
}

void DeleteEverything(vector<Song*>& songList) { //called at end of main
    for (int i = 0; i < songList.size(); i++) {
        delete songList.at(i);  //frees all remaining memory
    }
    for (int i = 0; i < songList.size(); i++) {
        songList.erase(songList.begin() + i - i/2);
    }
}

int main() {
    const string ADD_LIST = "add";
    const string LIST_SONGS = "list";
    const string ADD_PLAYLIST = "addp";
    const string ADD_SONG = "addsp";
    const string LIST_PLAYLISTS = "listp";
    const string PLAY_PLAYLIST = "play";
    const string REMOVE_PLAYLIST = "remp";
    const string TEMP_REMOVE_SONG = "remsp";
    const string REMOVE_SONG = "remsl";
    const string SHOW_OPTIONS = "options";
    const string QUIT = "quit";
    const string PLAYLIST_CHOOSE = "\nPick a playlist index number: ";
    vector<Song*> songs(0);
    vector<Playlist> playlist(0);
    string userChoice = "unassigned";
    string songName = "unassigned";
    int playlistIndex = 0;
    
    cout << "Welcome to the Firstline Player!  Enter options to see menu options.\n\n";
    cout << "Enter your selection now: ";
    cin >> userChoice;
    cin.ignore();
    while (userChoice != QUIT) {
        if (userChoice == ADD_LIST) {
            AddSongs(songs);
        }
        else if (userChoice == LIST_SONGS) {
            ListAllSongs(songs);
        }
        else if (userChoice == ADD_PLAYLIST) {
            AddPlaylist(playlist);
        }
        else if (userChoice == ADD_SONG) {
            AddSongToPlaylist(playlist, songs);
        }
        else if (userChoice == LIST_PLAYLISTS) {
            ListPlaylists(playlist);
        }
        else if (userChoice == PLAY_PLAYLIST) {
            playlistIndex = ChoosePlaylist(playlist, PLAYLIST_CHOOSE);
            playlist.at(playlistIndex).PlayPlayList();
        }
        else if (userChoice == REMOVE_PLAYLIST) {
            playlistIndex = ChoosePlaylist(playlist, "\nPick a playlist index number to remove: ");
            RemovePlaylist(playlist, playlistIndex);
        }
        else if (userChoice == TEMP_REMOVE_SONG) {
            playlistIndex = ChoosePlaylist(playlist, PLAYLIST_CHOOSE);
            playlist.at(playlistIndex).RemoveSongFromPlaylist();
        }
        else if (userChoice == REMOVE_SONG) {
            RemoveSong(songs, playlist);
    
        }
        else if (userChoice == SHOW_OPTIONS) {
            DisplayMenu();
        }
        else if (userChoice == QUIT) {
            break;
        }
        else {
            DisplayMenu();
        }
        cout << "\nEnter your selection now: ";
        cin >> userChoice;
        cin.ignore();
    }
    
    DeleteEverything(songs); //frees all memory from the pointers in the song library
    
    cout << "\nGoodbye!\n";
    return 0;
}
