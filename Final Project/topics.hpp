#ifndef TOPICS_H
#define TOPICS_H
#include "questions.hpp"
#include <vector>



class topic{

private:
  std::vector<question> topic;

public:

std::vector<question> generate_topic_cpp();

//topic generate_topic_hawaii();

//topic generate_topic_history();

//topic generate_topic_popculture();


};


#endif
