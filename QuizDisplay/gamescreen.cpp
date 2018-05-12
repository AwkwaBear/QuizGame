#include "gamescreen.hpp"
#include "user.hpp"
#include "answers.hpp"
#include "questions.hpp"
#include "topics.hpp"


int gamescreen(sf::RenderWindow &window, std::vector<user> users, int * userspx){


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

    sf::Text qtxt;
    sf::Text answer1txt;
    sf::Text answer2txt;
    sf::Text answer3txt;
    sf::Text answer4txt;
    sf::Text answeringplyrtxt;
    sf::Text p1nametxt;
    sf::Text p1scoretxt;
    sf::Text p2nametxt;
    sf::Text p2scoretxt;
    sf::Text p3nametxt;
    sf::Text p3scoretxt;
    sf::Text p4nametxt;
    sf::Text p4scoretxt;

    int i = 0;
    int countinput = 1;
    char lastinput = 'f';
    int answernum = 0;
    //Declare and generate topics
    topic cpp;
    topic pop;
    topic history;
    topic hawaii;

    //run topic initialization
    cpp.generate_topic_cpp();
    pop.generate_topic_pop();
    history.generate_topic_history();
    hawaii.generate_topic_hawaii();

    //create iterators for each topic vector
    std::vector<question>::iterator cpp_it = cpp.get_topic_begin();
    std::vector<question>::iterator pop_it = pop.get_topic_begin();
    std::vector<question>::iterator history_it = history.get_topic_begin();
    std::vector<question>::iterator hawaii_it = hawaii.get_topic_begin();
    std::vector<question>::iterator current_it = cpp.get_topic_begin();


    // select the font
    qtxt.setFont(Cammron); // font is a sf::Font
    answer1txt.setFont(Cammron);
    answer2txt.setFont(Cammron);
    answer3txt.setFont(Cammron);
    answer4txt.setFont(Cammron);
    answeringplyrtxt.setFont(Cammron);
    p1nametxt.setFont(Cammron);
    p2nametxt.setFont(Cammron);
    p3nametxt.setFont(Cammron);
    p4nametxt.setFont(Cammron);
    p1scoretxt.setFont(Cammron);
    p2scoretxt.setFont(Cammron);
    p3scoretxt.setFont(Cammron);
    p4scoretxt.setFont(Cammron);

/*
    // set the string to display
    qtxt.setString("Test Question here");
    answer1txt.setString("Answer 1");
    answer2txt.setString("Answer 2");
    answer3txt.setString("Answer 3");
    answer4txt.setString("Answer 4");
    answeringplyrtxt.setString("Player 1");
    p1nametxt.setString("player1");
    p2nametxt.setString("player2");
    p3nametxt.setString("player3");
    p4nametxt.setString("player4");
    p1scoretxt.setString("0");
    p2scoretxt.setString("0");
    p3scoretxt.setString("0");
    p4scoretxt.setString("0");
*/


    // set the character size
    //In pixels NOT POINTS!!
    qtxt.setCharacterSize(10);
    answer1txt.setCharacterSize(15);
    answer2txt.setCharacterSize(15);
    answer3txt.setCharacterSize(15);
    answer4txt.setCharacterSize(15);
    answeringplyrtxt.setCharacterSize(20);
    p1nametxt.setCharacterSize(20);
    p2nametxt.setCharacterSize(20);
    p3nametxt.setCharacterSize(20);
    p4nametxt.setCharacterSize(20);
    p1scoretxt.setCharacterSize(40);
    p2scoretxt.setCharacterSize(40);
    p3scoretxt.setCharacterSize(40);
    p4scoretxt.setCharacterSize(40);

    // set the color
    qtxt.setFillColor(sf::Color::White);
    answer1txt.setFillColor(sf::Color::White);
    answer2txt.setFillColor(sf::Color::White);
    answer3txt.setFillColor(sf::Color::White);
    answer4txt.setFillColor(sf::Color::White);
    answeringplyrtxt.setFillColor(sf::Color::White);
    p1nametxt.setFillColor(sf::Color::White);
    p2nametxt.setFillColor(sf::Color::White);
    p3nametxt.setFillColor(sf::Color::White);
    p4nametxt.setFillColor(sf::Color::White);
    p1scoretxt.setFillColor(sf::Color::White);
    p2scoretxt.setFillColor(sf::Color::White);
    p3scoretxt.setFillColor(sf::Color::White);
    p4scoretxt.setFillColor(sf::Color::White);



    // set the text style
    qtxt.setStyle(sf::Text::Bold);
    answer1txt.setStyle(sf::Text::Bold);
    answer2txt.setStyle(sf::Text::Bold);
    answer3txt.setStyle(sf::Text::Bold);
    answer4txt.setStyle(sf::Text::Bold);
    answeringplyrtxt.setStyle(sf::Text::Bold);
    p1nametxt.setStyle(sf::Text::Bold);
    p2nametxt.setStyle(sf::Text::Bold);
    p3nametxt.setStyle(sf::Text::Bold);
    p4nametxt.setStyle(sf::Text::Bold);
    p1scoretxt.setStyle(sf::Text::Bold);
    p2scoretxt.setStyle(sf::Text::Bold);
    p3scoretxt.setStyle(sf::Text::Bold);
    p4scoretxt.setStyle(sf::Text::Bold);

//    sf::FloatRect qrect = qtxt.getLocalBounds();
//    qtxt.setOrigin(qrect.width/2,qrect.height/2);
    qtxt.setPosition(sf::Vector2f(10,15));

//    sf::FloatRect a1rect = answer1txt.getLocalBounds();
//    answer1txt.setOrigin(a1rect.width/2,a1rect.height/2);
    answer1txt.setPosition(sf::Vector2f(10,230));

//    sf::FloatRect a2rect = answer2txt.getLocalBounds();
//    answer2txt.setOrigin(a2rect.width/2,a2rect.height/2);
    answer2txt.setPosition(sf::Vector2f(300,230));

//    sf::FloatRect a3rect = answer3txt.getLocalBounds();
//    answer3txt.setOrigin(a3rect.width/2,a3rect.height/2);
    answer3txt.setPosition(sf::Vector2f(10,365));

//    sf::FloatRect a4rect = answer4txt.getLocalBounds();
//    answer4txt.setOrigin(a4rect.width/2,a4rect.height/2);
    answer4txt.setPosition(sf::Vector2f(300,365));

//    sf::FloatRect answeringrect = answeringplyrtxt.getLocalBounds();
//    answeringplyrtxt.setOrigin(answeringrect.width/2,answeringrect.height/2);
    answeringplyrtxt.setPosition(sf::Vector2f(20,470));

//    sf::FloatRect p1nrect = p1nametxt.getLocalBounds();
//    p1nametxt.setOrigin(p1nrect.width/2, p1nrect.height/2);
    p1nametxt.setPosition(sf::Vector2f(600,10));

//    sf::FloatRect p2nrect = p2nametxt.getLocalBounds();
//    p2nametxt.setOrigin(p2nrect.width/2, p2nrect.height/2);
    p2nametxt.setPosition(sf::Vector2f(600,170));

//   sf::FloatRect p3nrect = p3nametxt.getLocalBounds();
//    p3nametxt.setOrigin(p3nrect.width/2, p3nrect.height/2);
    p3nametxt.setPosition(sf::Vector2f(600,310));

//    sf::FloatRect p4nrect = p4nametxt.getLocalBounds();
//    p4nametxt.setOrigin(p4nrect.width/2, p4nrect.height/2);
    p4nametxt.setPosition(sf::Vector2f(600,460));

//    sf::FloatRect p1srect = p1scoretxt.getLocalBounds();
//    p1scoretxt.setOrigin(p1srect.width/2, p1srect.height/2);
    p1scoretxt.setPosition(sf::Vector2f(730,85));

//    sf::FloatRect p2srect = p2scoretxt.getLocalBounds();
//    p2scoretxt.setOrigin(p2srect.width/2, p2srect.height/2);
    p2scoretxt.setPosition(sf::Vector2f(730,235));

//    sf::FloatRect p3srect = p3scoretxt.getLocalBounds();
//    p3scoretxt.setOrigin(p3srect.width/2, p3srect.height/2);
    p3scoretxt.setPosition(sf::Vector2f(730,375));

//    sf::FloatRect p4srect = p4scoretxt.getLocalBounds();
//    p4scoretxt.setOrigin(p4srect.width/2, p4srect.height/2);
    p4scoretxt.setPosition(sf::Vector2f(730,520));


    // run the program as long as the window is open
    while (window.isOpen())
      {

        switch(i%4){
          case 1: current_it = cpp_it + i; break;
          case 2: current_it = pop_it + i; break;
          case 3: current_it = history_it + i; break;
          case 4: current_it = hawaii_it + i; break;

        }


        //draw background image on screen
        window.draw(background);



        // set the string to display
        qtxt.setString(current_it->get_question());
        answer1txt.setString(current_it->get_answer(1).read_answer());
        answer2txt.setString(current_it->get_answer(2).read_answer());
        answer3txt.setString(current_it->get_answer(3).read_answer());
        answer4txt.setString(current_it->get_answer(4).read_answer());
        p1nametxt.setString(users[0].getName());
        p1scoretxt.setString(std::to_string(users[0].getScore()));
      if(*userspx >= 2){
        p2nametxt.setString(users[1].getName());
        p2scoretxt.setString(std::to_string(users[1].getScore()));
      }
      if(*userspx >= 3){
        p3nametxt.setString(users[2].getName());
        p3scoretxt.setString(std::to_string(users[2].getScore()));
      }
      if(*userspx == 4){
        p4nametxt.setString(users[3].getName());
        p4scoretxt.setString(std::to_string(users[3].getScore()));
      }
      //Write Text to screen
      window.draw(qtxt);
      window.draw(answer1txt);
      window.draw(answer2txt);
      window.draw(answer3txt);
      window.draw(answer4txt);
      window.draw(answeringplyrtxt);
      window.draw(p1nametxt);
      window.draw(p2nametxt);
      window.draw(p3nametxt);
      window.draw(p4nametxt);
      window.draw(p1scoretxt);
      window.draw(p2scoretxt);
      window.draw(p3scoretxt);
      window.draw(p4scoretxt);

      window.display();


  switch(countinput){
    case 1: answeringplyrtxt.setString("Player 1"); break;
    case 2: answeringplyrtxt.setString("Player 2");  break;
    case 3: answeringplyrtxt.setString("Player 3");  break;
    case 4: answeringplyrtxt.setString("Player 4"); break;

  }
  //Write Text to screen
  window.draw(qtxt);
  window.draw(answer1txt);
  window.draw(answer2txt);
  window.draw(answer3txt);
  window.draw(answer4txt);
  window.draw(answeringplyrtxt);
  window.draw(p1nametxt);
  window.draw(p2nametxt);
  window.draw(p3nametxt);
  window.draw(p4nametxt);
  window.draw(p1scoretxt);
  window.draw(p2scoretxt);
  window.draw(p3scoretxt);
  window.draw(p4scoretxt);

  window.display();





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

                  }


                }

       if (event.type == sf::Event::TextEntered){
          if(event.text.unicode > 96 && event.text.unicode < 101){
            lastinput = event.text.unicode;
              users[countinput].setAnswer(lastinput);
              if(lastinput == 97){
                answernum = 1;
                std::cout << "answernum: " << answernum <<std::endl;
              }
              if(lastinput == 98){
                answernum = 2;
                std::cout << "answernum: " << answernum <<std::endl;
              }
              if(lastinput == 99){
                answernum = 3;
                std::cout << "answernum: " << answernum <<std::endl;
              }
              if(lastinput == 100){
                answernum = 4;
                std::cout << "answernum: " << answernum <<std::endl;
              }
              if(current_it->get_answer(answernum).check_answer() == 1){
                  users[countinput].setScore(users[countinput].getScore() + 1);
                  std::cout << "answer correct"  << std::endl;
                }
                countinput++;
              if(countinput > *userspx){
                countinput = 1; i++;
              }
              answernum = 0;

            }

          }




        }//end event while loop
            // end the current frame
            window.display();
    }//end outer while loop

    return 0;
}
