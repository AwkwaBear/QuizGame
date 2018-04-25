#ifndef TOPICS_H
#define TOPICS_H
#include "questions.hpp"


class topic {
private:
  std::vector<question> q;

public:

  topic(vector<std::string> txt);

  void generate_topics();

}


#endif
