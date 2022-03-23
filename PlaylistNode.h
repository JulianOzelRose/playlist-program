/***********************************************************************************************
 *   Authors:     Anthony Swank, Duy Nguyen, Julian Rose, and Rosario Sainz
 *   File:        PlaylistNode.h
 *   Course:      CS 7B
 *   Assignment:  Project 2B: Playlist Program
 *   Date:        3-23-2022
 ***********************************************************************************************/

#ifndef PlaylistNode_cpp
#define PlaylistNode_cpp
#include <iostream>
#include <string>

using namespace std;

class PlaylistNode {
public:
    PlaylistNode();
    PlaylistNode(string songID, string songtitle, string songArtist, int songPlaytime);
    void InsertAfter(PlaylistNode* nodeLoc);
    void SetNext(PlaylistNode* nextNode);
    void PrintPlaylistNode();
    string GetID() const;
    string GetSongName() const;
    string GetArtistName() const;
    int GetSongLength() const;
    PlaylistNode* GetNext() const;
private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
};

#endif