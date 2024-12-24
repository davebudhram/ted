#ifndef CURSOR_H
#define CURSOR_H
#include "./GapBuffer.h"

class Cursor {
    public: 
        Cursor(GapBuffer& gapBuffer) : gb(gapBuffer) {} 
        void moveUp();
        void moveDown();
        void moveRight();
        void moveLeft();
        void setPosition(int line, int column);
    private:
        GapBuffer& gb;
        int row;
        int col;
};

#endif
