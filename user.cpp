#include "user.hpp"
#include "info.hpp"

//Default Constructor
user::user(){
	name = "";
	score = 0;
	standing = 0;
	answer = 0;
	info stats();
}

//Overloaded Constructor
user::user(std::string n){
	name = n;
}

//Getters
std::string user::getName(void){
	return name;
}

int user::getScore(void){
	return score;
}

int user::getStanding(void){
	return standing;
}

int user::getAnswer(void){
	return answer;
}

info user::getStats(void){
	return stats;
}

//Setters
void user::setName(std::string n){
	name = n;
}

void user::setScore(int s){
	score = s;
}

void user::setStanding(int s){
	standing = s;
}

void user::setAnswer(int a){
	answer = a;
}
void user::setStats(info s){
	stats = s;
}

double getRight(void){
	return stats.getR();
}

double getWrong(void){
	return stats.getW();
}

//get  % of player's right answers
double rightPerc(void){
	return stats.getRight();
}

//get % of player's wrong answers
double wrongPerc(void){
	return stats.getWrong();
}


