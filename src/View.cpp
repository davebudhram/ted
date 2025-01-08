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
    this->cursor_x = 0;
    this->cursor_y = 0;
    cursor.setSize(sf::Vector2f(2, 15));
    cursor.setFillColor(sf::Color::White);
    cursor.setPosition(this->cursor_x, this->cursor_y);
    sf::Uint32 character = 'A'; // Unicode value for 'A'
    unsigned int characterSize = 15;

    const sf::Glyph& glyph = font.getGlyph(character, characterSize, false);
    this->fontWidth = glyph.advance; // Width of the character 'A'
}

void View::render() {


    this->window.display();
    this->window.clear(sf::Color(40, 42, 54, 255));
    this->window.draw(text);
    this->cursor.setPosition(this->cursor_x, this->cursor_y);
    this->window.draw(cursor);
}

void View::updateText(const std::string &text) {
    this->text.setString(text);
}

void View::updateCursor(int x, int y) {
    this->cursor_x = this->fontWidth * y;
    this->cursor_y = this->font.getLineSpacing(15) * x;

    
}
