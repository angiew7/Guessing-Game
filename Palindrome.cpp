/*
  Angie Wang
  9/24/2022
  User inputs a word/sentence, program removes punct and spaces, ouputs whether
  its a palindrome or not
*/
#include <iostream>
#include <cstring>
using namespace std;

int main(){
  char str[80];
  char backwards[80];
  cin.getline(str, 80, '\n');
  int length = 0;
  int x=0;
  char ch = str[0];

  //covert lowercase
  for(int i = 0; i <= strlen(str); i++){
    str[i] = tolower(str[i]);
  }
  
  //put all the non punct and space chars in an array
  for (int i = 0; i <= strlen(str); i++){
    ch = str[i];
    if(!isspace(ch)){
      if(!ispunct(ch)){
	backwards[x] = ch;
	//cout<< backwards[x];
	x++;
      }
    }
   }
  
  //for(int i = 0; '\0' != backwards[i]; i++){
  // length = i;
  //}
  
  length = strlen(backwards) -1;
  int count = 0;
  //count each letter that matches
  //if at the end of the string = beggining letters
  for(int i = 0; i <= length; i++){
    if(backwards[i] != '\0'){
      if(backwards[length-i] == backwards[i]){
	count++;
      }
      //  cout << backwards[length-i] << endl;
    }
  }
  length = strlen(backwards);
  //if all the letters match
  if(count == length){
    cout << "Palindrome!";
  }
  else if(count != length){
    cout << "Not a palindrome.";
  }
  
  return 0;
}
