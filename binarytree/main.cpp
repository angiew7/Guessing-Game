/*
  Angie Wang
  4/7/2023
  Binary Search Tree -creates a binary tree where the right value is greater than the head and the left is less than or equal to the head
  
  Add: Manually adds or Generates from file
  Search: user enters in a number, outputs if its found in the tree or not
  Delete: deletes the inputted node, replacing the node if needed
  Print: print the tree
  Quit: stop program
 */
#include <iostream>
#include <cstring>
#include <time.h>
#include "Node.h"
#include <fstream>
#include<stdio.h>
#include<ctype.h>

using namespace std;
Node* head = NULL;
Node* Add(Node* current, int num);
void Print(Node* current, int depth);
void Search(Node* current, int num);
void Delete(Node* current, Node* prev, int num);
int main(){
  srand(time(NULL));
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
	int num = 0;
	cin >> num;
	cin.ignore();
	if(head==NULL)
	  head = new Node(num);
	else{
	  Add(head, num);
	}
	cout <<head->getValue()<<endl;
      }
      if(strcmp(input, "GENERATE")==0){
	  cout << "How many numbers do you want to generate? ";
	  int n = 0;
	  cin >> n;
	  cin.ignore();
          for(int i = 0; i < n; i++){
	  ifstream file("numbers.txt");
	    int count = 0;
	    int random = rand()%100;
	    int num = 0;
	    char* word = new char();
	    while(file>>word && count != random){
	      num = stoi(word);
	      count++;
	    }
	    //	    cout << word <<"num "<< num << endl;
	    if(head==NULL)
	      head = new Node(num);
	    else
	      Add(head, num);
	    file.close();
      }
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
Node* Add(Node* current, int num){
    //no head
  
  if(current == NULL){
  
    return new Node(num);
   
  }
  
   
  //transversal
    if(num <= current->getValue()){
      current->setLeft(Add(current->getLeft(), num));
    }
    else if(num > current->getValue()){
      current->setRight(Add(current->getRight(), num));
    }
  
      return current;
  
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
  //if greater than, go right, if less, go left
  if(num > current->getValue())
    Delete(current->getRight(), current, num);
  else if(num < current->getValue())
    Delete(current->getLeft(), current, num);
  
  else if(num == current->getValue()){
    cout << current->getValue()<<endl;
    //if no childrent just delete
    if(current->getLeft()==NULL && current->getRight()==NULL){
       
      if(current==prev->getLeft()){
	prev->setLeft(NULL);
      }
      else if(current==prev->getRight()){
	prev->setRight(NULL);
      }
       

      delete current;
      current=NULL;
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
    
      if(current==prev->getLeft()){
	prev->setLeft(temp);
      }
      else if(current==prev->getRight()){
	prev->setRight(temp);
      }
      delete current;
    }


    
    //2 children
    else if (current->getRight()!=NULL&&current->getLeft()!=NULL){
      //find leftmost node of the right subtree
      Node* min = current->getRight();
      while(min && min->getLeft()!=NULL){
	min = min->getLeft();
      }
      //replace the value
      current->setValue(min->getValue());
      //delete min
      Delete(current->getRight(), current, min->getValue());
       }
  }
}

