#include <iostream>
#include "questions.hpp"

question::question(): q(" "){std::cout << "blank question created" << std::endl;}

question::question(std::string s) : q(s) {std::cout << "actual question generated" << std::endl;}



std::string question::get_question(){
  std::cout << "get question called" << std::endl;

      return q;
    }

  void question::set_question(std::string input){
    std::cout << "set question called" << std::endl;
      q = input;
    }

  answer question::get_answer(int i){
    std::cout << "get answer called" << std::endl;
    switch(i){//begin switch
      case 1: return this->a1;

      case 2: return this->a2;

      case 3: return this->a3;

      case 4: return this->a4;

    }//end switch

  }//end function


  //Create Answers function will take in the vector of the text file and location of the iterator
  void question::create_answers(std::vector<std::string> txt, std::vector<std::string>::iterator txtit){

    std::cout << "create answers called" << std::endl;

    //The below section will produce a random permutation of slots 1-4 for the answers to be displayed

    //A vector is generated and numbers 1-4 are pushed in as the elements via 'for' loop
      std::vector<int> order;

      for(int i = 1; i <= 4; i++){
          order.push_back(i);
        }
    //randomizer function is called to reorder the numbers into a random permutation
        std::random_shuffle(order.begin(), order.end());

    //an iterator is created for navigating the order vector
        std::vector<int>::iterator orderit;

    //the a for loop will iterate through the order array andquestion
    //set the answers to follow the permutation
        for(int i = 1; i <= 4; i++){

          answer input(*txtit);

          if(i = 4){
              input.set_correct();
          }

        switch(*orderit){
          case 1: this->a1 = input; txtit++;
            break;
          case 2: this->a2 = input; txtit++;
            break;
          case 3: this->a3 = input; txtit++;
            break;
          case 4: this->a4 = input; txtit++;
            break;
        }

        orderit++; //iterate the order iterator
      }//end for
    }//end function
