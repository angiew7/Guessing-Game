#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include "room.h"
#include "item.h"
using namespace std;

room::room(){
  //vector<item*> items;
}
/*void room::setDescription(char str[100]){
  strcpy(description, str);
}
*/
room::room(char *newDesc){
  description = newDesc;
  //strcpy(description, newDesc);
  
}
char* room::getDescription(){
  char* d = (char*)malloc(200*sizeof(char));
  strcpy(d, description);
  return d;
  //cout << "You are in: " << d << endl;
}

map<char*, room*> room::getExits(){
  return exitMap;
}
void room::setExits(room* neighbor, char* direction){
  //exitMap.insert(newMap.begin(), newMap.end());
  exitMap.insert(make_pair<char*, room*>(((char*)direction), ((room*)neighbor)));
}
void room::printExits(){
  cout << "Exits in this room: ";
  for(auto &i: exitMap){
    cout << i.first << " ";
  }
  cout << endl;
}
void room::setItem(item* newItem){
  items.push_back(newItem);
}
void room::printItems(){
  for(int i = 0; i < items.size(); i++){
    cout << items[i]->getItem();
  }
  cout << endl;
}
item* room::matchItem(char* input){
  count = 0;
  for(int i=0; i< items.size(); i++){
    if(strcmp(items[i]->getItem(), input)==0){
      match = items[i];
	count = count +1;
      }
    }
  if(count==0){
    cout << "No items match " << endl;
    //return null;
  }
  return match;
  
}
void room::deleteItem(item* it){
  for(int i=0; i < items.size(); i++){
    if(strcmp(items[i]->getItem(), it->getItem())==0){
      items.erase(items.begin()+i);
    }
  }
}
