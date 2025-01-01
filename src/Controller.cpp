#include "../include/Controller.h"
#include "../include/TextEditor.h" 
#include "../include/View.h"
#include "../SFML/include/SFML/System.hpp"
#include <string>
#include <iostream>


// Inserting character into the buffer
void Controller::handleKeyboardInput(sf::Event event) {
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Left) {
            this->textEditor.cursorLeft();
        }
        else if(event.key.code == sf::Keyboard::Right) {
            this->textEditor.cursorRight();
        }
        else if(event.key.code == sf::Keyboard::Backspace) {
            this->textEditor.backspace();
        }
        else if(event.key.code == sf::Keyboard::Up) {
            this->textEditor.cursorUp();
        }
        else if (event.key.code == sf::Keyboard::Down) {
            this->textEditor.cursorDown();
        }
    }
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode < 128 && event.text.unicode != 8) { // Check for ASCII characters
            char character = static_cast<char>(event.text.unicode);
            std::string str(1, character);
            this->textEditor.insert(str);
        }
    }
    this->view.updateText(this->textEditor.text());

    
} 