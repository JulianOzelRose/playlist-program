/***********************************************************************************************
 *   Authors:     Anthony Swank, Duy Nguyen, Julian Rose, and Rosario Sainz
 *   File:        PlaylistNode.cpp
 *   Course:      CS 7B
 *   Assignment:  Project 2B: Playlist Program
 *   Date:        3-23-2022
 ***********************************************************************************************/

#include "PlaylistNode.h"

PlaylistNode::PlaylistNode() {
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = 0;
}

PlaylistNode::PlaylistNode(string songID, string songtitle, string songArtist, int songPlaytime) {
    this->uniqueID = songID;
    this->songName = songtitle;
    this->artistName = songArtist;
    this->songLength = songPlaytime;
    this->nextNodePtr = 0;
}

void PlaylistNode::InsertAfter(PlaylistNode* nodeLoc) {
    PlaylistNode* tmpNext;
    tmpNext = this->nextNodePtr;
    this->nextNodePtr = nodeLoc;
    nodeLoc->nextNodePtr = tmpNext;
}

void PlaylistNode::SetNext(PlaylistNode* nextNode) {
    PlaylistNode* playNext = nullptr;
    playNext = this->nextNodePtr;
    this->nextNodePtr = nextNode;
    nextNode->nextNodePtr = playNext;
}

string PlaylistNode::GetID() const {
    return uniqueID;
}

string PlaylistNode::GetSongName() const {
    return songName;
}

string PlaylistNode::GetArtistName() const {
    return artistName;
}

int PlaylistNode::GetSongLength() const {
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() const {
    return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << this->uniqueID << endl;
    cout << "Song Name: " << this->songName << endl;
    cout << "Artist Name: " << this->artistName << endl;
    cout << "Song Length (in seconds): " << this->songLength << endl;
}