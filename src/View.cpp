#include "../include/View.h"
#include <iostream>

// Contructor
View::View(sf::RenderWindow& window) : window(window) {
    // Load the font
    if (!font.loadFromFile("../fonts/Monaco.ttf")) {
        std::cout << "Failed to load font!" << std::endl;
    }

    text.setFont(font);
    text.setPosition(0, 0);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(15);
}

void View::render() {
    this->window.display();
    this->window.clear(sf::Color(40, 42, 54, 255));
    this->window.draw(text);
}

void View::updateText(const std::string &text) {
    this->text.setString(text);
}
