#include <iostream>
#include "Student.h"
#include "Node.h"
using namespace std;
void Add(Student* newStudent);
void Print(Node* next);
Node* head = NULL;
int main(){
  Student* one = new Student();
  one->setID(1);
  
  Add(one);
  Print(head);
  //add student 2
  
  Student* two = new Student();
  two->setID(2);
  Add(two);
  Print(head);
  
  //add student 3
  Student* three = new Student();
  three->setID(3);
 
  Add(three);
  
  

  
  Print(head);
  
  return 0;
}
void Add(Student* newStudent){
  Node* current = head;
  //start of head
  if(current == NULL){
    head = new Node(newStudent);
   
  }
  else{
    //cycle until the end of the list
    while(current->getNext()!= NULL){
      current = current->getNext();
    }
    //add a new node to the end of list
    Node* n = new Node(newStudent);
    current->setNext(n);
   
  }
}
void Print(Node* next){
  if(next==head){
    cout << "list: ";
  }
  if(next != NULL){
    cout << (next->getStudent())->getID() << " ";
    Print(next->getNext());
  }
}
