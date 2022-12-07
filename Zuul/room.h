#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <iostream>
#include <cstring>
#include <map>
#include "item.h"
using namespace std;

class room {
 public:
  room();
  room(char*);
  //void setDescription();
  //char * newDescription = new char[200];
  char* getDescription();
  map<char*, room*>getExits();
  void setExits(room* neighbor, char* direction);
  void printExits();
  void setItem(item* newItem);
  void printItems();
  void deleteItem(item* it);
  item* matchItem(char* input);
  //  void setExit(char *direction, room neighbor);
private:
  int count = 0;
  char* description;
  map<char*, room*> exitMap;
  vector<item*>items;
  item* match;
  int size = 0;
};
#endif
