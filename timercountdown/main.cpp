#include <SFML/Graphics.hpp>
#include "Keyboard.hpp"
#include <sstream>
#include <cmath>
#include <string>
#include <iostream>





int main()
{

    sf::Font font;
    font.loadFromFile("times.ttf");


    sf::Text text;
    text.setFont(font);
    text.setPosition(300,490);
    text.setCharacterSize(40);
    text.setColor(sf::Color::Black);

    sf::Texture texture;
    texture.loadFromFile("800x600.png");
    sf::Sprite background(texture);

    sf::Clock clock; // starts the clock
    sf::Time elapsed; // set time object

    int intSecondsCounted;
    int timeRemaining;
    std::stringstream ss;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Countdown Timer");
    // run the main loop

    window.setKeyRepeatEnabled(false);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Num1 || event.key.code == sf::Keyboard::Num2 ||
                   event.key.code == sf::Keyboard::Num3 || event.key.code == sf::Keyboard::Num4) {
                    clock.restart();
                }
            }
        }

        // set the timer
        elapsed = clock.getElapsedTime();
        // set the countdown timer by 10 seconds
        timeRemaining = 10 - floor(elapsed.asSeconds());
                //When the countdown timer reaches 0, restart the clock
                if(timeRemaining == 0)
                {
                  clock.restart();
                }

        ss.str(std::string()); //clear the string
        ss << std::endl << timeRemaining;
        //Display
        text.setString( ss.str().c_str() );
        window.draw(background);
        window.draw(text);
        window.display();
        window.clear();

    }
    return 0;
}
