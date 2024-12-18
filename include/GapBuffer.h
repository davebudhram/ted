#ifndef GAPBUFFER_H
#define GAPBUFFER_H

#include <vector>
#include <string>

class GapBuffer {
public:
    GapBuffer(size_t initial_size = 100);
    void moveGap(int cursor); // Move the gap to the left or to the right
    void insert(const std::string& input, int cursor);
    std::string bufferText();
    void grow();
    std::vector<char> buffer; // This is our gap buffer. It will store all of the text

private:
    int gapStart; // The starting index of the gap. The gapStart is essentially the location of the cursor
    int gapEnd; // The end of the gap. The is always the end of the gap buffer. When this gets to 
                // the size of the buffer we have to expand our vector.
    int gapSize;
    int size;
};

#endif