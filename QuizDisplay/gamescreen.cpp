#include "gamescreen.hpp"


int gamescreen(sf::RenderWindow &window, std::vector<user> users){

  std::cout << "Enter gamescreen running" << std::endl;
    //Load Background picture and create texture object
    sf::Texture texture;
    if (!texture.loadFromFile("gamescreen.jpg"))
    {   //error message
        std::cout << "ERROR: Gamescreen Background Image Unable to Load" << std::endl;
      }

      sf::Font Cammron;
  if (!Cammron.loadFromFile("fonts/Cammron.ttf"))
  {
      // error message
      std::cout << "ERROR: Cammron Font Unable to Load" << std::endl;
  }

    //Set texture as a sprite
    sf::Sprite background(texture);

    sf::Text questiontxt;
    sf::Text answer1txt;
    sf::Text answer2txt;
    sf::Text answer3txt;
    sf::Text answer4txt;
    sf::Text p1nametxt;
    sf::Text p2nametxt;
    sf::Text p3nametxt;
    sf::Text p4nametxt;


    // select the font
    questiontxt.setFont(Cammron); // font is a sf::Font
    answer1txt.setFont(Cammron);

    // set the string to display
//    questiontxt.setString();


    // set the character size
    questiontxt.setCharacterSize(24); // in pixels, not points!
    answer1txt.setCharacterSize(24);

    // set the color
    questiontxt.setFillColor(sf::Color::Black);
    answer1txt.setFillColor(sf::Color::Black);

    // set the text style
    questiontxt.setStyle(sf::Text::Bold);

    sf::FloatRect questionrect = questiontxt.getLocalBounds();
    questiontxt.setOrigin(questionrect.width/2,questionrect.height/2);
    questiontxt.setPosition(sf::Vector2f(800/2.0f,200));
/*
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

*/

    // run the program as long as the window is open
    while (window.isOpen())
      {


        //draw background image on screen
        window.draw(background);
/*

        //Write Text to screen
        window.draw(dsplytxt);

        //Draw number of users buttons and text
        window.draw(button1);
        window.draw(button1txt);

        window.draw(playertxt);
*/

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
/*                 if(event.mouseButton.x < 375 && event.mouseButton.x > 275 && event.mouseButton.y < 400 && event.mouseButton.y > 300){


                    std::cout << "users left: " << usersleft << "  name entered: "<< enteredname << std::endl;

                    if(usersleft == 0){
                    return 4;
                    }
                  }
*/

                }
              }
/*          if (event.type == sf::Event::TextEntered){
              if(event.text.unicode < 128){
                if(event.text.unicode == '\b' && playerinput.begin() != playerinput.end()){

                  playerinput.erase(playerinput.getSize()-1, 1);
                  playertxt.setString(playerinput);
                }
                else{
                  playerinput +=event.text.unicode;
                  playertxt.setString(playerinput);
                }
              }
          }
  */
//            window.display();
    }

//    window.draw(playertxt);
    window.display();
        // end the current frame
        window.display();

      }
    return 0;
}
