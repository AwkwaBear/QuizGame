#include "answers.hpp"

//Create Answers function will take in the vector of the text file and location of the iterator
void answer::create_answers(vector<std::string> s, std::string *txtit){ 

  //The below section will produce a random permutation of slots 1-4 for the answers to be displayed

  //A vector is generated and numbers 1-4 are pushed in as the elements via 'for' loop
    vector <int> order;

    for(int i = 1; i <= 4; i++){
        order.push_back(i);
      }
  //randomizer function is called to reorder the numbers into a random permutation
      std::random_shuffle(order.begin(), order.end());

  //an iterator is created for navigating the vector
      vector<int>::iterator it;

  //the a for loop will iterate through the
      for(int i = 1; i <= 4; i++){

        answer input();
        if(i = 4){input->correct = 1;}

      switch(*it){
        case 1: question->a1 = input;
          break;
        case 2: question->a2 = input;
          break;
        case 3: question->a3 = input;
          break;
        case 4: question->a4 = input;
          break;
      }

      it++;
      }
    }

bool check_answer(int input, Question *q){
      switch(input){
        case 1: if (question->a1->correct == 1) {
                      return true;
                    }
                else{
                return false;
              }
        case 2: if (question->a2->correct == 1) {
                      return true;
                    }
                else{
                return false;
              }
        case 3: if (question->a3->correct == 1) {
                      return true;
                    }
                else{
                return false;
              }
        case 4: if (question->a4->correct == 1) {
                      return true;
                    }
                else{
                return false;
              }
      }
    }
}
