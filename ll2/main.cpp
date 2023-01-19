#include <iostream>
#include "node.h"
#include "Student.h"
#include <cstring>
using namespace std;
void Add();
void Print(Node* next);
Node* head = NULL;

int main(){
  int id =0;
  char input[10];
  cin >> input;
  cin.ignore();
  if(strcmp(input, "ADD")==0){
    Add();
  }
  if(strcmp(input, "PRINT")==0){
    Print(head);
  }
  return 0;
}
void Add(){
  int id = 0;
  cin >> id;

  Student* student = new Student();
  student->setID(id);
  cout << "o";
  Node* current = head;
  if(current->getNext()==NULL){
    head = new Node(student);
    
  }
}
void Print(Node* next){
  if(next==head){
    cout << "List:" << endl;
  }
  if(next!= NULL){
    cout << (next->getStudent())->getID()<<endl;
    Print(next->getNext());
  }
}
