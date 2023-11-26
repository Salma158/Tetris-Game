#ifndef GAME_H
#define GAME_H
#include <graphics.h>
#include <iostream>
#include <conio.h>
#include "Block.h"
#include <Blocks.h>
#include "Board.h"
#include <time.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77


class Game
{
    private:
        Board board;
        int score;
    public:
        Game();
        void initializeGame();
        void handleInput();
        void updateGame();
        void endGame();
        void run();
        Block* generateNewBlock();
};

#endif // GAME_H
