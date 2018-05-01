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
    sf::Time elapsed; // set time object

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
            //If user clicked a window, it stops the whole program or the clock
            if(event.type == sf::Event::Closed)
                window.close();
            //When a character is pressed, restart the clock
            if(event.type == sf::Event::KeyReleased)
                clock.restart();
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
        ss << std::endl << "Time Remaining " << " : " << timeRemaining;
        //Display
        text.setString( ss.str().c_str() );
        window.draw(text);
        window.display();
        window.clear();

    }
    return 0;
}
