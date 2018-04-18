#include <iostream>
#include <string>
#include <vector>

class question{
  private:
    string q;
    answer a1;
    answer a2;
    answer a3;
    answer a4;
  public:
}

class answer{
  private:
    string a;
    int correct;
  public:
    create_answers(){
      vector <int> order;

      for(int i = 1; i <= 4; i++){
        order.push_back(i);
      }

      std::random_shuffle(order.begin(), order.end());

      vector<int>::iterator it;

      for(int i = 1; i <= 4; i++){
        answer input("read in text for the answer");
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

    check_answer(int input, Question *q){
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
