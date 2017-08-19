//
// Created by miguel on 11/08/17.
//

#include <cstdlib>
#include <iostream>
#include "gameOf2048.h"

using namespace std;

gameOf2048::gameOf2048() {
    for (int i = 0; i < numberOfInitialTiles; ++i) {
        this->addRandomTile();
    }
}


//Updates the state of the game
//Return 1 if something went wrong, otherwise 0

int gameOf2048::updateGame() {

    //Fail safe
    if (this->isFinish){
        return 1;
    }
    int decision = makePlayerChoose();
    makeMove( decision );
    addRandomTile();
    printboard();
    return 0;
}

void gameOf2048::addRandomTile() {
    int x, y;
    while(true) {

        x = rand() % sizeOfBoard;
        y = rand() % sizeOfBoard;

        if (cells[x][y].isEmpty) {
            cells[x][y].fill();
            break;
        }
    }
}

int gameOf2048::makePlayerChoose() {
    cout << "==================================" << endl;
    cout << "      Choose your next Move       " << endl;
    cout << "==================================" << endl;
    cout << "1) Swipe Right" << endl;
    cout << "2) Swipe Left" << endl;
    cout << "3) Swipe Up" << endl;
    cout << "4) Swipe Down" << endl;
    cout << "My decision = ";

    unsigned int decision;
    cin >> decision;

    //TODO for some reason if I input text into decision it loops indefinetly ??
    // I rather make the input unbuffered
    //Check if input is valid
    while( !(decision == 1 || decision == 2 || decision == 3 || decision == 4) ){
        cout << "Please select a valid option: ";
        cin >> decision;
    }

    return decision;
}

void gameOf2048::makeMove(int decision) {

    switch (decision){
        case 1:
            //For loop through rows
            for (int i = 0; i < sizeOfBoard; ++i) pushRowAscending(i);
            break;
        case 2:
            //For loop through rows
            for (int i = 0; i < sizeOfBoard; ++i) pushRowDescending(i);
            break;
        case 3:
            //For loop through columns
            for (int i = 0; i < sizeOfBoard; ++i) pushColumnDescending(i);
            break;
        case 4:
            //For loop through columns
            for (int i = 0; i < sizeOfBoard; ++i) pushColumnAscending(i);
            break;
        default:
            break;
    }
}

int gameOf2048::getScore() const {
    return score;
}

void gameOf2048::printboard() {
    //TODO Make it so it actually displays a bit better
    cout << endl << endl;

    printf("-----------------\n");
    for (auto &row : cells) {
        for (auto &index : row) {
            if (index.isEmpty) {
                printf("|  0");
            } else {
                printf("|%3d", index.value);
            }
        }
        printf("|\n");
        printf("-----------------\n");
    }

    cout << "Current Score= " <<this->getScore() << endl;
}


//Control of the Game
void gameOf2048::pushRowAscending(int row) {
    int lastToBeMerged = sizeOfBoard-1;

    for (int i = sizeOfBoard-2 ; i >= 0 ; i--) {
        if (cells[row][i].isEmpty)continue;
        if (cells[row][lastToBeMerged].isEmpty) {
            cells[row][lastToBeMerged] = cells[row][i];
            cells[row][i].isEmpty = true;
        } else if (cells[row][lastToBeMerged].value == cells[row][i].value){
            cells[row][lastToBeMerged].value *= 2;
            cells[row][i].isEmpty = true;
            score += cells[row][lastToBeMerged].value;
            lastToBeMerged--;
        } else if (lastToBeMerged-1 == i) {
            lastToBeMerged--;
        } else {
            cells[row][lastToBeMerged-1] = cells[row][i];
            cells[row][i].isEmpty = true;
            lastToBeMerged--;
        }
    }
}

void gameOf2048::pushRowDescending(int row) {
    int lastToBeMerged = 0;

    for (int i = 1 ; i < sizeOfBoard ; i++) {
        if (cells[row][i].isEmpty) continue;
        if (cells[row][lastToBeMerged].isEmpty) {
            cells[row][lastToBeMerged] = cells[row][i];
            cells[row][i].isEmpty = true;
        } else if (cells[row][lastToBeMerged].value == cells[row][i].value) {
            cells[row][lastToBeMerged].value *= 2;
            cells[row][i].isEmpty = true;
            score += cells[row][lastToBeMerged].value;
            lastToBeMerged++;
        } else if (lastToBeMerged + 1 == i) {
            lastToBeMerged++;
        } else {
            cells[row][lastToBeMerged+1] = cells[row][i];
            cells[row][i].isEmpty = true;
            lastToBeMerged++;
        }
    }
}

void gameOf2048::pushColumnAscending(int column) {
    int lastToBeMerged = sizeOfBoard-1;

    for (int i = sizeOfBoard-2 ; i >= 0 ; i--) {
        if (cells[i][column].isEmpty) continue;
        if (cells[lastToBeMerged][column].isEmpty) {
            cells[lastToBeMerged][column] = cells[i][column];
            cells[i][column].isEmpty = true;
        } else if (cells[lastToBeMerged][column].value == cells[i][column].value){
            cells[lastToBeMerged][column].value *= 2;
            cells[i][column].isEmpty = true;
            score += cells[lastToBeMerged][column].value;
            lastToBeMerged--;
        } else if (lastToBeMerged-1 == i){
            lastToBeMerged--;
        } else {
            cells[lastToBeMerged-1][column] = cells[i][column];
            cells[i][column].isEmpty = true;
            lastToBeMerged--;
        }
    }
}

void gameOf2048::pushColumnDescending(int column) {
    int lastToBeMerged = 0;

    for (int i = 1 ; i < sizeOfBoard ; i++) {
        if (cells[i][column].isEmpty) continue;
        if (cells[lastToBeMerged][column].isEmpty) {
            cells[lastToBeMerged][column] = cells[i][column];
            cells[i][column].isEmpty = true;
        } else if (cells[lastToBeMerged][column].value == cells[i][column].value){
            cells[lastToBeMerged][column].value *= 2;
            cells[i][column].isEmpty = true;
            score += cells[lastToBeMerged][column].value;
            lastToBeMerged++;
        } else if (lastToBeMerged+1 == i) {
            lastToBeMerged++;
        }else {
            cells[lastToBeMerged+1][column] = cells[i][column];
            cells[i][column].isEmpty = true;
            lastToBeMerged++;
        }
    }
}
