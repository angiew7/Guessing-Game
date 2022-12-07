#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <map>
#include <cstring>

using namespace std;

class item{
 public:
  item();
  item(char*);
  char* getItem();
 private:
  char* description;
};
#endif
