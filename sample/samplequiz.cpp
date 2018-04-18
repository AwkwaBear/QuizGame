#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <random>
#include <stdio.h>
#include <curses.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <unistd.h>

namespace {
    const int s_questionScore = 10;  // Points rewarded for each correct answer.
    const int s_failingGrade = 60;
    const int s_numQuestions = 10;
    const char* s_winMessage = "Correct!\n";
    const char* s_loseMessage = "Incorrect, the correct answer was ";
    const char* s_promptAnswer = "What is your answer?\n";
}

class Question {
public:
    int askQuestion(int num = -1);
    friend std::istream& operator >> (std::istream& is, Question& ques);

private:
    std::string question_text;
    std::string answer_1;
    std::string answer_2;
    std::string answer_3;
    std::string answer_4;
    char correct_answer;
};

void PrintArt(std::ifstream myfile);
void InititializeQuizGame(std::ifstream data);
void load(std::istream& is, std::vector<Question>& questions);
void Shuffle(std::vector<Question>& questions);
void PrintResults(std::vector<Question>& questions);
void clearScreen();
void PositionCursor();

int main()
{
    PrintArt(std::ifstream("welcome.txt"));
    InititializeQuizGame(std::ifstream("quiz_data.txt")); //Load questions from .txt file

    return 0;
}

void PrintArt(std::ifstream myfile)
{
    std::string line;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            std::cout << line << '\n';
        }
        myfile.close();
        std::cin.get();
        clearScreen();
    }
    else
    {
        std::cout << "Error: File not found!\n";
    }
}

void InititializeQuizGame(std::ifstream data)
{
    if (data.is_open())
    {
        std::vector<Question> questions;
        load(data, questions);
        Shuffle(questions);
        PrintResults(questions);
    }
    else
    {
        std::cout << "Error: File not found!\n";
    }
    std::cin.get();
}

std::istream& operator >> (std::istream& is, Question& ques)
{
    std::string line;
    while (std::getline(is, line))
    {
        if (line.size() == 0)
            continue;
        break;
    }
    ques.question_text = line;
    getline(is, ques.answer_1);
    getline(is, ques.answer_2);
    getline(is, ques.answer_3);
    getline(is, ques.answer_4);

    is >> ques.correct_answer;
    return is;
}

void load(std::istream& is, std::vector<Question>& questions)
{
    Question q;
    while (is >> q)
        questions.push_back(q);
}

int Question::askQuestion(int num) //Ask the question.
{
    int score = 0;
    int s = 5;
    int sec;
    char guess = ' ';
    std::cout << "\n";
    if (num > 0)
        std::cout << num << ".) ";
    std::cout << question_text << "\n";
    std::cout << "a. " << answer_1 << "\n";
    std::cout << "b. " << answer_2 << "\n";
    std::cout << "c. " << answer_3 << "\n";
    std::cout << "d. " << answer_4 << "\n";

    //Ask user for their answer.
    std::cout << s_promptAnswer;
    for (int sec = s; sec >= 0; sec--)
    {



      usleep(1000000);
      std::cout << sec  << std::endl;

    }

    if ( sec == 0 ){
      s = 59;
      guess = 'z';

      std::cout << s_loseMessage << correct_answer << ".\n";
      std::cin.get();
      std::cin.get();
      usleep(100000);
      return score;
    }
    else
    {
      //PositionCursor();
      std::cin >> guess;
      if (guess == correct_answer) {
      std::cout << s_winMessage;
      score = s_questionScore;
      std::cin.get();
      std::cin.get();
    }
    else
    {
        std::cout << s_loseMessage << correct_answer << ".\n";
        std::cin.get();
        std::cin.get();
    }

    usleep(100000);
    return score;
  }

}

void Shuffle(std::vector<Question>& questions) //Shuffle the questions.
{
    std::random_device rd;
    std::mt19937 randomGenerator(rd());
    std::shuffle(questions.begin(), questions.end(), randomGenerator);
}

void PrintResults(std::vector<Question>& questions)
{
    int total = 0; //Total score.

    //Keep track of score.
    for (size_t i = 0; i < s_numQuestions; ++i)
    {
        total += questions[i].askQuestion(i + 1);
    }
    //Print Total score.
    clearScreen();
    if (total >= s_failingGrade) {
        std::cout << "\n\n";
        std::cout << "You scored " << total << " out of 100!\n";
        PrintArt(std::ifstream("quiz_passed.txt"));
    }
    else
    {
        std::cout << "You scored " << total << " out of 100....\n";
        std::cout << "Sorry, you failed... Better luck next time.\n";
        PositionCursor();
    }
}

void clearScreen()
{
    std::cout << std::string(22, '\n');
}

void PositionCursor()
{
    std::cout << std::string(22, '\n');
}
