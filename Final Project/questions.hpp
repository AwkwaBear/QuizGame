#ifndef QUESTIONS_H
#define QUESTIONS_H
#include "answers.hpp"
#include <vector>

class question{

  private:
    std::string q;
    answer a1;
    answer a2;
    answer a3;
    answer a4;

  public:

//Default Constructor
question();

//Overloaded Constructor Function
question(std::string s);

//Getter Functions
std::string get_question();

answer get_answer(int i);

//Setter Function
void set_question(std::string);

//Create associated answers function
void create_answers(std::vector<std::string> txt, std::vector<std::string>::iterator txtit);
};

#endif
