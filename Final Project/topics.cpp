#include <iostream>
#include "topics.hpp"

//this function will call create a topic which holds a vector
//of questions which each contain 4 Answers
//the function reads in a .txt file and stores each line in a
//slot of a vector which are then passed in order to create the questions and answers which are stored in the topic vector

std::vector<question> topic::generate_topic_cpp(){ //begin function

  //create string to store current line
  std::string line;

  //create vector to store lines of text
  std::vector<std::string> txt;

  //create iterator for vector above and initiailize at     start of vector
  std::vector<std::string>::iterator txtit = txt.begin();

  //create topic object to store questions
  topic t;

  //create ifstream for applicable file
  std::ifstream myfile ("c++.txt");

  //In case file is not opened
  if(!myfile){//begin if
    std::cout<<"Error opening output file"<< std::endl;
          system("pause");
          return -1;
      }//end if

  //While loop will read in file and store in a vector
  while(std::getline(myfile, line)){//begin while

   txt.push_back(line);

    }//end while

//Iterate through array and store each question and answer
//until no more lines of text remain
  while(txtit != NULL){//begin while

    //initialize a variable for current question being       generated
    question current;

    //use string to create a question and iterate to next line
    current.set_question(*txtit);
    txtit++;

    //use subsequent lines of text to generate 4 answers
    //and iterate pointer accordingly
    current->a1.create_answers(txt, txtit);
    txtit += 4;


    //push question into topic's vector
    topic.push_back(current);

  }//end while

return topic;

}//end function
