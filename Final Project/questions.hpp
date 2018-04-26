#ifndef QUESTIONS_H
#define QUESTIONS_H
#include "answers.hpp"

class question{

  private:
    string q;
    answer a1;
    answer a2;
    answer a3;
    answer a4;

  public:

//Default Constructor
question();

//Overloaded Constructor Function
question(std::string s);

//Getter Function
std::string get_question();

//Setter Function
void set_question(std::string);

}
