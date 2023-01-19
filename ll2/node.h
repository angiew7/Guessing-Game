#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

class Node { // Node Class
public:
  Node(Student* Student); // Node Constructor
  ~Node(); // Destructor
  Student* getStudent(); // get student*
  void setNext(Node*); // Set the next node
  Node* getNext(); // Get the next node
private:
  Node* next;
  Student* student;
};
#endif
