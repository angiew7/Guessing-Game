#ifndef PARENT_H
#define PARENT_H

#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

class parent {
 public:
  parent();
    virtual void print(vector<parent*>&list, int i){
      cout << "Title" << list[i]->getTitle() << endl;
  }
  virtual ~parent(){
    cout << endl;
  }
  //parent(char*);
  char* getAuthor();
  void setAuthor();
  
  char* getTitle();
  void setTitle();
  
  int getYear();
  void setYear();
 protected:
  int year;
  char title[50];
  char author[50];
};

#endif
