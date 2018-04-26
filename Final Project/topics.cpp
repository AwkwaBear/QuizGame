#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "answers.hpp"
#include "questions.hpp"
#include "topics.hpp"


std::vector<question> topic::get_topic(){
  std::cout << "topic getted" << std::endl;
  return this->questions;
}


//this function will call create a topic which holds a vector
//of questions which each contain 4 Answers
//the function reads in a .txt file and stores each line in a
//slot of a vector which are then passed in order to create the questions and answers which are stored in the topic vector


void topic::generate_topic_cpp(){//begin function

  //create string to store current line
  std::string line;

  //create vector to store lines of text
  std::vector<std::string> txt;


  //create ifstream for applicable file
  std::ifstream myfile ("c++.txt");

  //In case file is not opened
  if(!myfile){//begin if
    std::cout << "Error opening output file" << std::endl;

      }//end if

  //While loop will read in file and store in a vector
  while(std::getline(myfile, line)){//begin while
std::cout << "reading file" << std::endl;
   txt.push_back(line);

    }//end while

std::cout << "topic generating" << std::endl;
  //create iterator for vector above and initiailize at start of vector
  std::vector<std::string>::iterator txtit = txt.begin();

//Iterate through array and store each question and answer
//until no more lines of text remain
  while(txtit != txt.end()){//begin while
    std::cout << "txtit while loop running" << std::endl;
    //initialize a variable for current question being       generated
    question current;

    //use string to create a question and iterate to next line
    current.set_question(*txtit); std::cout << current.get_question() << std::endl;
    txtit++;

    //use subsequent lines of text to generate 4 answers
    //and iterate pointer accordingly
    current.create_answers(txt, txtit);
    txtit += 4;


    //push question into topic's vector
    questions.push_back(current);

  }//end while


}//end function
