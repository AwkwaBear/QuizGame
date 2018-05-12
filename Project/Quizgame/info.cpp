#include "info.hpp"

//Default Constructor
info::info(){
	right = 0;
	wrong = 0;
	total = 0;
}


//Overloaded Constructor
info::info(double r, double w, double t){
	right = r;
	wrong = w;
	total = t;
}


//Getters
double info::getR(void){
	return right;
}

double info::getW(void){
	return wrong;
}

double info::getT(void){
	return total;
}

double info::getRight(void){
	return (right/total);
}

double info::getWrong(void){
	return (wrong/total);
}

//Setters
void info::setR(double r){
	right = r;
}

void info::setW(double w){
	wrong = w;
}

void info::setT(double t){
	total = t;
}
