#include <iostream>
#include "controller/Controller.hpp"
#include "settings/SETTINGS.hpp"
#include "model/Butin.hpp"

int main(void){
    // sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application");
    // sf::CircleShape shape;
    // shape.setRadius(40.f);
    // shape.setPosition(100.f, 100.f);
    // shape.setFillColor(sf::Color::Cyan);

    // while (window.isOpen())
    // {
    //     sf::Event event;

    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }

    //     window.clear();
    //     window.draw(shape);
    //     window.display();
    // }
    Controller(SCREEN_WIDTH, SCREEN_HEIGHT, "TESSSSSSSt");
    vector<string> v;
    v.push_back("oui");
    Butin *b = new Butin(v);

    return EXIT_SUCCESS;
}