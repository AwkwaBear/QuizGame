#include <iostream>
#include "topics.hpp"
#include "answers.hpp"
#include "questions.hpp"

int main(){

  topic cpp;

  cpp->topic = generate_topic_cpp();

  std::vector<std::string>::iterator it;

  for( it = cpp->topic.begin(); it != NULL; it++){

    std::cout << *it->q << endl;

  }


}
