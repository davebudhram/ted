#include "../include/GapBuffer.h" 
#include "../include/TextEditor.h" 

TextEditor::TextEditor() {
    this->gapBuffer = GapBuffer(100);
}

void TextEditor::insert(const std::string& input) {
    this->gapBuffer.insert(input);
    // Surely the gap buffer can just hold this right?
    this->totalLines = std::max(this->totalLines, this->gapBuffer.lineNum); 
}

void TextEditor::backspace() {
    this->gapBuffer.backspace();
}

std::string TextEditor::text() {
    return this->gapBuffer.bufferText();
}

void TextEditor::cursorLeft() {
    this->gapBuffer.cursorLeft();
}

void TextEditor::cursorRight() {
    this->gapBuffer.cursorRight();

}

void TextEditor::cursorUp() {
    this->gapBuffer.cursorUp();

}
void TextEditor::cursorDown() {
    this->gapBuffer.cursorDown();

}

int TextEditor::numLines() {
    return this->totalLines;
}

int TextEditor::lineNum() {
    return this->gapBuffer.lineNum;
}

int TextEditor::charWidth() {
    return this->gapBuffer.charWidth;
}