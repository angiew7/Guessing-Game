#include <iostream>
#include <cstring>
//#include <time.h>
#include "Node.h"
#include <fstream>
#include<stdio.h>
#include<ctype.h>

using namespace std;
Node* head = NULL;
void Add(Node* current, int num);
void Print(Node* current, int depth);
void Search(Node* current, int num);
void Delete(Node* current, Node* prev, int num);
int main(){
  //  srand(time(NULL));
  char input[20];
  bool playing = true;
  while(playing == true){
    cout << "[ADD] [SEARCH] [DELETE] [PRINT] [QUIT] ";
    cin >> input;
    cin.ignore();
    if(strcmp("ADD",input)==0){

      cout << "[MANUAL] or [GENERATE] entry? ";
      cin >> input;
      cin.ignore();
      if(strcmp("MANUAL",input)==0){
	cout << "Enter a list of numbers seperated by space: " << endl; 
	char entry[100];
	  cin.get(entry,100,'\n');

	  cin.ignore();
	  char num;
	  char nums[4];
	  int count = 0;

	  for(int i = 0; i < strlen(entry); i++){
	    if(!isspace(entry[i])){
	      
	      nums[count] = entry[i];
	      count++;

	    }
	    if (isspace(entry[i])||i+1==strlen(entry)){
	      count = 0;
	      int num = stoi(nums);
	      cout << "final "<<num << endl;

	      nums[0]='\0';
	      nums[1]='\0';
	      nums[3]='\0';
	      if(head==NULL){
	       head = new Node(num);

	      }
	       else{
		 Add(head, num);
	     }

	    }
	   

	  }
	

      }
      if(strcmp(input, "GENERATE")==0){
	  cout << "How many numbers do you want to generate? ";
	  int n = 0;
	  cin >> n;
	  cin.ignore();

	  ifstream file("numbers.txt");
	    int count = 0;

	    int num = 0;
	    char* word = new char();
	    while(file>>word&&count!=n){
	      num = stoi(word);
	      count++;
	    

	    if(head==NULL)
	      head = new Node(num);
	    else{
	      Add(head, num);
	    }
	    }
	    file.close();
      }
    }
    
    if(strcmp("PRINT",input)==0){
      Print(head, 0);
    }
    if(strcmp("SEARCH",input)==0){
      int num = 0;
      cout << "Number you are looking for: ";
      cin >> num;
      cin.ignore();
      Search(head, num);
    }
    if(strcmp("DELETE",input)==0){
      int num = 0;
      cout << "Number you want to delete: ";
      cin >> num;
      cin.ignore();
      Delete(head, head, num);
    }
    if(strcmp("QUIT",input)==0){
      playing = false;
    }

    }
}
void Add(Node* current, int num){
  Node* parent = NULL;
  Node* newNode = new Node(num);
  //Node* current = head;
  while(current!=NULL){
    parent=current;
    if(num < current->getValue()){
      current  = current->getLeft();
    }
    else if(num >=  parent->getValue()){
      current = current->getRight();
    }
  }
  
  
  if(num< parent->getValue()){
    parent->setLeft(newNode);
  }
  else if(num>= parent->getValue()){
    parent->setRight(newNode);
  }



}
void Print(Node* current, int depth){
  //right 
  if(current->getRight()!= NULL){
    Print(current->getRight(), depth+1);
  }
  //print tabs 
    for(int x = 0; x < depth; x++){
      cout << '\t';
    }
    cout << current->getValue() << endl;
    //check left
    if(current->getLeft()!=NULL){
      Print(current->getLeft(), depth+1);
    }
    
}
//search if the value is found
void Search(Node* current, int num){
  if(current->getValue()==num)
    cout << num << " is found. " << endl;
  //if reaches leaf and still isnt found, it is not in the tree
  else if(current->getRight() == NULL && current->getLeft() == NULL){
    cout << "None found" << endl;
  }
  //recursion left and right
  else if(current->getValue() < num)
    Search(current->getRight(), num);
  else if(current->getValue() > num)
    Search(current->getLeft(), num);
  
}
void Delete(Node* current, Node* prev, int num){
  if(num > current->getValue())
    Delete(current->getRight(), current, num);
  else if(num < current->getValue())
    Delete(current->getLeft(), current, num);

  //if found
  else if(num == current->getValue()){
    
    //if no childrent just delete
    if(current->getLeft()==NULL && current->getRight()==NULL){
      
      if(prev->getLeft()==current)
	prev->setLeft(NULL);
      if(prev->getRight()==current)
        prev->setRight(NULL);

      current = NULL;
      delete current;
      
       
    }
    //if there is children
    else if(current->getLeft()==NULL||current->getRight()==NULL){

      Node* temp = current;
      if(current->getLeft()==NULL){
	temp = current->getRight();
      }
      else if(current->getRight()==NULL){
	temp = current->getLeft();
      }
      
      if(current == head){
	head = temp;
      }
      else if(current==prev->getLeft()){
	prev->setLeft(temp);
      }
      else if(current==prev->getRight()){
	prev->setRight(temp);
      }
      current = NULL;
      delete current;
    }
    //2 children
    else if (current->getRight()!=NULL&&current->getLeft()!=NULL){
      //find leftmost node
      Node* min = current->getRight();
      while(min && min->getLeft()!=NULL){
	min = min->getLeft();
      }
      current->setValue(min->getValue());
      
      Delete(current->getRight(), current, min->getValue());
      
    }
  }
}

