#include "enter_names.hpp"


int enter_names(sf::RenderWindow &window, int * px)
{
  std::cout << "Enter users screen running" << std::endl;
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

    sf::Text dsplytxt;
    sf::Text button1txt;
    sf::String playerinput;
    sf::Text playertxt;

    // select the font
    dsplytxt.setFont(robot); // font is a sf::Font
    button1txt.setFont(robot);
    playertxt.setFont(robot);

    // set the string to display
    dsplytxt.setString("Enter player 1's name: ");
    button1txt.setString("ENTER");


    // set the character size
    dsplytxt.setCharacterSize(24); // in pixels, not points!
    button1txt.setCharacterSize(24);
    playertxt.setCharacterSize(24);

    // set the color
    dsplytxt.setFillColor(sf::Color::White);
    button1txt.setFillColor(sf::Color::White);
    playertxt.setFillColor(sf::Color::White);

    // set the text style
    dsplytxt.setStyle(sf::Text::Bold | sf::Text::Underlined);
    button1txt.setStyle(sf::Text::Bold);

    sf::FloatRect dsplyrect = dsplytxt.getLocalBounds();
    dsplytxt.setOrigin(dsplyrect.width/2,dsplyrect.height/2);
    dsplytxt.setPosition(sf::Vector2f(800/2.0f,200));

    // declare buttons for user input
    sf::RectangleShape button1(sf::Vector2f(120, 50));



    // change the size to 300x100
    button1.setSize(sf::Vector2f(200, 100));


    button1.setPosition(sf::Vector2f(275,300));
    playertxt.setPosition(sf::Vector2f(200, 250));

    button1.setFillColor(sf::Color::Green);

    sf::FloatRect button1rect = button1txt.getLocalBounds();

    button1.setOrigin(button1rect.width/2,button1rect.height/2);


    button1txt.setPosition(sf::Vector2f(310, 340));



    // run the program as long as the window is open
    while (window.isOpen())
      {


        //draw background image on screen
        window.draw(background);


        //Write Text to screen
        window.draw(dsplytxt);

        //Draw number of users buttons and text
        window.draw(button1);
        window.draw(button1txt);

        window.draw(playertxt);


  // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (window.pollEvent(event))
    {
        // "close requested" event: we close the window
      if (event.type == sf::Event::Closed){
                window.close();
              }

           if (event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left){

                  std::cout << "the right click was pressed" << std::endl;
                  std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                  std::cout << "mouse y: " << event.mouseButton.y << std::endl;

                  //If Enter button is pressed
                  if(event.mouseButton.x < 375 && event.mouseButton.x > 275 && event.mouseButton.y < 400 && event.mouseButton.y > 300){

                    std::cout << "Enter Button clicked" <<std::endl;

  //                  return 3;
                  }


                }
              }
          if (event.type == sf::Event::TextEntered){
              if(event.text.unicode < 128){
                  playerinput +=event.text.unicode;
                  playertxt.setString(playerinput);
                }
              }
            window.draw(playertxt);
            window.display();
          }


        // end the current frame
        window.display();

      }
    return 0;
}
