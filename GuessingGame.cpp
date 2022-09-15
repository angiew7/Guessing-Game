/*
 Angie Wang Guessing Game 9/13/2022
  C++ rules:
1. No global variables
2. No strings
3. You should include  <iostream> not stdio
4. Avoid using a mouse
*/
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
  bool running = true;
  while(running == true){
    //random seed
    srand(time(NULL));
    int number = rand()%100;
    cout << number;
    cout << "Guess a number between 1-50" << endl;
    int input = -1;
    int tries = 0;
    while(input != number){
      cin >> input;
      tries = tries +1;
      if(input == number){
	cout << "You got it right!" << endl;
	cout << "Tries:" << tries << endl;
      }
      else if(input > number){
	cout << "Your guess is higher than the number!" << endl;
      }
      else if(input < number){
	cout << "Your guess is lower than the number!" << endl;
      }
    }
    cout<< "Do you want to try again? y/n" << endl;
    char ans;
    cin >> ans;
    if (ans == 'y')
      running = true;
    else if (ans == 'n')
      running = false;
  }
  return 0;
}
