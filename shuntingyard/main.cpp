/*
  Angie Wang
  3/14/2023
  This program implements a shunting yard algorithm to take a user
  inputed expression to insert it into an expression tree
  and print it out in prefix, infix, or postfix notation
 */
#include <iostream>
#include "Node.h"
#include <cstring>
#include<stdio.h>
#include<ctype.h>

using namespace std;
void Enqueue(Node* current, char value);
void Push(Node* current, Node* add);
Node* Peek(Node* current);
void Pop(Node* current);
void Dequeue(Node* current);
void buildTree(Node* current);
void Infix(Node* current);
void Postfix(Node* current);
void Prefix(Node* current);

Node* queueHead  = NULL;
Node* stackHead = NULL;
int main(){
  char input[20];
  char character;
 
  
  cout << "Enter expression (single digits, seperated by space): " << endl;
  cin.get(input, 20, '\n');
  cin.ignore();
  for(int i = 0; i < strlen(input); i++){
    //turn each char seperated by space into node
    if(!isspace(input[i])){
      
      //numbers go straight to queue
      if(isdigit(input[i])){
	Enqueue(queueHead, input[i]);
      }
      
      //top of stack goes to queue if right parentheses
      else if(input[i] == ')'){
	//move all the values in the parentheses to the stack and delete them
	// from the stack
	while(Peek(stackHead)->getValue()!='('){
	  Enqueue(queueHead, Peek(stackHead)->getValue());
	  Pop(stackHead);
	  cout << Peek(stackHead)->getValue() << endl;
	}
	//make sure to delete right parentheses
	if(Peek(stackHead)->getValue()=='('){
	  Pop(stackHead);
	}
      }
      
      else if(!isdigit(input[i]) && input[i]!= ')'){
	Node* n = new Node(input[i]);
	Push(stackHead, n);
	
      }
    }
    
  }
  //after 'cars' have been moved
  // keep moving stack to queue
  while(stackHead!=NULL){
    if(Peek(stackHead)->getValue()!='('){
      Enqueue(queueHead, Peek(stackHead)->getValue());
    }
      Pop(stackHead);
  }
  //print postfix
  cout << "Postfix: "<< endl;
  Node* current = queueHead;
  while(current!=NULL){
    cout << current->getValue() << " ";
    current = current->getNext();
  }
  //out << endl;
  //ut <<  Peek(queueHead)->getValue() << endl;
  //ut << endl;
  //build tree
  while(queueHead!=NULL){
    //ut << queueHead->getValue() << endl; 
    buildTree(queueHead);
    Dequeue(queueHead);
    
  }
  bool running = true;
  while(running == true){
    char answer[8];
    cout << "PRINT [INFIX] [POSTFIX] [PREFIX] or [QUIT] ";
    cin >> answer;
    cin.ignore();
    if(strcmp("INFIX",answer)==0){
      Infix(stackHead);
      cout << endl;
    }
    else if (strcmp("POSTFIX", answer)==0){
      Postfix(stackHead);
      cout << endl;
    }
    else if (strcmp("PREFIX", answer)==0){
      Prefix(stackHead);
      cout << endl;
    }

    else if(strcmp("QUIT", answer)==0){
      running = false;
    }
    cout << endl;
  }
  //Print(stackHead, 0);
  return 0;
}

//Add nodes to queue
void Enqueue(Node* current, char value){
  int i = 0;
  if(current == NULL){
    queueHead = new Node(value);
  }
  else if (current!=NULL){
    while(current->getNext()!=NULL){
      current  = current->getNext();
    }
    Node* n = new Node(value);
    current->setNext(n);
    //cout << "queue " << n->getValue() << endl;

  }
  //cout << "queue " << current->getValue() << endl;
}

//push node to top of stack
void Push(Node* current, Node* add){
  //add->setNext(NULL);
  if(current == NULL){
    stackHead = add;
  }
  
  else if (current!=NULL){
    while(current->getNext()!=NULL){
      current = current->getNext();
    }
    //Node* n = new Node(value);
    current->setNext(add);
    //cout << "stack" << stackHead->getNext()->getValue() << endl;
  }
 

  
}

//return top of stack
Node* Peek(Node* current){
  while(current->getNext()!=NULL){
    current = current->getNext();
  }
  return current;
}

//remove top of stack
void Pop(Node* current){
  if(current->getNext()==NULL){
    stackHead = NULL;
    delete current; 
  }
  else{
    while(current->getNext()->getNext()!=NULL){
      current = current->getNext();
    }
    //cout << "deleted " << current->getNext()->getValue() << endl;
    delete current->getNext();
    current->setNext(NULL);
  }
  }

//delete head of queue
void Dequeue(Node* current){
  if(current->getNext()==NULL){
    queueHead = NULL;
    delete current;
  }
  else if(current->getNext()!=NULL){  
    Node* temp = current->getNext();
    queueHead = NULL;
    delete current;
    queueHead = temp;
  }
}

//make array, set left and right ptrs if non-digit 
void buildTree(Node* current){
  //all the numbers get added to stack
  if(isdigit(current->getValue())){
    Node* n = new Node(current->getValue());
    Push(stackHead, n);
  }
  else if(!isdigit(current->getValue())){
      //set left and right as top nodes in stack
    Node* n =  new Node(current->getValue());
    //create new node for left and right
    Node* newRight = new Node(Peek(stackHead)->getValue());
    newRight->setRight(Peek(stackHead)->getRight());
    newRight->setLeft(Peek(stackHead)->getLeft());

    n->setRight(newRight);
    Pop(stackHead);
    Node* newLeft = new Node(Peek(stackHead)->getValue());
    newLeft->setRight(Peek(stackHead)->getRight());
    newLeft->setLeft(Peek(stackHead)->getLeft());
    n->setLeft(newLeft);
    Pop(stackHead);
    
    Push(stackHead, n);
  }
}
void Infix(Node* current){
  if(current->getLeft()!=NULL){
    //add parenthesses before left num thats a parent
    cout << "( ";
    Infix(current->getLeft());
  }
  
  cout<<current->getValue() << " ";
  if(current->getRight()!=NULL){
    Infix(current->getRight());
    cout << ") ";
  }
  
}
//print postfix by transversing tree
void Postfix(Node* current){
   if(current->getLeft()!=NULL){
    Postfix(current->getLeft());
  }
  if(current->getRight()!=NULL){
    Postfix(current->getRight());
  }
  //print leaf nodes first
  cout << current->getValue() << " ";
}
//print prefix notation
void Prefix(Node* current){
  //operators print before values
  cout << current->getValue() << " ";
  if(current->getLeft()!=NULL){
    Prefix(current->getLeft());
  }
  if(current->getRight()!=NULL){
    Prefix(current->getRight());
  }

}
