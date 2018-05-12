#include "intro.hpp"
#include "enter_users.hpp"
#include "enter_names.hpp"
#include "user.hpp"
#include "gamescreen.hpp"
#include "end.hpp"
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>


int main(){

  // create the window
  sf::RenderWindow window(sf::VideoMode(800, 600), "Quiz Game");
  window.setFramerateLimit(60);

  int gamestate = 1;
  int players = 0;
  int * playerspx = &players;
  std::vector<std::string> names;
  std::vector<std::string>::iterator it;
  std::vector<user> users;
  std::vector<user>::iterator uit;
  user p;
  int i = 0;
  sf::Event event;
  while (window.isOpen())
    {
      if(gamestate == 1){
      gamestate = intro(window);
      }
      std::cout << "back to main gamestate is: " << gamestate << std::endl;
      if(gamestate == 2){
        gamestate = enter_users(window,playerspx);
        window.clear(sf::Color::Black);
        // end the current frame
        window.display();
      }

      std::cout <<"back to main gamestate is: " << gamestate <<"  users selected: " << *playerspx << std::endl;
      // "close requested" event: we close the window
      if(gamestate == 3){
        gamestate = enter_names(window,playerspx,names);
        window.clear(sf::Color::Black);
        // end the current frame
        window.display();
      }
      std::cout <<"back to main gamestate is: " << gamestate <<"  users entered: " << std::endl;

      for(it = names.begin(); it != names.end(); it++){
        i++;
        p = user(*it);
        users.push_back(p);
        std::cout << "name player #" << i << ": " << *it << std::endl;
      }
      for(uit = users.begin(); uit != users.end(); uit++){
        std::cout<< "user in stack" << uit->getName() << std::endl;
      }
      if(gamestate == 4){
        gamestate = gamescreen(window, users, playerspx);
        window.clear(sf::Color::Black);
        // end the current frame
        window.display();
      }
      if(gamestate == 5){
        gamestate = end(window);
      }

      if (event.type == sf::Event::Closed || gamestate == 4){//begin if
          window.close();
        }//end if
    }
}
