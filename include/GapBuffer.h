#ifndef GAPBUFFER_H
#define GAPBUFFER_H

#include <vector>
#include <string>

class GapBuffer {
public:
    GapBuffer(size_t initial_size = 100);
    void moveGap(int cursor); 
    void insert(const std::string& input);
    void backspace();
    std::string bufferText();
    void grow();
    std::vector<char> buffer; 
    void cursorLeft();
    void cursorRight();
    void cursorUp();
    void cursorDown();
    int lineNum; // The current line the cursor is at
    int charWidth; // the current position on the line the cursor it at

private:
    int gapStart; // The starting index of the gap. The gapStart is essentially the location of the cursor
    int gapEnd; // The end of the gap. The is always the end of the gap buffer. When this gets to 
                // the size of the buffer we have to expand our vector.
    int gapSize;
    int size;
    int cursor;

    int currentLineCharWidth(int p); // Get the current line character width
};

#endif