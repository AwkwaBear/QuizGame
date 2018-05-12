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
  topic choice;

int input;
//  std::cout << "main running" << std::endl;
  //Initialize Topic objects and questions/answers associated

  cpp.generate_topic_cpp();
  pop.generate_topic_pop();
  history.generate_topic_history();
  hawaii.generate_topic_hawaii();

//  std::cout << "topics fully generated" << std::endl;

  std::vector<question>::iterator it;

  std::cout << "Choose a Topic:" << std::endl;
  std::cout << "'1' for C++ Questions" << std::endl;
  std::cout << "'2' for Pop Culture Questions" << std::endl;
  std::cout << "'3' for US History Questions" << std::endl;
  std::cout << "'4' for Hawaii Questions" << std::endl << std::endl;
  std::cin >> input;
  switch(input){
    case 1: choice = cpp; break;
    case 2: choice = pop; break;
    case 3: choice = history; break;
    case 4: choice = hawaii; break;
  }

 std::cout << std::endl << std::endl;

  for(it = choice.get_topic_begin(); it != choice.get_topic_end(); it++){

  //  std::cout << "for loop running" << std::endl;
    std::cout <<"Q: " << it->get_question() << std::endl;
    std::cout <<"1: " <<it->get_answer(1).read_answer() << std::endl;
    std::cout <<"2: " <<it->get_answer(2).read_answer() << std::endl;
    std::cout <<"3: " <<it->get_answer(3).read_answer() << std::endl;
    std::cout <<"4: " <<it->get_answer(4).read_answer() << std::endl << std::endl;

    std::cout << "Enter an answer: (or 0 to quit)" << std::endl;

    std::cin >> input;

    if(input == 0)
      return 0;

    if(it->get_answer(input).check_answer() == 1){
      std::cout << "CORRECT!!" << std::endl;
      std::cout << std::endl << std::endl;
    }
    else{
      std::cout << "Answer is wrong. Correct answer is: " << std::endl;
      for(int i = 1; i <= 4; i++){
        if(it->get_answer(i).check_answer() == 1){
          std::cout << it->get_answer(i).read_answer() << std::endl;
          std::cout << std::endl << std::endl;
        }
      }
    }

  }


}
