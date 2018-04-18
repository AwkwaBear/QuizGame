#include <iostream>
#include <stdio.h>
#include <curses.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <unistd.h>

      unsigned int sleep(unsigned int seconds);
 using namespace std;
int main()
{
	 int m, s,h;
	 cout << "A COUNTDOWN TIMER " << endl;

	// cout << "enter im in seconds here" << endl;
	 //cin >> s;
	 cout << " A COUNTDOWN TIMER" << endl;
	 cout << "time remaining" << endl;
	 cout << " secs : " << s << endl;
			for (int sec = s; sec >= 0; sec--)
			{
				if ( sec == 0 )
					s = 59;
				usleep(1000000);
			//	system("cls");
				cout << sec  << endl;
			}

	//usleep(1000000);
	 cout << "THE END" << endl;

	return 0;
}
