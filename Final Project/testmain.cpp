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

  for(it = cpp.get_topic_begin(); it != cpp.get_topic_end(); it++){

  //  std::cout << "for loop running" << std::endl;
    std::cout <<"Q: " << it->get_question() << std::endl;
    std::cout <<"A1: " <<it->get_answer(1).read_answer() << std::endl;
    std::cout <<"A2: " <<it->get_answer(2).read_answer() << std::endl;
    std::cout <<"A3: " <<it->get_answer(3).read_answer() << std::endl;
    std::cout <<"A4: " <<it->get_answer(4).read_answer() << std::endl;

    std::cout << std::endl;

  }


}
