/*File: user.hpp
 *
 */
#ifndef USER_H
#define USER_H

#include "info.hpp"
#include <string>

class user{
    private:
        std::string name;
        int score;
        int standing;
	       int answer; //interacts w/Question/Answer class
        info stats; //make class for this

   public:
	//Default Constructor
        user();

	//Overloaded Constructor
	user(std::string n);

  void addpoint(void);

        //Get functions
        std::string getName(void);
        int getScore(void);
        int getStanding(void);
	      int getAnswer(void);
        info getStats(void);

        //Set functions
        void setName(std::string n);
        void setScore(int s);
        void setStanding(int s);
	void setAnswer(int a);
        void setStats(info s);


};

#endif
