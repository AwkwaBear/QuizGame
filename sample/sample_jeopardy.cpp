#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;


void letters(string QL[][5],char filename[]) // This adds all the letters to the matrix. u can also use a this to add all the questions to their matrix and answers to theirs.
{
    ifstream fin (filename, ios::in);
    for(short i=0;i<5;i++)
    {
        for(short j=0;j<5;j++)
     {
        fin >> QL[i][j];
}
}
fin.close();
fin.clear();
}
void points(string Q[][5]) // This adds all the points to the matrix. u can also use a this to add all the questions to their matrix and answers to theirs.
{ string p;
    ifstream fin ("points.txt", ios::in);
    for(short i=0;i<5;i++)
    { fin>>p;
        for(short j=0;j<5;j++)
     {
        Q[i][j]=p;
      }
      }
fin.close();
fin.clear();
}
void ask(string q,string a,int &knows,bool& correct,string p[] )
{
string ans;
int prev=knows;
cout<<q<<endl<<p[0]<<" enter 0, "<<p[1]<<" enter 1 to indicate you know the answer: ";
cin>>knows;
cout<<"OK "<<p[knows]<<" what is the answer: ";
cin>>ans;
if(a.compare(ans)==0)
        {correct=true;
        cout<<"That is correct\n";
        }
else
        {correct=false;
        cout<<"That is incorrect\n";
        knows=prev;
        }
for(int i=0;i<400000000;i++);
}
int main()
{string Q[5][5],QL[5][5];//QL is being used to store the letters this way we can compare the position of the letter in the matrix to the position of the question in the Q matrix.
string ans[5][5],quest[5][5];
    string a, b;
    int turn=0,count=25;
    bool correct;
    string P[2]; // player names
    short S[2]={0,0}; // score variables
    int i,j;
    char l;
    letters(QL,"letters.txt");
    points(Q);
    letters(ans,"answers.txt");
    letters(quest,"questions.txt");

    cout << "Welcome to Jeopardy!" << endl;
    cout << "Enter the name for Player 1: " << endl;
    cin >> P[0];
    cout << "Enter the name for Player 2: " << endl;
    cin >> P[1];
    system("cls");
    cout << "Welcome " << P[0] << " and " << P[1] << "! Let's play Jeopardy!" << endl;
    for(i=0;i<800000000;i++);
    system("cls");
    do{
    system("cls");


cout << "|===========================================================|\n";
cout << "|    C++    |   Sports | Celebrity |   Music   | Movies   |\n";
cout << "|===========|===========|===========|===========|===========|\n";
for(i=0;i<5;i++)
    {for(j=0;j<5;j++)
         {cout<<"|   "<<Q[i][j];
         if(QL[i][j].compare(" ")==0)
              cout<<" "<<QL[i][j]<<"    ";
         else
             cout<<" ("<<QL[i][j]<<") ";
         }
    cout<<"|\n";
    if(i!=4)
        cout << "|-----------|-----------|-----------|-----------|-----------|\n";
    }
cout << "|===========|===========|===========|===========|===========|\n";
for(i=0;i<2;i++)
    {cout << P[i]<<" Score: " << S[i];
    if(i==0)
       cout<<"         |||||| |     ";
    else
       cout<<"|\n";
       }
do
{
cout << P[turn]<<" Please choose a letter from the board \n";
cin>>l;
i=(l-'a')/5;
j=(l-'a')%5;
}while(QL[i][j].compare(" ")==0);
ask(quest[i][j],ans[i][j],turn,correct,P);
if(correct)
    S[turn]+=(i+1)*100;
Q[i][j]=" ";
QL[i][j]=" ";


    }while(--count>0);
system("pause");
return 0;
}
