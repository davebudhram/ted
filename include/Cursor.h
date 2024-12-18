#ifndef CURSOR_H
#define CURSOR_H

class Cursor {
    public: 
        Cursor();
        void moveUp();
        void moveDown();
        void setPosition(int line, int column);
    private:
        int row;
        int col;
};

#endif
