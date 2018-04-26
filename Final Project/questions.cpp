#include <iostream>
#include "questions.hpp"

question::question(std::string s) : q(s) {}



std::string question::get_question(){
      return q;
    }

  void question::set_question(std::string input){
      q = input;
    }

  //Create Answers function will take in the vector of the text file and location of the iterator
  void question::create_answers(std::vector<std::string> txt, std::string *txtit){

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
