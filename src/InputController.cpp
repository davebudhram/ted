#include "../include/GapBuffer.h" 
#include "../include/InputController.h" 
#include "../SFML/include/SFML/System.hpp"
#include <string>



// Inserting character into the buffer
void InputController::handleKeyboardInput(sf::Event event) {
    // const sf::Keyboard::Key keycode = keyEvent.code;
    // Only works for numbers
    // if (keycode >= sf::Keyboard::A && keycode <= sf::Keyboard::Z) {
    //     char chr = static_cast<char>(keycode - sf::Keyboard::A + 'a');
    //     std::string str(1, chr); 
    //     this->gb.insert(str, 0);
    // }
    if (event.type == sf::Event::TextEntered) {
        // sf::String input(event.text.unicode);
        // std::string str = input.toAnsiString(); 
        if (event.text.unicode < 128) { // Check for ASCII characters
            char character = static_cast<char>(event.text.unicode);
            std::string str(1, character);
            this->gb.insert(str, 0);
        }
    }
    
} 