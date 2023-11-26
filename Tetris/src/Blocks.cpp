#include "Blocks.h"
#include "Block.h"
IBlock::IBlock()
{
    matrix[0][1] = matrix[1][1] = matrix[2][1] = matrix[3][1] = 7;
}

OBlock::OBlock()
{
    matrix[0][1] = matrix[0][2] = matrix[1][1] = matrix[1][2] = 9;
}

SBlock::SBlock()
{
    matrix[0][1] = matrix[0][2] = matrix[1][0] = matrix[1][1] = 10;
}

TBlock::TBlock()
{
    matrix[0][0] = matrix[0][1] = matrix[0][2] = matrix[1][1] = 14;
}

ZBlock::ZBlock()
{
    matrix[0][0] = matrix[0][1] = matrix[1][1] = matrix[1][2] = 12;
}

JBlock::JBlock()
{
    matrix[0][0] = matrix[0][1] = matrix[0][2] = matrix[1][2] = 13;
}

LBlock::LBlock()
{
    matrix[0][0] = matrix[0][1] = matrix[0][2] = matrix[1][0] = 11;
}
