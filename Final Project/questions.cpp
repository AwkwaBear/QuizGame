#include <iostream>
#include "questions.hpp"

question::question(std::string s) : q(s) {}



std::string question::get_question(){
      return q;
    }

  void question::set_question(std::string input){
      q = input;
    }
}
