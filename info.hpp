/*File: info.hpp
 *
 */

class info{

public:

	//Default Constructor
	info();

	//Overloaded Constructor
	info(double r, double w, double t);

	//Getters
	double getR(void);
	double getW(void);
	double getT(void);
	double getRight(void);
	double getWrong(void);

	//Setters
	void setR(double r);
	void setW(double w);
	void setT(double t);

private:
	
	double right;
	double wrong;
	double total;

};
