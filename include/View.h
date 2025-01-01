#include "../SFML/include/SFML/Graphics.hpp"

#ifndef VIEW_H
#define VIEW_H

#include <vector>
#include <string>

/**
 * The View is part of the typical MVC pattern. Our view will hold a reference to an SFML 
 * RenderWindow where the program will be displayed. We will need to figure out how to represent
 * Different things that get displayed such as the text and the cursor. 
 */
class View {
    public:
        View(sf::RenderWindow& window);

        // Methods
        void render();
        void updateText(const std::string&  text);
    private:
        // Fields
        sf::RenderWindow& window;
        sf::Font font;
        sf::Text text;
};

#endif