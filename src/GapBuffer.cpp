#include "../include/GapBuffer.h" 
#include <iostream>

// Need to figure out how to delete. (Should we start with backspace or would a general implementation)
// Work better
 
// Constructor for the Gap Buffer. Sets the initial size. When constructed, 
// the buffer should be empty. 
// Need to figure out later how to handle opening and reading files.
GapBuffer::GapBuffer(size_t initial_size){
    this->buffer.resize(initial_size);
    this->gapStart = 0;
    this->gapSize = 10;
    this->gapEnd = this->gapSize - this->gapStart - 1;
    this->size = 10;
}

void GapBuffer::moveGap(int cursor){
    // Move left
    if (cursor < this->gapStart) {
        while (cursor < this->gapStart) {
            // Move one before gap start to end of gap
            this->buffer[this->gapEnd] = this->buffer[this->gapStart - 1];
            this->gapStart--;
            this->gapEnd--;
        }
    }
    else if (cursor > this->gapStart) {
        while (cursor > this->gapStart) {
            this->gapStart += 1;
            this->gapEnd += 1;
            this->buffer[this->gapStart-1] = buffer[this->gapEnd]; 
        // buffer[gap_right]='_';
            // Move one after gap end to gapp start
        }
    }
}

// Inserts the given string at the given cursor position.
// Does not handle updating the given cursor position
// If the cursor changes to a class then possibly it might make sense to change it here
// As of now the Gap buffer class operates independtly from the view
void GapBuffer::insert(const std::string& input, int cursor) {
    int i = 0; 

    if (cursor != this->gapStart) { 
        this->moveGap(cursor);
    } 
    // TODO: Change to a for loop or for each loop
    while (i < input.length()) {
        // The gap only has one element so we need to resize it
        if (this->gapStart == this->gapEnd) {
            this->grow();
        }
        this->buffer[this->gapStart] = input[i];
        this->gapStart += 1;
        i +=1;
    }
}

void GapBuffer::grow() {
    // We do not need to grow if the gap still has space
    if (this->gapStart != this->gapEnd) {
        return;
    }
    // Our buffer doesn't have enough space for the current elements plus the new gap
    if (this->gapSize + this->size > this->buffer.size()) {
        this->buffer.resize(this->buffer.size() * 2);
    }

    // TODO: We don't need to copy to a temp array, we should be able to just shift things over
    std::vector<char> temp; // Create a temp array the size of the buffer to hold things

    // All all elements right of the gap to the temp array
    for (int i = this->gapStart+1; i < size; i++) { 
       temp.push_back(buffer[i]); 
    }
    this->gapEnd += this->gapSize ;
    // Increase to gap to the size we want it to be
    int p = this->gapEnd + 1;
    // COPY elements over
    for (int i = 0; i < temp.size(); i++) {
        this->buffer[p] = temp[i];
        p += 1;
    }
    this->size += this->gapSize;

}

std::string GapBuffer::bufferText() {
    std::vector<char> vec;
    for (int i = 0; i < this->buffer.size(); i++) {
        if ((i < this->gapStart || i > this->gapEnd) && i < this->size) {
            vec.push_back(this->buffer[i]);
        }
    }
    std::string str(vec.begin(), vec.end());
    return str;
}