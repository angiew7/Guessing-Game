#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>

using namespace std;

class Node { // Node Class
public:
  Node();
  Node(int newValue); // Node Constructor
  ~Node(); // Destructor
  int getValue(); // get student*
  void setValue(int num);
  void setRight(Node* Right); // Set the right node
  Node* getRight(); // Get the right node
  void setLeft(Node* Left); // Set the left node
  Node* getLeft(); // Get the left node
  int getColor();
  void setColor(int newColor);
  Node* getParent();
  void setParent(Node* newParent);
private:
  Node* right;
  Node* left;
  Node* parent;
  int value;
  int color;
};
#endif
