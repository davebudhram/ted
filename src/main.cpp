#include "../include/TextEditor.h" 
#include "../include/Controller.h"
#include <iostream>
#include <string>
#include "../SFML/include/SFML/Graphics.hpp"

int main() {
    TextEditor textEditor;
    Controller controller(textEditor);
    // Cursor cursor(gapBuffer);
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test");
    sf::Font font;
    font.loadFromFile("../fonts/Monaco.ttf"); 

    sf::Text text;
    text.setFont(font);
    std::string myString = ""; 
    text.setPosition(0, 0);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(15);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            controller.handleKeyboardInput(event);
            myString = textEditor.text();

           
        }
        window.display();
        window.clear(sf::Color(40, 42, 54, 255));
        text.setString(myString);
        window.draw(text);
    }


    return 0;
}