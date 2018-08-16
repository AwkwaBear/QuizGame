#include "enter_users.hpp"
#include <SFML/Audio.hpp>

int enter_users(sf::RenderWindow &window, int * px)
{
  sf::SoundBuffer buffer;

  if(!buffer.loadFromFile("pling.wav")){
    return -1;
  }

  sf::Sound pling;
  pling.setBuffer(buffer);

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
    sf::Text button2txt;
    sf::Text button3txt;
    sf::Text button4txt;

    // select the font
    dsplytxt.setFont(robot); // font is a sf::Font
    button1txt.setFont(robot);
    button2txt.setFont(robot);
    button3txt.setFont(robot);
    button4txt.setFont(robot);

    // set the string to display
    dsplytxt.setString("Choose How Many Users");
    button1txt.setString("1");
    button2txt.setString("2");
    button3txt.setString("3");
    button4txt.setString("4");

    // set the character size
    dsplytxt.setCharacterSize(24); // in pixels, not points!
    button1txt.setCharacterSize(24);
    button2txt.setCharacterSize(24);
    button3txt.setCharacterSize(24);
    button4txt.setCharacterSize(24);

    // set the color
    dsplytxt.setFillColor(sf::Color::White);
    button1txt.setFillColor(sf::Color::White);
    button2txt.setFillColor(sf::Color::White);
    button3txt.setFillColor(sf::Color::White);
    button4txt.setFillColor(sf::Color::White);

    // set the text style
    dsplytxt.setStyle(sf::Text::Bold | sf::Text::Underlined);
    button1txt.setStyle(sf::Text::Bold);
    button2txt.setStyle(sf::Text::Bold);
    button3txt.setStyle(sf::Text::Bold);
    button4txt.setStyle(sf::Text::Bold);

    sf::FloatRect dsplyrect = dsplytxt.getLocalBounds();
    dsplytxt.setOrigin(dsplyrect.width/2,dsplyrect.height/2);
    dsplytxt.setPosition(sf::Vector2f(800/2.0f,200));

    // declare buttons for user input
    sf::RectangleShape button1(sf::Vector2f(120, 50));
    sf::RectangleShape button2(sf::Vector2f(120, 50));
    sf::RectangleShape button3(sf::Vector2f(120, 50));
    sf::RectangleShape button4(sf::Vector2f(120, 50));



    // change the size to 300x100
    button1.setSize(sf::Vector2f(100, 100));
    button2.setSize(sf::Vector2f(100, 100));
    button3.setSize(sf::Vector2f(100, 100));
    button4.setSize(sf::Vector2f(100, 100));

    button1.setPosition(sf::Vector2f(275,300));
    button2.setPosition(sf::Vector2f(425,300));
    button3.setPosition(sf::Vector2f(275,450));
    button4.setPosition(sf::Vector2f(425,450));
    button1.setFillColor(sf::Color::Green);
    button2.setFillColor(sf::Color::Green);
    button3.setFillColor(sf::Color::Green);
    button4.setFillColor(sf::Color::Green);

    sf::FloatRect button1rect = button1txt.getLocalBounds();
    sf::FloatRect button2rect = button2txt.getLocalBounds();
    sf::FloatRect button3rect = button3txt.getLocalBounds();
    sf::FloatRect button4rect = button4txt.getLocalBounds();
    button1.setOrigin(button1rect.width/2,button1rect.height/2);
    button2.setOrigin(button2rect.width/2,button2rect.height/2);
    button3.setOrigin(button3rect.width/2,button3rect.height/2);
    button4.setOrigin(button4rect.width/2,button4rect.height/2);

    button1txt.setPosition(sf::Vector2f(310, 340));
    button2txt.setPosition(sf::Vector2f(460, 340));
    button3txt.setPosition(sf::Vector2f(310, 490));
    button4txt.setPosition(sf::Vector2f(460, 490));


    // run the program as long as the window is open
    while (window.isOpen())
      {


        //draw background image on screen
        window.draw(background);


        //Write Text to screen
        window.draw(dsplytxt);

        //Draw number of users buttons and text
        window.draw(button1);
        window.draw(button2);
        window.draw(button3);
        window.draw(button4);
        window.draw(button1txt);
        window.draw(button2txt);
        window.draw(button3txt);
        window.draw(button4txt);


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
                  //If buton 1 is pressed
                  if(event.mouseButton.x < 375 && event.mouseButton.x > 275 && event.mouseButton.y < 400 && event.mouseButton.y > 300){

                    *px = 1;

                    std::cout << "button 1 clicked" <<std::endl;
                      pling.play();
                    return 3;
                  }
                  //If button 2 is pressed
                  if(event.mouseButton.x < 525 && event.mouseButton.x > 425 && event.mouseButton.y < 400 && event.mouseButton.y > 300){
                    //set users playing to 2
                    *px = 2;

                    std::cout << "button 2 clicked" <<std::endl;
                      pling.play();
                    return 3;
                  }
                  //If buton 3 is pressed
                  if(event.mouseButton.x < 375 && event.mouseButton.x > 275 && event.mouseButton.y < 550 && event.mouseButton.y > 450){

                    *px = 3;

                    std::cout << "button 3 clicked" <<std::endl;
                      pling.play();
                    return 3;
                  }
                  //If buton 4 is pressed
                  if(event.mouseButton.x < 525 && event.mouseButton.x > 425 && event.mouseButton.y < 550 && event.mouseButton.y > 450){

                    *px = 4;

                    std::cout << "button 4 clicked" <<std::endl;
                      pling.play();
                    return 3;
                  }

                }
              }


          }


        // end the current frame
        window.display();

      }
    return 0;
}
