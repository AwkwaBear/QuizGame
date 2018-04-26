#include <iostream>
#include <queue>

#include "user.hpp"
#include "info.hpp"

int main(){
int numPlayers;

//Enter number of Players
std::cout << "Enter the number of players: ";
std::cin >> numPlayers;
while(numPlayers < 0 || numPlayers > 4){
    std::cout << "Invalid number of players." << std::endl;
    std::cout << "Enter the number of players: ";
    std::cin >> numPlayers;
}

//Create Players
std::queue <user> playerQueue;
user p;
for(int i=0; i < numPlayers; i++){
   numberQueue.push(p);
}

//Select category

//Play Game
while(questions > 0){

}

}
