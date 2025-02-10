#include "../include/GapBuffer.h" 
#include <iostream>

// https://www.geeksforgeeks.org/gap-buffer-data-structure/
/**
 * Constructor for the Gap Buffer. Hardcoded the initial gap size to be 10. This means the gap start
 * is 0 and the gap end is 9. We also store the current lineNum and charWidth in order to figure out
 * where the cursor should be. The int cursor is the index in the buffer where the cursor should be.
 * Size refers to how much of the buffer is actually being used
 */
GapBuffer::GapBuffer(size_t initial_size) {
    this->buffer.resize(initial_size);
    this->gapStart = 0;
    this->gapSize = 10; 
    this->gapEnd = this->gapSize - this->gapStart - 1;
    this->size = 10; // To represent how much of the buffer is filled.
    this->cursor = 0; // Single index of where the cursor is
    this->lineNum = 0;
    this->charWidth = 0;    
}

/**
 * Move the gap to the cursor position given
 */
void GapBuffer::moveGap(int cursor){
    // Move left
    if (cursor < this->gapStart) {
        while (cursor < this->gapStart) {
            this->buffer[this->gapEnd] = this->buffer[this->gapStart - 1];
            this->buffer[this->gapStart - 1] = '*';
            this->gapStart--;
            this->gapEnd--;
        }
    }
    // Move right
    else if (cursor > this->gapStart) {
        while (cursor > this->gapStart) {
            this->gapStart += 1;
            this->gapEnd += 1;
            this->buffer[this->gapStart-1] = buffer[this->gapEnd]; 
            this->buffer[this->gapEnd] = '*';
        }
    }
}

/**
 * Grow the gap size when the gap 
 */
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
    int p = this->gapEnd + 1;
    // COPY elements over
    for (int i = 0; i < temp.size(); i++) {
        this->buffer[p] = temp[i];
        p += 1;
    }
    this->size += this->gapSize;

}

/**
 * Inserts the given string at the cursor location.
 */
void GapBuffer::insert(const std::string& input) {
    if (cursor != this->gapStart) { 
        this->moveGap(cursor);
    } 
    for (char c: input) {
        // Grow the gap (if needed)
        this->grow();
        // Insert the character to the buffer
        this->buffer[this->gapStart] = c;
        this->gapStart += 1;
        this->cursor += 1;
        // Update the lineNum and charWidth
        if (c == '\n') {
            this->lineNum += 1;
            this->charWidth = 0;
        }
        else {
            this->charWidth += 1;
        }
    }
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
        if (this->buffer[this->gapEnd + 1] == '\n') {
            this->lineNum += 1;
            this->charWidth = 0;
        }
        else {
            this->charWidth += 1;
        }
        this->cursor += 1;
        this->moveGap(this->cursor);
    }
}
/**
 * Backspace by one character. O(1) operation. Does not change the array size.
 */
void GapBuffer::backspace() {
    if (this->cursor > 0) {
        this->gapStart -= 1;
        this->cursorLeft();
    }
}

/**
 * Return the buffer text. This will need to change in the future to account for bolding, italicing
 * and underlining.
 */
std::string GapBuffer::bufferText() {
    std::vector<char> vec;
    std::vector<char> vec2;
    for (int i = 0; i < this->size; i++) {
        // Temporary to visualize the cursor is where it should be
        if (i == this->cursor) {
            vec2.push_back('|');
        }
        vec2.push_back(this->buffer[i]);
        if ((i < this->gapStart || i > this->gapEnd)) {
            vec.push_back(this->buffer[i]);
        }
    }
    std::string str(vec.begin(), vec.end());
    std::string str2(vec2.begin(), vec2.end());
    std::cout << str2 << std::endl;
    return str;
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
    while (cursorCopy <= this->size) {
        if (cursorCopy == this->size) {
            this->cursor += width2;
            this->moveGap(this->cursor);
            this->charWidth = width + width2;
            return;
        }
       
        if (this->buffer[cursorCopy] == '\n') {
            width2 += 1;
            lineNum += 1;
            break;
        }
        cursorCopy += 1;
        width2 += 1;
    }
    this->cursor += width2;
    this->moveGap(this->cursor);
    int width3 = 0;
    while (cursorCopy <= this->size) {
        cursorCopy += 1;
        
        if (this->buffer[cursorCopy] == '\n' || cursorCopy == this->size) {
            // width3 -= 1;

            break;
        }
        width3 += 1;
    }
    charWidth = std::min(width, std::max(width3, 0));
    std::cout << width << " " << width3 << std::endl;

    this->cursor += std::min(width, std::max(width3, 0));
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

int GapBuffer::currentLineWidth(int p) {
    int width = 0;
    while (p < this->size) {
        if (p >= this->gapStart && p <= this->gapEnd) {
            p++;
            continue;
        }

        if (this->buffer[p] == '\n') {
            break;
        }
        width++;
        p++;
    }
    return width;
}

/**
 * Move the cursor to the specified line and character width
 * @param newLineNum The line number to move the cursor to
 * @param newCharWidth The character width to move the cursor to
 */
void GapBuffer::moveCursor(int newLineNum, int newCharWidth) {
    std::cout << "cursor " <<  this->cursor << std::endl;
    std::cout << "gapStart " << this->gapStart << std::endl;
    std::cout << "gapEnd " << this->gapEnd << std::endl;
    std::cout << "size " << this->size << std::endl;
    int currLineNum = 0;
    int currCharWidth = 0;
    int lastLineStart = 0;
    for (int i = 0; i < this->size; i++) {
       // Skip the gap
        if (i >= this->gapStart && i <= this->gapEnd) {
            continue;
        }
        // Look for character now
        if (currLineNum == newLineNum) {
            int j = i;
            while (j < this->size) {
                if (j >= this->gapStart && j <= this->gapEnd) {
                    j += (this->gapEnd - this->gapStart + 1);
                    continue;
                }
                if (currCharWidth == newCharWidth || this->buffer[j] == '\n') {
                    if (this->cursor < j) {
                        this->cursor = j - (this->gapEnd - this->gapStart + 1);
                        this->moveGap(this->cursor);
                    }
                    else {
                        this->cursor = j;
                        this->moveGap(this->cursor);
                    }
                    this->reputeCursor();
                    return;
                }
                currCharWidth += 1;
                j++;
            }
            break;
            // if (this->cursor < j) {
            //     this->cursor = j - (this->gapEnd - this->gapStart + 1);
            //     this->moveGap(this->cursor);
            // }
            // else {
            //     this->cursor = j;
            //     this->moveGap(this->cursor);
            // }
            // this->reputeCursor();
            // return;
        }
                // Try to move the cursor to one before this line
        if (this->buffer[i] == '\n') {
            currLineNum += 1;
        }
    }
    this->cursor = this->size - (this->gapEnd - this->gapStart + 1) ; // make it look right but not actually correct 
    this->moveGap(this->cursor);
    // TODO: This is wrong
    this->reputeCursor();
    // If we reach here, the specified line and character width are out of bounds
}

void GapBuffer::reputeCursor() {
    this->lineNum = 0;
    this->charWidth = 0;
    for (int i = 0; i < this->size; i++) {
        if (i == this->cursor) {
            return;
        }
        if (i >= this->gapStart && i <= this->gapEnd) {
            continue;
        }

        if (this->buffer[i] == '\n') {
            this->lineNum += 1;
            this->charWidth = 0;
        }
        else {
            this->charWidth += 1;
        }
    }
}