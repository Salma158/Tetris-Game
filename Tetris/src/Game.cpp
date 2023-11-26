#include "Game.h"
#include <graphics.h>
#include <iostream>
#include <conio.h>
#include "Block.h"
#include "Board.h"
#include <time.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
using namespace std;
void Game::initializeGame()
{
    board.initialize();
    board.drawGrid();
    Block* initialBlock = generateNewBlock();
    board.setCurrentBlock(initialBlock);
    score = 0;
}

void Game::handleInput()
{
    if (kbhit())
    {
        char c = getch();
        switch (c)
        {
        case UP:
            board.getBlock()->Rotate();
            break;
        case DOWN:
            if (board.canMovedown())
            {
                board.getBlock()->moveDown();
            }
            break;
        case LEFT:
            if (board.canMoveLeft())
            {
                board.getBlock()->moveLeft();
            }
            break;
        case RIGHT:
            if (board.canMoveRight())
            {
                board.getBlock()->moveRight();
            }
            break;
        }
        board.UpdateBoard();
        board.getBlock()->drawBlock();
    }
}

void Game::updateGame()
{
    if (board.havetoMerge() || !board.getBlock()->canMoveDown())
    {
        board.mergeBlock();
        Block* newBlock = generateNewBlock();
        board.setCurrentBlock(newBlock);
        if (board.havetoMerge())
        {
            endGame();
        }
    }

    static int timer=0;
    delay(2);
    timer++;
    if (timer == 30)
    {
        timer = 0;
        board.getBlock()->moveDown();
        board.UpdateBoard();
        board.getBlock()->drawBlock();
    }


    int linesClearedScore = board.findWholeLines();
    score += linesClearedScore;
}

void Game::endGame()
{
    cleardevice();
    setcolor(WHITE);
    char str[20];
    sprintf(str, "Your score is : %d", score);
    outtextxy(10, 10, str);
    outtextxy(10, 30, "Do you want to play again? (y/n): ");

    char playAgain = getch();
    if (playAgain != 'y' && playAgain != 'Y')
    {
        closegraph();
        exit(0);
    }
    else
    {
        cleardevice();
        initializeGame();
    }
}


Game::Game()
{
    initwindow(300, 600, "Tetris");
    initializeGame();
}

void Game::run()
{
    while (1)
    {
        handleInput();
        updateGame();
    }
}

Block* Game::generateNewBlock()
{
    srand(time(NULL));
    Block* newBlock;
    int choice = rand() % 7;
    switch (choice)
    {
    case 0:
        newBlock = new LBlock;
        break;
    case 1:
        newBlock = new IBlock;
        break;
    case 2:
        newBlock = new JBlock;
        break;
    case 3:
        newBlock = new TBlock;
        break;
    case 4:
        newBlock = new OBlock;
        break;
    case 5:
        newBlock = new SBlock;
        break;
    case 6:
        newBlock = new ZBlock;
        break;
    }
    return newBlock;
}

