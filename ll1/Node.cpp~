#include <iostream>
#include "Node.h"
#include "Student.h"
using namespace std;

Node::Node(){
  
}

//Constructor
Node::Node(Student* newStudent){
  student = newStudent;
  next = NULL;
}

//Destructor
Node::~Node(){
  delete student;
  next = NULL;
}

//Get student pointer
Student* Node::getStudent(){
  return student;
}

//Set next pointer to corresponding node pointer
void Node::setNext(Node* newNext){
  next = newNext;
}
Node* Node::getNext(){
  return next;
}
