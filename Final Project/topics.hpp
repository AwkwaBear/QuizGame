#ifndef TOPICS_H
#define TOPICS_H
#include "questions.hpp"
#include <vector>



class topic{

private:
  std::vector<question> questions;

public:
//Getter for overall topic vector beginning
std::vector<question>::iterator get_topic_begin();

std::vector<question>::iterator get_topic_end();
//Initializer for Topic on C++
void generate_topic_cpp();

void generate_topic_hawaii();

void generate_topic_pop();

void generate_topic_history();


};


#endif
