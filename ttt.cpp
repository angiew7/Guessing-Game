/*
Angie Wang 
9/29/2022
2 Player Tic Tac Toe. Outputs number of wins and ties, and asks if you want to play again.
*/
#include <iostream>
#include <cstring>

using namespace std;
int board[3][3];
const int BLANK = 0;
const int X_MOVE = 1;
const int O_MOVE = 2;
const int X_TURN = 0;
const int O_TURN = 1;
int turn = X_TURN;
char yesno = ' ';
int xWins= 0;
int oWins = 0;
void printBoard();
bool checkWin(int player);
bool checkTie();
void resetGame();

int main(){
  bool stillPlaying = true;
  while(stillPlaying == true){
    //play while no one wins
    while(checkWin(X_MOVE) == false && checkWin(O_MOVE) == false && checkTie() == false){
      
	printBoard();
	char x;
	//cin.getline(input, 3, '\n');
	char y;
	//get input
	cin >> x;
	cin >> y;
	//    cout << row << ',' << column << endl;
	if(x != 'a' && x!= 'b' && x!= 'c'){
	  cout << "Please enter the row number first. Row number must be an a, b or c."<< endl;
	}
	else if(y != '1' && y!= '2' && y != '3'){
	  cout << "Please enter the column number second. Column number must be a 1, 2, or 3" << endl;
	}
	else{
	  int row = x - 'a';
	  int column = y - '1';
	  if(board[row][column] == BLANK){
	    //X Turn
	    if (turn == X_TURN){
	      board[row][column] = X_MOVE;
	      turn = O_TURN;
	    }
	    else if (turn == O_TURN){
	      board[row][column] = O_MOVE;
	      turn = X_TURN;
	    }
	  }
    
    
	  else{
	    cout << "There is already a piece there!" << endl;
	  }
	}
      }
    printBoard();
    //checks who won or tie
    if(checkWin(X_MOVE) == true){
      cout << "X Wins!"<< endl;
      xWins = xWins + 1;
    }
    else if(checkWin(O_MOVE) == true){
      cout << "O Wins!" << endl;
      oWins = oWins +1;
    }
    else if(checkTie() == true){
      cout << "You tied!" << endl;
    }
    
    //counted wins
    cout << "X # of wins: " << xWins << endl;
    cout << "O # of wins: " << oWins << endl;

    //play again?
    cout << "Play again? (y/n)" << endl;
    cin >> yesno;
    
    //game will reset if user inputs y for yes
    if(yesno == 'y'){
      resetGame();
      stillPlaying = true;
    }
    if(yesno == 'n'){
      stillPlaying = false;
    }
  }
      

  return 0;
}

//prints out the tic tac toe board
void printBoard(){
  cout << "\t1\t2\t3" << endl;
  for(int row = 0; row < 3; row++){
    char output = char('a' + row);
    cout << output << '\t';
    for(int column = 0; column < 3; column++){
      if(board[row][column] == BLANK){
	cout << '\t';
      }
      else if (board[row][column] == X_MOVE){
	cout << "X\t";
      }
      else if (board[row][column] == O_MOVE){
	cout << "O\t";
      }
    }
    cout << ' ' << endl;
    
  }
}

//check wins for both players
bool checkWin(int player){
  //right column
  if(board[0][0] == player && board[0][1] == player && board[0][2] == player){
    return true;
  }
  //diagonal
  else if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
    return true;
  }
  //top row
  else if(board[0][0] == player && board[1][0] == player && board[2][0] == player){
    return true;
  }
  //mid column
  else if(board[1][1] == player && board[1][0] == player && board[1][2] == player){
    return true;
  }
  //mid row
  else if(board[1][1] == player && board[0][1] == player && board[2][1] == player){
      return true;
    }
  //diagonal
    else if (board[0][2] ==player && board[1][1] == player && board[2][0] == player){
      return true;
    }
    //bot column
    else if (board[0][2] == player && board[1][2] == player && board[2][2] == player){
      return true;
    }
    //bot row
    else if(board[2][2] == player && board[2][1] == player && board[2][0] == player){
      return true;
    }
  
  return false;  
}

//check ties by checking for any blank spaces
  bool checkTie(){
    for(int row = 0; row < 3; row++){
      for(int column = 0; column < 3; column++){
	if(board[row][column] == BLANK){
	  return false;
	}
      }
    }
    return true;
  }

//turns every move to blank
  void resetGame(){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j< 3; j++){
	board[i][j] = BLANK;
      }
    }
    turn = X_TURN;
  }
