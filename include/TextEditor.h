#include "./GapBuffer.h"

#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

/**
 * The TextEditor class is our "model" in the MVC pattern. All "backend" type of logic will happen
 * here. The gap buffer is the primary focus of the text editor handling inserting, deleting, 
 * backspacing, and moving the internal cursor to the correct position. With that being said, I 
 * wonder if I should move the cursor logic here. The cursor logic will need to use the gap buffer.
 * 
 */
class TextEditor {
    public:
        TextEditor();
        // Methods
        void insert(const std::string& input);
        void backspace();
        std::string text();
        void cursorLeft();
        void cursorRight();
        void cursorUp();
        void cursorDown();
        int numLines();
        int lineNum();
        int charWidth();
    private:
        // Fields
        GapBuffer gapBuffer;
        int totalLines = 0;
};

#endif