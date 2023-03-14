#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;
Node::Node(){
}
Node::Node(char newValue) {
  value = newValue;
  right = NULL;
  left = NULL;
  next = NULL;
}
Node::~Node(){
  left = NULL;
  right = NULL;
  left = NULL;
}
char Node::getValue() {
  return value;  
}
Node* Node::getRight(){
  return right;
}
void Node::setRight(Node* Right){
  right = Right;
}
Node* Node::getLeft(){
  return left;
}
void Node::setLeft(Node* Left){
  left = Left;
}

Node* Node::getNext() {
  return next;
}

void Node::setNext(Node* Next) {
  next = Next;
}
