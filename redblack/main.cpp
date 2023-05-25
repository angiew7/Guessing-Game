/*
Angie Wang
5/1/2023
Using BST insertion, update the tree after each node inserted and deleted using Red-Black tree properties

 */
#include <iostream>
#include <cstring>
#include "Node.h"
#include <fstream>
#include<stdio.h>
#include<ctype.h>

using namespace std;
Node* head = NULL;
int RED = 1;
int BLACK = 2;
void Add(Node* current, int num);
void Print(Node* current, int depth);
void Search(Node* current, int num);
void Delete(Node* current, Node* prev, int num);
void Update(Node* x);
void leftRotate(Node* node);
void rightRotate(Node* node);
void replaceParentChild(Node* parent, Node* oldChild, Node* newChild);
//void deleteFix(Node* node, Node* p);
void fixDelete(Node* node);
bool isBlack(Node* node);
int main(){
  //  srand(time(NULL));
  char input[20];
  bool playing = true;
  cout << "NOTE: When printing, p: [number] shows parent of that node, r  means red, b means black. The number following is the int assigned to that node." << endl;
  cout << endl;
  while(playing == true){
    cout << "[ADD] [SEARCH] [DELETE] [PRINT] [QUIT] ";
    cin >> input;
    cin.ignore();
    if(strcmp("ADD",input)==0){

      cout << "[MANUAL] or [GENERATE] entry? ";
      cin >> input;
      cin.ignore();
      if(strcmp("MANUAL",input)==0){
	cout << "Enter a list of numbers seperated by space: (no more than 100 char inputed total) " << endl; 
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
	      

	      nums[0]='\0';
	      nums[1]='\0';
	      nums[2]='\0';
	      if(head==NULL){
	       head = new Node(num);
	       head->setColor(BLACK);
	      }
	       else{
		 Add(head, num);
	     }

	    }
	   

	  }
	

      }
      if(strcmp(input, "GENERATE")==0){
	  cout << "How many numbers do you want to generate? (up to 100) ";
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
	    

	      if(head==NULL){
		head = new Node(num);
		head->setColor(BLACK);
	      }
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
    newNode->setParent(parent);
  }
  else if(num>= parent->getValue()){
    parent->setRight(newNode);
    newNode->setParent(parent);
  }
  //cout << newNode->getValue() << " parent " << newNode->getParent()->getValue() <<endl;; 
  Update(newNode);

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
    if(current->getParent()!=NULL)
      cout << "p: " << current->getParent()->getValue() << " ";

    if(current->getColor()==RED)
      cout << "r";
    if(current->getColor()==BLACK)
      cout << "b";
    cout << current->getValue()<<endl;
    
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
  Node* child = NULL;
  int currentColor = BLACK;
  if(num > current->getValue())
    Delete(current->getRight(), current, num);
  else if(num < current->getValue())
    Delete(current->getLeft(), current, num);

  //if found
  else if(num == current->getValue()){
    
    //if no childrent just delete
    if(current->getLeft()==NULL && current->getRight()==NULL){
      if(current->getColor() == BLACK){
	  cout << "black" << endl;
	  fixDelete(current);
	}
      prev = current->getParent();
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
	temp->setParent(prev);
      }
      else if(current==prev->getRight()){
	prev->setRight(temp);
	temp->setParent(prev);
      }
      child = temp;
      currentColor = current->getColor();
      current = NULL;
      delete current;
      if(currentColor == BLACK){
	cout << "black" << endl;
	fixDelete(child);
    }

      //   current = NULL;
      //delete current;
    }
    //2 children
    else if (current->getRight()!=NULL&&current->getLeft()!=NULL){
      
      //find leftmost node
      Node* min = current->getRight();

      while(min!=NULL && min->getLeft()!=NULL){
	min = min->getLeft();
      }
      
      current->setValue(min->getValue());
      
      Delete(current->getRight(), current, min->getValue());
      
    }
    
  }
}

void Update(Node* x){
  Node* p = NULL;
  Node* u = NULL;
  Node* g = NULL;
  //no nodes
  if(head->getLeft()==NULL&&head->getRight()==NULL){
    x->setColor(BLACK);
    head = x;
  }

  while(x!=head && x->getParent()->getColor()==RED){
    p = x->getParent();
    g = x->getParent()->getParent();
         
    //if parent is  right child
    if(p == g->getRight()){
      u = g->getLeft();

     //parent is red and uncle is red ()
      if(u!=NULL && u->getColor() == RED){
        u->setColor(BLACK);
        p->setColor(BLACK);
        g->setColor(RED);
        x = g;
      }   
      //rotate case
      else if(u==NULL || u->getColor()==BLACK){
	//if node is left child then do a right rotation then left
	if(x == p->getLeft()){
	  rightRotate(p);
	  p = x;
	  
	}
	//g = x->getParent()->getParent();
	leftRotate(g);
	
	//recolor original parent and grandparent;
	x->setColor(RED);
	p->setColor(BLACK);
	g->setColor(RED);
	
	}
	
      }
    //if parent is left child 
    else if (p == g->getLeft()){
	 u = g->getRight();
	 if(u!=NULL && u->getColor() == RED){
	   u->setColor(BLACK);
	   p->setColor(BLACK);
	   g->setColor(RED);
	   x = g;
	 }
	 //rotate cases
	 else if(u == NULL || u->getColor() == BLACK){
	   if(x == p->getRight()){
	     leftRotate(p);
	     p = x;
	   }
	 
    	   rightRotate(g);
	   x->setColor(RED);
	   p->setColor(BLACK);
           g->setColor(RED);

	 }

    }
    //head always black
    head->setColor(BLACK);
  }
}

//used happycoders
void leftRotate(Node* node){
  
  Node* p = node->getParent();
  Node* x = node->getRight();
  node->setRight(x->getLeft());
  if(x->getLeft() !=NULL){
    x->getLeft()->setParent(node);
  }
  
  x->setLeft(node);
  
  node->setParent(x);
  
  replaceParentChild(p, node, x);
}
void rightRotate(Node* node){
  
  Node* p = node->getParent();
  Node* l = node->getLeft();
  node->setLeft(l->getRight());
  if(l->getRight()!=NULL){
    l->getRight()->setParent(node);
  }
  l->setRight(node);
  node->setParent(l);
  replaceParentChild(p, node, l);
}

void replaceParentChild(Node* parent, Node* oldChild, Node* newChild){
  if(parent==NULL){
    head = newChild;
  }
  else if(parent->getLeft()==oldChild){
    parent->setLeft(newChild);
  }
  else if(parent->getRight()==oldChild){
    parent->setRight(newChild);
  }
  else{
    cout << "no" << endl;
  }
  if(newChild!= NULL){
    newChild->setParent(parent);
  }

}
//used happy coders
void fixDelete(Node* node){
  Node* p = node->getParent();
  
  //case 1
  if(node == head){
    return;
  }
  Node* s = NULL;
  //get sibling
  if(node==p->getLeft())
    s = p->getRight();
  if(node==p->getRight())
    s = p->getLeft();
  //  cout << p->getRight()->getValue()<<endl;

  //case 2 red sib
  if(s!=NULL && s->getColor()==RED){
    cout << "case 2" << endl;
    //recolor and rotate
    s->setColor(BLACK);
    node->getParent()->setColor(RED);
    if(node == p->getLeft())
      leftRotate(p);
    else
      rightRotate(p);
    p = node->getParent();
    //get sibling
    if(node==p->getLeft())
      s = p->getRight();
    else if(node==p->getRight())
      s = p->getLeft();
  }
  //cases 3 4, black sib w/ 2 black children
  if(s!=NULL&& isBlack(s->getLeft())&&isBlack(s->getRight())){
    s->setColor(RED);
    //case 
    if(p->getColor()==RED){
      cout << "case 3"<<endl;
      p->setColor(BLACK);
    }
    //case 4 black sib w/ 2 black children + black parent
  
    else{
      cout << "case 4" << endl;
      fixDelete(node->getParent());
    }
  }
  //case 5, 6 black sib with at least 1 red child
  else{
    cout << "case 5 6" << endl;
    bool isLeftChild = node == node->getParent()->getLeft();
    if(isLeftChild && isBlack(s->getRight())){
      s->getLeft()->setColor(BLACK);
      s->setColor(RED);
      rightRotate(s);
      s = node->getParent()->getRight();
    } else if(!isLeftChild && (s==NULL||isBlack(s->getLeft()))){
      if(s->getRight()!=NULL)
	s->getRight()->setColor(BLACK);
      s->setColor(RED);
      leftRotate(s);
      s = node->getParent()->getLeft();
      }
    //recolor sib, parent, child, and rotate around p
    s->setColor(node->getParent()->getColor());
    node->getParent()->setColor(BLACK);
    if(isLeftChild){
    
	s->getRight()->setColor(BLACK);
      leftRotate(node->getParent());
    }
    else{
       s->getLeft()->setColor(BLACK);
       rightRotate(node->getParent());

    }
  }
}
bool isBlack(Node* node){
  return node == NULL|| node->getColor() == BLACK;
}
