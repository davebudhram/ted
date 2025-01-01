#include "./TextEditor.h" 
#include "./View.h"
#include "../SFML/include/SFML/Graphics.hpp"

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <string>

// Idea for now is to have this controller handle the user inputs. 
// The controller will hold a reference to the gap buffer
// While I haven't started the cursor it might need to hold that as well
// We will handle sfml key events here. Issue I see is identifying what key is pressed
// Having shift pressed and having a letter pressed will be tricky. 
class Controller {
    public:
        Controller(TextEditor& textEditor, View& view): textEditor(textEditor), view(view) {}
        void handleKeyboardInput(sf::Event event);
    private:
        TextEditor& textEditor;
        View& view;
};

#endif