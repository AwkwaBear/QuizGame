#include "intro.hpp"


void intro()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Quiz Game");
    window.setFramerateLimit(15);

    //Load Background picture and create texture object
    sf::Texture texture;
    if (!texture.loadFromFile("background.jpg"))
    {   //error message
        std::cout << "ERROR: Background Image Unable to Load" << std::endl;
      }

      sf::Font robot;
  if (!robot.loadFromFile("fonts/Patchy Robots.ttf"))
  {
      // error message
      std::cout << "ERROR: Patchy Robots Font Unable to Load" << std::endl;
  }

    //Set texture as a sprite
    sf::Sprite background(texture);

    sf::Text welcome;
    sf::Text play;

    // select the font
    welcome.setFont(robot); // font is a sf::Font
    play.setFont(robot);

    // set the string to display
    welcome.setString("Welcome to the EE205 Quiz Game");
    play.setString("Press Enter to Play");

    // set the character size
    welcome.setCharacterSize(24); // in pixels, not points!
    play.setCharacterSize(16);

    // set the color
    welcome.setFillColor(sf::Color::White);
    play.setFillColor(sf::Color::White);

    // set the text style
    welcome.setStyle(sf::Text::Bold | sf::Text::Underlined);
    play.setStyle(sf::Text::Bold);

    sf::FloatRect textRect = welcome.getLocalBounds();
    welcome.setOrigin(textRect.width/2,textRect.height/2);
    welcome.setPosition(sf::Vector2f(800/2.0f,200));

    // define a 120x50 rectangle
    sf::RectangleShape startbutton(sf::Vector2f(120, 50));

    // change the size to 100x100
    startbutton.setSize(sf::Vector2f(300, 100));

    sf::FloatRect buttonRect = startbutton.getLocalBounds();
    startbutton.setOrigin(buttonRect.width/2,buttonRect.height/2);
    play.setOrigin(buttonRect.width/2.5,buttonRect.height/6);
    startbutton.setPosition(sf::Vector2f(800/2.0f,400));
    play.setPosition(sf::Vector2f(800/2.0f,400));
    startbutton.setFillColor(sf::Color::Green);

    // run the program as long as the window is open
    while (window.isOpen())
      {


        //draw background image on screen
        window.draw(background);

        //Write Text to screen
        window.draw(welcome);

        //Draw startbutton and text
        window.draw(startbutton);
        window.draw(play);

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
//        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }

    return;
}
