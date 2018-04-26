#include <iostream>
#include "answers.hpp"
#include "questions.hpp"
#include "topics.hpp"

int main(){

  topic cpp;
  std::cout << "main running" << std::endl;
  cpp.generate_topic_cpp();
std::cout << "topic fully generated" << std::endl;

  std::vector<question>::iterator it;

  for(it = cpp.get_topic().begin(); it != cpp.get_topic().end(); it++){

    std::cout << "for loop running" << std::endl;
    std::cout << it->get_question() << std::endl;


  }


}
