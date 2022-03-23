/***********************************************************************************************
 *   Authors:     Anthony Swank, Duy Nguyen, Julian Rose, and Rosario Sainz
 *   File:        main.cpp
 *   Course:      CS 7B
 *   Assignment:  Project 2B: Playlist Program
 *   Date:        3-23-2022
 ***********************************************************************************************/

#include <iostream>
#include <vector>
#include "PlaylistNode.h"
using namespace std;

void PrintMenu(string &playListName) {
    cout << playListName << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl << endl;
}

void ExecuteMenu(char &option, string &playListName, PlaylistNode* &headNode) {
    string addTitle;
    string addLength;
    string addArtist;
    string addID;
    int addTimeLength;
    int nCount = 1;

    PlaylistNode* currNode = nullptr;
    PlaylistNode* lastNode = nullptr;
    PlaylistNode* tempPrevNode = nullptr;

    lastNode = headNode;

    switch (option) {
    case 'a': {
        cin.ignore();
        cout << "ADD SONG" << endl;
        cout << "Enter song's unique ID:" << endl;
        getline(cin, addID);
        cout << "Enter song's name:" << endl;
        getline(cin, addTitle);
        cout << "Enter artist's name:" << endl;
        getline(cin, addArtist);
        cout << "Enter song's length (in seconds):" << endl;
        cin >> addTimeLength;

        currNode = new PlaylistNode(addID, addTitle, addArtist, addTimeLength);
        lastNode->InsertAfter(currNode);
        lastNode = currNode;
        cin.clear();
        break;
    }
    case 'o': {
        cout << playListName << " - OUTPUT FULL PLAYLIST" << endl;

        currNode = headNode->GetNext();

        if (currNode == nullptr) {
            cout << "Playlist is empty" << endl;
            cout << endl;
        }
        else {
            vector<PlaylistNode*> node;

            while (currNode != nullptr) {
                node.push_back(currNode);
                currNode = currNode->GetNext();
            }

            for (int i = node.size() - 1; i >= 0; i--) {
                cout << nCount << "." << endl;
                node.at(i)->PrintPlaylistNode();
                nCount++;
            }
        }
        break;
    }
    case 's': {
        cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
        cout << "Enter artist's name:" << endl << endl;
        cin.ignore();
        getline(cin, addArtist);

        currNode = headNode->GetNext();

        if (currNode == nullptr) {
            cout << playListName << " - OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
        }
        else {
            nCount = 1;

            vector<PlaylistNode*> node;

            while (currNode != nullptr) {
                node.push_back(currNode);
                currNode = currNode->GetNext();
            }

            for (int i = node.size() - 1; i >= 0; i--) {
                if (node.at(i)->GetArtistName() == addArtist) {
                    cout << nCount << "." << endl;
                    node.at(i)->PrintPlaylistNode();
                }
                nCount++;
            }
        }
        break;
    }
    case 'd': {
        cout << "REMOVE SONG" << endl;
        cout << "Enter song's unique ID:" << endl;
        cin.ignore();
        getline(cin, addID);

        currNode = headNode->GetNext();
        while (currNode != nullptr) {
            if (currNode->GetID() == addID) {
                cout << "\"" << currNode->GetSongName() << "\" removed.\n" << endl;
                currNode->SetNext(tempPrevNode);
                currNode = nullptr;
                delete currNode;
                break;
            }
            tempPrevNode = currNode;
            currNode = currNode->GetNext();
        }
        break;
    }
    case 't': {
        int totalTime = 0;
        cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;

        currNode = headNode;

        while (currNode != nullptr) {
            totalTime += currNode->GetSongLength();
            currNode = currNode->GetNext();
        }
        cout << "Total time: " << totalTime << " seconds" << endl;
        cin.clear();
        break;
    }
    case 'q': {
        exit(0);
        break;
    }
    default: {
        break;
    }
    }
}

int main() {
    string playListName;
    char option = 'a';

    PlaylistNode* headNode;

    headNode = new PlaylistNode();

    cout << "Enter playlist's title:" << endl << endl;
    getline(cin, playListName);

    while (option != 'q') {
        PrintMenu(playListName);
        cout << "Choose an option:" << endl;
        cin >> option;
        if (option != 'q') {
            ExecuteMenu(option, playListName, headNode);
        }
    }

    return 0;
}