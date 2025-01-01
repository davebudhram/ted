#include "../include/Controller.h"
#include "../include/TextEditor.h" 
#include "../include/View.h"
#include <iostream>
#include <string>
#include "../SFML/include/SFML/Graphics.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test");
    TextEditor textEditor;
    View view(window);
    Controller controller(textEditor, view);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            controller.handleKeyboardInput(event);
        }
        view.render();
    }


    return 0;
}