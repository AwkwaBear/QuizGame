#ifndef ANSWERS_H
#define ANSWERS_H

#include "topics.hpp"
#include "questions.hpp"

class answer{
  private:
    std::string a;
    int correct;

  public:

    //Create Answers function will take in the vector of the text file and location of the iterator
    //and generate an answer object
    create_answers(vector<std::string> s, std::string *txtit);

    check_answer(int input, Question *q);

  }

#endif
