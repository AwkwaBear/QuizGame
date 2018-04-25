#include <iostream>
#include "questions.hpp"



std::string question::get_question(){
      return q;
    }

  void question::set_question(std::string input){
      q = input;
    }
}
