#include "stats.hpp"

//Default Constructor
stats::stats(){
	right = 0;
	wrong = 0;
	total = 0;
}

//Overloaded Constructor
stats::stats(double r, double w, double t){
	right = r;
	wrong = w;
	total = t;
}

//Getters
double stats::getR(void){
	return right;
}

double stats::getW(void){
	return wrong;
}

double stats::getT(void){
	return total;
}

double stats::getRight(void){
	return (right/total);
}

double stats::getWrong(void){
	return (wrong/total);
}

//Setters
void stats::setR(double r){
	right = r;
}

void stats::setW(double w){
	wrong = w;
}

void stats::setT(double t){
	total = t;
}
