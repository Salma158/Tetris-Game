#ifndef BLOCKS_H
#define BLOCKS_H
#include "Block.h"

class IBlock : public Block
{
public:
    IBlock();
};

class JBlock : public Block
{
public:
    JBlock();
};

class LBlock : public Block
{
public:
    LBlock();
};

class OBlock : public Block
{
public:
    OBlock();
};

class SBlock : public Block
{
public:
    SBlock();
};

class TBlock : public Block
{
public:
    TBlock();
};

class ZBlock : public Block
{
public:
    ZBlock();
};
#endif // BLOCKS_H
