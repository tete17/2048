//
// Created by miguel on 11/08/17.
//

#ifndef INC_2048_GAMEOF2048_H
#define INC_2048_GAMEOF2048_H

#define numberOfInitialTiles 3
#define sizeOfBoard 4

#include "cell.h"

class gameOf2048 {
    public:
        gameOf2048();
        bool isFinish = false;
        int updateGame();
        void printboard();
        int getScore() const;

private:
        cell cells[sizeOfBoard][sizeOfBoard];
        int score=0;
        void addRandomTile();
        int makePlayerChoose();
        void makeMove( int );



        //Control of games
        void pushRowAscending(int);
        void pushRowDescending(int);
        void pushColumnAscending(int);
        void pushColumnDescending(int);
};


#endif //INC_2048_GAMEOF2048_H
