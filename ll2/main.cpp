/*
Angie Wang
1/25/2023
This program asks user for a command:
 
  ADD: asks user for first and last name, ID, and GPA
  PRINT: Prints out all students and their information
  DELETE: Asks user for a ID to delete 
  AVERAGE: Prints the average gpa of all the current students
  QUIT: Stops running
 */
#include <iostream>
#include "node.h"
#include "Student.h"
#include <cstring>
#include <iomanip>
using namespace std;
void Add(Node* current, Student* student);
void Print(Node* next);
void Delete(Node* next, int id);
void Average(Node* next, float sum, int num);
Node* head = NULL;

int main(){
 
  bool running = true;
  while(running ==true){
    cout << "Enter Command [ADD, PRINT, DELETE, AVERAGE, QUIT]: ";
    char input[10];
    cin >> input;
    cin.ignore();

    if(strcmp(input, "ADD")==0){
      //input info
      int id = 0;
      Student* student = new Student();
      
      cout << "ID: ";
      cin >> id;
      cin.ignore();
      cout << "First Name: ";
      student->setFirstName();
      
      cout << "Last Name: ";
      student->setLastName();
      
      cout << "GPA: ";
      student->setGPA();
      
      student->setID(id);
      
 
      
      Add(head, student);
    }
    if(strcmp(input, "PRINT")==0){
      Print(head);
    }
    if(strcmp(input, "QUIT")==0){
      running = false;
    }
    if(strcmp(input, "DELETE")==0){
      cout << "Enter ID you want to delete: ";
      int deleteID = 0;
      cin >> deleteID;
      cin.ignore();
      Delete(head, deleteID);
    }
    if(strcmp(input, "AVERAGE")==0){
      float sum = 0;
      int num = 0;
      Average(head, sum, num);
    }
  }
  return 0;
}
void Add(Node* current, Student* student){
 
  int position = 0;
 

   int dest = 0;
  //new head
  if(current==NULL){
    head = new Node(student);
    
  }
  //if new node id is less than head
  else if(head->getStudent()->getID() > student->getID()){
        position = 0;
        cout << "h" << endl;
        Node* n = new Node(student);
        n->setNext(head);
        head = n;


      }

  else{
    
    if(current->getNext()!= NULL && student->getID() > current->getNext()->getStudent()->getID()){
    

	Add(current->getNext(), student);
    }

  
    
    else{

      Node* next = current->getNext();



      Node* n = new Node(student);
      current->setNext(n);
      n->setNext(next);
    
    }
  }
}
void Print(Node* next){
  if(next==head){
    cout << "Student list:" << endl;
  }
  if(next!= NULL){
    cout << "Name: " << (next->getStudent())->getFirstName();
    cout << " " << (next->getStudent())->getLastName();
    cout << " ID:  "<<(next->getStudent())->getID();
    cout << setprecision(2) << fixed;
    cout << " GPA: " <<(next->getStudent())->getGPA() << endl;
    Print(next->getNext());
  }
}
void Delete(Node* next, int id){
  //replace the head 
  if(head->getStudent()->getID()==id){
    Node* n = head;
    head = head->getNext();
    delete n;    
  }
  //cycle until the next node ID is the same as input
  else if(next->getNext()!=NULL && next->getNext()->getStudent()->getID()!=id){
    Delete(next->getNext(), id);
  }
  //delete once node found
  else if(next->getNext()->getStudent()->getID()==id){
    Node* temp = next->getNext();
    next->setNext((next->getNext())->getNext());
    delete temp;
  }
  else{
    cout << "No ID found. " << endl;
  }
}
void Average(Node* next, float sum, int num){
  if(next->getNext()!=NULL){
    sum = sum + (next->getStudent())->getGPA();
    num++;
    Average(next->getNext(), sum, num);
  }
  else if(next->getNext()==NULL){
    sum = sum + (next->getStudent())->getGPA();
    num++;
    sum = sum/num;
    cout << setprecision(2) << fixed;
    cout << "GPA Average: " << sum << endl;
  }
}
