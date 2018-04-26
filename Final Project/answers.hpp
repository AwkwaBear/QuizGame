#ifndef ANSWERS_H
#define ANSWERS_H
#include <vector>
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>
#include <string>

class answer{

  private:
    std::string a;
    int correct;

  public:

  //Default Constructor
  answer();

  //overloaded constructor
  answer(std::string s);

  //function to set string for answer
  void set_answer(std::string);

  //Set correct value in Function
  void set_correct();

  //Create Answers function will take in the vector of the text file and location of the iterator
  //and generate an answer object
  //void create_answers(std::vector<std::string> s, std::string *txtit);

  //Function to check if answer is correct
  int check_answer();

};
#include "questions.hpp"

#endif
