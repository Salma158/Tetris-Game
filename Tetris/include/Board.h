#ifndef BOARD_H
#define BOARD_H
#define ROW 20
#define COL 10
#define CELL 30
#include "Block.h"
class Board
{
protected:
    int board[ROW][COL];
    Block* block;
public:
    Board();
    Block * getBlock();
    void initialize();
    void print();
    void drawGrid();
    void setCurrentBlock(Block * _block);
    int havetoMerge();
    void mergeBlock();
    void UpdateBoard();
    int canMoveLeft();
    int canMoveRight();
    int findWholeLines();
    int canMovedown();
};

#endif // BOARD_H
