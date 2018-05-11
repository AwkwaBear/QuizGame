#include "intro.hpp"
#include "enter_users.hpp"
#include "enter_names.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

int main(){

  // create the window
  sf::RenderWindow window(sf::VideoMode(800, 600), "Quiz Game");
  window.setFramerateLimit(15);

  int gamestate = 1;
  int players = 0;
  int * playerspx = &players;
  std::vector<std::string> names;

  sf::Event event;
  while (window.isOpen())
    {
      if(gamestate == 1){
      gamestate = intro(window);
      }
      std::cout << "back to main gamestate is: " << gamestate << std::endl;
      if(gamestate == 2){
        gamestate = enter_users(window,playerspx);
      }

      std::cout <<"back to main gamestate is: " << gamestate <<"  users selected: " << *playerspx << std::endl;
      // "close requested" event: we close the window
      if(gamestate == 3){
        gamestate = enter_names(window,playerspx,names);
      }

      if (event.type == sf::Event::Closed || gamestate == 0){//begin if
          window.close();
        }//end if
    }
}
