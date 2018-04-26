#include <iostream>
#include "answers.hpp"


//Default Constructor
answer::answer(): a(" "), correct(0){}

//Overloaded Constructor
answer::answer(std::string s): a(s), correct(0){}

//function to set
void answer::set_answer(std::string s){
  this->a = s;
}

//Set as correct answer
void answer::set_correct(){
  this->correct = 1;
}

/*
//Create Answers function will take in the vector of the text file and location of the iterator
void answer::create_answers(std::vector<std::string> txt, std::string *txtit){

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

  //the a for loop will iterate through the order array and
  //set the answers to follow the permutation
      for(int i = 1; i <= 4; i++){

        answer input(*txtit);

        if(i = 4){
          input.set_correct();
        }

      switch(*orderit){
        case 1: question->a1 = input; txtit++;
          break;
        case 2: question->a2 = input; txtit++;
          break;
        case 3: question->a3 = input; txtit++;
          break;
        case 4: question->a4 = input; txtit++;
          break;
      }

      orderit++; //iterate the order iterator
      }
    }//end function
*/
int answer::check_answer(){
      return this->correct;
      }
