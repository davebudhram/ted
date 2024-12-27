#include "../include/GapBuffer.h" 
#include "../include/InputController.h" 
#include "../SFML/include/SFML/System.hpp"
#include <string>
#include <iostream>



// Inserting character into the buffer
void InputController::handleKeyboardInput(sf::Event event) {
     if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Left) {
            this->gb.cursorLeft();
        }
        else if(event.key.code == sf::Keyboard::Right) {
            this->gb.cursorRight();
        }
        else if(event.key.code == sf::Keyboard::Backspace) {
            this->gb.backspace();
        }
        else if(event.key.code == sf::Keyboard::Up) {
            this->gb.cursorUp();
        }
        else if (event.key.code == sf::Keyboard::Down) {
            this->gb.cursorDown();
        }
        else if (event.key.code == sf::Keyboard::Escape) {
            std::cout << "(" << gb.lineNum << ", " << gb.charWidth << ")" << std::endl;
        }
    }
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode < 128 && event.text.unicode != 8) { // Check for ASCII characters
            char character = static_cast<char>(event.text.unicode);
            std::string str(1, character);
            this->gb.insert(str);
            this->cursor++;

        }
    }
   
    
} 