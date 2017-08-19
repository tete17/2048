#include <iostream>
#include "gameOf2048.h"

int main(){
    std::cout << "Hello, World!" << std::endl;

    gameOf2048 currentGame;
    currentGame.printboard();

    while (!currentGame.isFinish){
        currentGame.updateGame();
    }

    return 0;
}