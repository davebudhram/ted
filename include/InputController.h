#include "./GapBuffer.h" 
#include "../SFML/include/SFML/Graphics.hpp"
#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER_H

#include <vector>
#include <string>

// Idea for now is to have this controller handle the user inputs. 
// The controller will hold a reference to the gap buffer
// While I haven't started the cursor it might need to hold that as well
// We will handle sfml key events here. Issue I see is identifying what key is pressed
// Having shift pressed and having a letter pressed will be tricky. 
class InputController {
public:
    InputController(GapBuffer& gapBuffer): gb(gapBuffer) {}
    void handleKeyboardInput(sf::Event event);
private:
    GapBuffer& gb;
    int cursor = 0;
};

#endif