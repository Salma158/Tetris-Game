#ifndef BLOCK_H
#define BLOCK_H
#define SIDE 4
#define CELL 30

class Block
{
public:
    Block();
    void transpose();
    void Reverse();
    int Rotate();
    int moveRight();
    int moveLeft();
    int moveDown();
    void drawBlock();
    int getMatrixValue(int i, int j);
    int getRowOffset();
    int getColOffset();
    int canMoveDown();

protected:
    int matrix[SIDE][SIDE];
    int rowOffset;
    int colOffset;

};
#endif // BLOCK_H
