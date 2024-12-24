#include "../include/Cursor.h" 
#include "../include/GapBuffer.h" 
#include <iostream>

// These functions are very basic and dont ahve the correct functionality yet
// We need to check if we can move down or right based on the gap buffer
// These are simple functions to just move it when inserting and deleting characters
// When we are not inserting or deleting we will need checks
// Feels like the checks can be ineffeicient
void Cursor::moveUp() {
    this->row -= 1;
}

void Cursor::moveDown() {
    this->row += 1;
}

void Cursor::moveRight() {
    this->col += 1;
}

void Cursor::moveLeft() {
    this->col -= 1;

}

void Cursor::setPosition(int line, int column) {

}