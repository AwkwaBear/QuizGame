#ifndef ANSWERS_H
#define ANSWERS_H

#include "topics.hpp"
#include "questions.hpp"

class answer{
  private:
    std::string a;
    int correct;

  public:
  //overloaded constructor
  answer(std::string s);

  //function to set string for answer
  void set_answer(std::string);

  //Set correct value in Function
  void set_correct();

  //Create Answers function will take in the vector of the text file and location of the iterator
  //and generate an answer object
  void create_answers(vector<std::string> s, std::string *txtit);

  //Function to check if answer is correct
  bool check_answer(int input, answer a);

  }

#endif
