#include <iostream>
#include "answers.hpp"
#include "questions.hpp"
#include "topics.hpp"

int main(){
//Generate Topic objects
  topic cpp;
  topic pop;
  topic history;
  topic hawaii;
int input;
//  std::cout << "main running" << std::endl;
  //Initialize Topic objects and questions/answers associated
//  cpp.generate_topic_cpp();
  pop.generate_topic_pop();
  history.generate_topic_history();
  hawaii.generate_topic_hawaii();

  std::cout << "topics fully generated" << std::endl;

  std::vector<question>::iterator it;

  for(it = pop.get_topic_begin(); it != pop.get_topic_end(); it++){

  //  std::cout << "for loop running" << std::endl;
    std::cout <<"Q: " << it->get_question() << std::endl;
    std::cout <<"A1: " <<it->get_answer(1).read_answer() << std::endl;
    std::cout <<"A2: " <<it->get_answer(2).read_answer() << std::endl;
    std::cout <<"A3: " <<it->get_answer(3).read_answer() << std::endl;
    std::cout <<"A4: " <<it->get_answer(4).read_answer() << std::endl;

    std::cout << "Enter an answer: " << std::endl;

    std::cin >> input;

    if(it->get_answer(input).check_answer() == 1){
      std::cout << "CORRECT!!" << std::endl;
    }
    else{
      std::cout << "Answer is wrong" << std::endl;
    }

  }


}
