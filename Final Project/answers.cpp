#include <iostream>
#include "answers.hpp"


//Default Constructor
answer::answer(): a(" "), correct(0){}

//Overloaded Constructor
answer::answer(std::string s): a(s), correct(0){}

//function to set
void answer::set_answer(std::string s){
  this->a = s;
}

//read answer Function
std::string answer::read_answer(){
  return a;
}

//Set as correct answer
void answer::set_correct(){
  this->correct = 1;
}


//Function to determine if answer is correct
int answer::check_answer(){
      return this->correct;
      }
