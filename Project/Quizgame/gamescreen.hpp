#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#include "user.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <string>
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>

int gamescreen(sf::RenderWindow &window, std::vector<user> users, int * userspx);


#endif
