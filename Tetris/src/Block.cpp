#include <graphics.h>
#include "Block.h"
#define SIDE 4
#define CELL 30
#define WIDTH 10
#define HEIGHT 20
Block::Block()
{
    rowOffset= 0;
    colOffset= 3;
    for (int i = 0; i < SIDE; ++i)
    {
        for (int j = 0; j < SIDE; ++j)
        {
            matrix[i][j] = 0;
        }
    }
}


void Block::transpose()
{
    for (int i = 0; i < SIDE; i++)
    {
        for (int j = i + 1; j < SIDE; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}
void Block::Reverse()
{
    for (int i = 0; i < SIDE; i++)
    {
        int Start = 0;
        int End = SIDE - 1;
        while (Start < End)
        {
            int temp = matrix[i][Start];
            matrix[i][Start] = matrix[i][End];
            matrix[i][End] = temp;
            Start++;
            End--;
        }
    }
}
int Block::Rotate()
{
    transpose();
    Reverse();

    for(int i=0; i<SIDE; i++)
    {
        for(int j=0; j<SIDE; j++)
        {
            if( (colOffset+j > WIDTH-1 || colOffset+j < 0 ||  rowOffset+i > HEIGHT-1) && matrix[i][j])
            {
                Reverse();
                transpose();
                return 0;
            }
        }
    }
    return 1;
}


int Block::moveRight()
{
    for(int i=0; i<SIDE; i++)
    {
        for(int j=0; j<SIDE; j++)
        {
            if( colOffset+1+j > WIDTH-1 && matrix[i][j] )
            {
                return 0;
            }
        }
    }
    colOffset++;
    return 1;
}

int Block::moveLeft()
{
    for(int i=0; i<SIDE; i++)
    {
        for(int j=0; j<SIDE; j++)
        {
            if( colOffset-1+j < 0 && matrix[i][j])
            {
                return 0;
            }
        }
    }
    colOffset--;
    return 1;
}

int Block::moveDown()
{
    if(canMoveDown())
    {
        rowOffset++;
    }
}

int Block::canMoveDown()
{
    for(int i=0; i<SIDE; i++)
    {
        for(int j=0; j<SIDE; j++)
        {
            if( rowOffset+j > HEIGHT-1 && matrix[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}


void Block::drawBlock()
{
    for(int row = 0; row < 4; row++)
    {
        for(int col = 0; col < 4; col++)
        {

            if(matrix[row][col])
            {
                int left = (col + colOffset) * CELL;
                int top = (row + rowOffset) * CELL;
                int right = left + CELL;
                int bottom = top + CELL;
                int cellValue = matrix[row][col];
                setfillstyle(SOLID_FILL, cellValue);
                rectangle(left, top, right, bottom);
                floodfill(left + 1, top + 1, WHITE);

            }
        }
    }
}

int Block::getMatrixValue(int i, int j)
{
    return matrix[i][j];
}

int Block::getRowOffset()
{
    return rowOffset;
}

int Block::getColOffset()
{
    return colOffset;
}

