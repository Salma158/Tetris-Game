#include "Board.h"
#include <iostream>
#include <graphics.h>
#define HEIGHT 20
#define WIDTH 10
#define CELL 30
#define SIDE 4
#include <vector>
using namespace std;
Board::Board()
{
}
Block* Board::getBlock()
{
    return block;
}


void Board::initialize()
{
    for(int i=0; i<HEIGHT; i++)
    {
        for(int j=0; j<WIDTH; j++)
        {
            board[i][j] = 0;
        }
    }
}

int Board::canMovedown(){

for(int i=0; i<SIDE; i++)
    {
        for(int j=0; j<SIDE; j++)
        {
            if(board[block->getRowOffset()+1+i][block->getColOffset()+j] && block->getMatrixValue(i,j) )
            {
                return 0;
            }
        }
    }
    return 1;

}

void Board::drawGrid()
{
    for(int i=0; i<HEIGHT; i++)
    {
        for(int j=0; j<WIDTH; j++)
        {
            int top = i * CELL;
            int left = j * CELL;
            int right = left + CELL;
            int bottom = top + CELL;

            setfillstyle(SOLID_FILL,0);
            rectangle(left, top, right, bottom);
            floodfill(left+1, top+1, WHITE);

        }
    }
}

void Board::setCurrentBlock(Block * _block)
{
    block = _block;
}

int Board::canMoveLeft()
{
    for(int i=0; i<SIDE; i++)
    {
        for(int j=0; j<SIDE; j++)
        {
            if(board[block->getRowOffset()+i][block->getColOffset()-1+j] && block->getMatrixValue(i,j) )
            {
                return 0;
            }
        }
    }
    return 1;
}

int Board::canMoveRight()
{
    for(int i=0; i<SIDE; i++)
    {
        for(int j=0; j<SIDE; j++)
        {
            if(board[block->getRowOffset()+i][block->getColOffset()+1+j] && block->getMatrixValue(i,j) )
            {
                return 0;
            }
        }
    }
    return 1;
}


int Board::havetoMerge()
{

    for(int i=0; i<SIDE; i++)
    {
        for(int j=0; j<SIDE; j++)
        {
            if(board[block->getRowOffset()+1+i][block->getColOffset()+j] &&
                    block->getMatrixValue(i,j))
            {
                return 1;
            }
        }
    }
    return 0;
}

void Board::mergeBlock()
{
    for(int i=0; i<SIDE; i++)
    {
        for(int j=0; j<SIDE; j++)
        {
            if(block->getMatrixValue(i,j))
            {
                board[block->getRowOffset() + i][block->getColOffset() + j] = block->getMatrixValue(i,j);
            }
        }
    }
}

int Board::findWholeLines()
{
    int score=0;
    vector<int> completedRows;

    for(int i=0; i<HEIGHT; i++)
    {
        int rowCompleted = 1;
        for (int j = 0; j< WIDTH; j++)
        {
            if (! board[i][j])
            {
                rowCompleted = false;
            }
        }
        if (rowCompleted)
        {
            completedRows.push_back(i);
        }
    }

    if (!completedRows.empty())
    {
        for (int r=0; r<completedRows.size(); r++)
        {
            int row = completedRows[r];

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < WIDTH; j++)
                {
                    board[row - i][j] = board[row-1 - i][j];
                }
            }
            score+=50;
        }
    }
    return score;
}

void Board::UpdateBoard()
{
    for(int i=0; i<HEIGHT; i++)
    {
        for(int j=0; j<WIDTH; j++)
        {
            int top = i * CELL;
            int left = j * CELL;
            int right = left + CELL;
            int bottom = top + CELL;

            if(board[i][j])
            {
                int cellValue = board[i][j];
                setfillstyle(SOLID_FILL,cellValue);
                rectangle(left, top, right, bottom);
                floodfill(left+1, top+1, WHITE);
            }
            else
            {
                setfillstyle(SOLID_FILL,0);
                rectangle(left, top, right, bottom);
                floodfill(left+1, top+1, WHITE);
            }
        }
    }
}
