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
user::user(std::string n, int sc, int st,int ans, double r, double w, double t){
	name = n;
	score = sc;
	standing = st;
	stats.setR(r);
	stats.setW(w);
	stats.setT(t);
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

//get  % of player's right answers
double rightPerc(void){
	return stats.getRight();
}

//get % of player's wrong answers
double wrongPerc(void){
	return stats.getWrong();
}


