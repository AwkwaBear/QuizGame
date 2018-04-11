/*File: user.hpp
 *
 */

class user{
    private:
        std::string name;
        int score;
        int standing;
        stats info; //make class for this

   public:
	//Default Constructor
        user();

	//Overloaded Constructor
	user(std::string n, int sc, int st, double r, double w, double t);
        //performs deep copy & allocates new memory
        user(const user& other);

        //Takes contents of another user and clears info of other user
        user(user&& other);

        //deallocate memory
        ~user();

        //Get functions
        std::string getName(void);
        int getScore(void);
        int getStanding(void);
        stats getStats(void);

        //Set functions
        void setName(std::string n);
        void setScore(int s);
        void setStanding(int s);
        void setStats(stats s);

	//get  % of player's right answers
	double rightPerc(stats s);

	//get % of player's wrong answers
	double wrongPerc(stats s);

};
