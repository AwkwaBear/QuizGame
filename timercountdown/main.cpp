#include <SFML/Graphics.hpp>
#include <sstream>
#include <cmath>



int main()
{

    sf::Font font;
    font.loadFromFile("times.ttf");

    sf::Text text;
    text.setFont(font);
    text.setPosition(100,450);
    text.setCharacterSize(40);
    text.setColor(sf::Color::White);


    sf::Clock clock; // starts the clock
    sf::Time elapsed1; // set time object

    int intSecondsCounted;
    int timeRemaining;
    std::stringstream ss;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Countdown Timer");
    // run the main loop

    while (window.isOpen())
    {
        // handle events

        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyReleased)
                clock.restart();
        }


        elapsed1 = clock.getElapsedTime();
        timeRemaining = 10 - floor(elapsed1.asSeconds());

        ss.str(std::string()); //clear the string
        ss << std::endl << "Time Remaining " << " : " << timeRemaining;

        if(timeRemaining == 0)
        {
          clock.restart();
        }

        text.setString( ss.str().c_str() );
        window.draw(text);
        window.display();
        window.clear();

    }

    return 0;
}
