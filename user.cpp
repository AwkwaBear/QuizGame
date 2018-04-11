#include "user.hpp"

//Default Constructor
user::user(){
	name = "";
	score = 0;
	standing = 0;
	stats info();
}

//Overloaded Constructor
user::user(std::string n, int sc, int st, double r, double w, double t){
	name = n;
	score = sc;
	standing = st;
	info.setR(r);
	info.setW(w);
	infor.setT(t);
}

//perform deep copy & allocate new memory
user::user(const user& other){

}

//takes contents of another user an clears info of other user
user::user(user&& other){

}

//deallocates memory
user::~user(){

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

stats user::getStats(void){
	return info;
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

void user::setStats(stats s){
	info = s;
}

//get  % of player's right answers
double rightPerc(void){
	return info.getRight();
}

//get % of player's wrong answers
double wrongPerc(void){
	return info.getWrong();
}


