#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H
#include "./GapBuffer.h"
#include "./Cursor.h"


class TextEditor {
    public:
        TextEditor(GapBuffer& gapBuffer) : gb(gapBuffer) {}
    private:
        GapBuffer& gb;
};

#endif