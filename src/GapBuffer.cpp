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
    this->gapSize = 10; // This is fixed to 10
    this->gapEnd = this->gapSize - this->gapStart - 1;
    this->size = 10; // To represent how much of the buffer is filled.
    this->cursor = 0; // Single index of where the cursor is
    this->lineNum = 0;
    this->charWidth = 0;
}

void GapBuffer::moveGap(int cursor){
    // Move left
    if (cursor < this->gapStart) {
        while (cursor < this->gapStart) {
            // Move one before gap start to end of gap
            this->buffer[this->gapEnd] = this->buffer[this->gapStart - 1];
            //this->buffer[this->gapStart - 1] = '*';
            this->gapStart--;
            this->gapEnd--;
        }
    }
    else if (cursor > this->gapStart) {
        while (cursor > this->gapStart) {
            this->gapStart += 1;
            this->gapEnd += 1;
            this->buffer[this->gapStart-1] = buffer[this->gapEnd]; 
            //this->buffer[this->gapEnd] = '*';
        }
    }
}

// Inserts the given string at the given cursor position.
// Does not handle updating the given cursor position
// If the cursor changes to a class then possibly it might make sense to change it here
// As of now the Gap buffer class operates independtly from the view
void GapBuffer::insert(const std::string& input) {
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
        this->cursor += 1;
        if (input[i] == '\n') {
            this->lineNum += 1;
            this->charWidth = 0;
        }
        else {
            this->charWidth += 1;
        }
        i +=1;
        
    }
}

void GapBuffer::backspace() {
    // Want to backsapce at the cursor position
    if (this->cursor > 0) {
        this->gapStart -= 1;
        this->cursorLeft();
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
        if (i == this->cursor) {
            vec.push_back('|');
        }
        if ((i < this->gapStart || i > this->gapEnd) && i < this->size) {
            vec.push_back(this->buffer[i]);
        }

    }
    std::string str(vec.begin(), vec.end());
    return str;
}

void GapBuffer::cursorLeft() {
    if (this->cursor > 0) {
        this->cursor -= 1;
        if (this->buffer[this->cursor] == '\n') {
            this->lineNum -= 1;
            this->charWidth = this->currentLineCharWidth(this->cursor);
            
        }
        else {
            this->charWidth -= 1;
        }
        // this->cursor -= 1;
        this->moveGap(this->cursor);
    }
}

void GapBuffer::cursorRight() {
    if (this->cursor < this->size - (this->gapEnd - this->gapStart + 1)) {
        // std::string bufferString2 = "";
        // for (char c : this->buffer) {
        //     if (c == '\n') {
        //         bufferString2 += "NL";
        //     }
        //     else {
        //         bufferString2 += c;
        //     }
            
        // }
        
        // std::cout << bufferString2 << std::endl;
        // std::cout << "(" << this->lineNum << ", " << this->charWidth << ")" << std::endl;
        if (this->buffer[this->gapEnd + 1] == '\n') {
            this->lineNum += 1;
            this->charWidth = 0;
        }
        else {
            this->charWidth += 1;
        }
         //std::cout << "(" << this->lineNum << ", " << this->charWidth << ")" << std::endl;
        this->cursor += 1;
        this->moveGap(this->cursor);
    }
}

void GapBuffer::cursorUp() {

    // Algorithm is simple but O(n) (Computers these days should be able to handle)
    // starting from the cursor go backuntil we get a new line. Keep track
    // of how many characters we saw
    // Go to next new line or position 0. If we get to position 0 end put cursor at 0
    // If we find a new line
    // Go right to amount of characters we went left originally until
    if (this->cursor == 0) {
        return;
    }
    int cursor_copy = this->cursor - 1;
    int width = 0;
    while (cursor_copy >= 0) {
        if (cursor_copy == 0) {
            this->cursor = 0;
            this->moveGap(this->cursor);
            this->charWidth = 0;
            return;
        }
        if (this->buffer[cursor_copy] == '\n' ) {
            break;
        }
        cursor_copy -= 1;
        width += 1;
    }
    int width2 = 0;
    while (cursor_copy >= 0) {
        if (cursor_copy == 0) {
            break;
        }
        cursor_copy -= 1;
        width2 += 1;
        if (this->buffer[cursor_copy] == '\n') {
            width2 -= 1;
            cursor_copy +=1;
            break;
        }

    }
    this->lineNum -= 1;
    this->charWidth = std::min(width, width2);
    this->cursor = cursor_copy + std::min(width, width2);
    this->moveGap(this->cursor);
}

void GapBuffer::cursorDown() {
    if (this->cursor == this->size - (this->gapEnd - this->gapStart) - 1) {
        return;
    }
    // This algorithm is more complicated I'm guessing due to now having to deal with the gap.
    // We might also need to go left and then right possibily
    // Go left to get the width of the current line (when we add a current pos in we won't need this)
    // Go left get width of this line. Go until cursor pos is 0 or /n. If a new line do then same as before
    // Then go back to the current cursor position
    // Go right until we find a new line or until we reach the size of the gap buffer. 
    // If we reach the end stay there
    // If we reach new line
    // Go right for the width of the line or until the end of the line

    int cursorCopy = this->cursor - 1;
    int width = 0;
    while (cursorCopy >= 0) {
        if (this->buffer[cursorCopy] == '\n') {
            break;
        }
        cursorCopy -= 1;
        width += 1;
    }
    cursorCopy = this->gapEnd + 1;
    // find the next new line
    int width2 = 0;
    while (cursorCopy < this->size) {
       
        if (this->buffer[cursorCopy] == '\n') {
            width2 += 1;
            break;
        }
        cursorCopy += 1;
        width2 += 1;
    }
    this->cursor += width2;
    this->moveGap(this->cursor);
    int width3 = 0;
    while (cursorCopy < this->size) {
        cursorCopy += 1;
        width3 += 1;
        if (this->buffer[cursorCopy] == '\n') {
            width3 -= 1;
            break;
        }
    }
    if (width3 == 0) {
        charWidth = width + width2;
    } 
    else {
        charWidth = std::min(width, std::max(width3 - 1, 0));
        lineNum += 1;
    }
    this->cursor += std::min(width, std::max(width3 - 1, 0));
    this->moveGap(this->cursor);

}

// Get the current line's character width
int GapBuffer::currentLineCharWidth(int p) {
    p -= 1;
    int width = 0;
    while (p >= 0) {
        if (this->buffer[p] == '\n' ) {
            break;
        }
        p -= 1;
        width += 1;
    }
    return width;
}