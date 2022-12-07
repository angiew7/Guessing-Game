#include <iostream>
#include <vector>
#include <map>
#include "room.h"
#include "item.h"
using namespace std;

room* goRoom(room* currentRoom, map<char*, room*>&exitMap);
void printRoom(room* currentRoom);
void getItem(room* currentRoom, vector<item*>&inventory);
void getInventory(vector<item*>&inventory);
void dropItem(room* currentRoom, vector<item*>&inventory);
bool checkWin(room* currentRoom, room* roof, vector<item*>&inventory, int moves);
//void setExits(int roomNumber, char* direction);
int main(){
  room* currentRoom;
  map<char*, room*> exitMap;
  vector<item*>inventory;
  char command[10];
  bool running = true;
  int moves = 0;
  //rooms
  room* main = new room((char*)"in the reception area.");
  room* bathroom = new room((char*)("in the bathroom."));
  room* gift = new room((char*)("in the giftshop."));
  room* cafe = new room((char*)("in the cafe. "));
  room* outside = new room((char*)("outside."));
  room* zooland = new room((char*)("in Zooland!"));
  room* art = new room((char*)("in the art hall"));
  room* history = new room((char*)("in the history hall"));
  room* fossil = new room((char*)("in the fossils room"));
  room* child = new room((char*)"in the child playground");
  room* aquarium = new room((char*)"in the aquarium");
  room* plantarium = new room((char*)"in the planetarium");
  room* stairs = new room((char*)"in the stairwell");
  room* auditorium = new room((char*)"in the auditorium");
  room* roof = new room((char*)"on the rooftop");
			   
  //exits
  //outside
  //exitMap.insert(make_pair<char*, room*>( ((char*)"NORTH"), ((room*)main) ));
  outside->setExits(main, (char*)"NORTH");
  //main
  main->setExits(aquarium, (char*)"NORTH");
  main->setExits(art, (char*)"EAST");
  main->setExits(cafe, (char*)"WEST");
  //art
  art->setExits(main, (char*)"WEST");
  art->setExits(history, (char*)"EAST");
  art->setExits(zooland, (char*)"NORTH");
  //history
  history->setExits(art, (char*)"WEST");
  history->setExits(fossil, (char*)"NORTH");
  //fossils
  fossil->setExits(history,(char*)"SOUTH");
  fossil->setExits(zooland, (char*)"WEST");
  //zooland
  zooland->setExits(art, (char*)"SOUTH");
  zooland->setExits(fossil, (char*)"EAST");
  zooland->setExits(child,(char*)"NORTH");
  zooland->setExits(aquarium, (char*)"WEST");
  //child
  child->setExits(zooland,(char*)"SOUTH");
  //aquarium
  aquarium->setExits(main, (char*)"SOUTH");
  aquarium->setExits(zooland, (char*)"EAST");
  aquarium->setExits(gift, (char*)"WEST");
  aquarium->setExits(plantarium, (char*)"NORTH");
  //plantarium
  plantarium->setExits(aquarium, (char*)"SOUTH");
  plantarium->setExits(stairs, (char*)"WEST");
  //cafe
  cafe->setExits(main,(char*)"EAST");
  cafe->setExits(bathroom, (char*)"WEST");
  //bathroom
  bathroom->setExits(cafe, (char*)"EAST");
  bathroom->setExits(auditorium, (char*)"NORTH");
  //auditorium
  auditorium->setExits(bathroom, (char*)"SOUTH");
  auditorium->setExits(gift, (char*)"EAST");
  //gift
  gift->setExits(auditorium, (char*)"WEST");
  gift->setExits(aquarium, (char*)"EAST");
  gift->setExits(cafe, (char*)"SOUTH");
  //stairs
  stairs->setExits(roof, (char*)"WEST");
  
    //items
  item* food = new item((char*)"Food");
  cafe->setItem(food);
  item* monalisa = new item((char*)"Mona Lisa");
  zooland->setItem(monalisa);
  item* soap = new item((char*)"Soap");
  bathroom->setItem(soap);
  item* emptyArt = new item((char*)"Empty artwork frame");
  art->setItem(emptyArt);
  item* fish = new item((char*)"Striped Fish");
  aquarium->setItem(fish);
  item* baby = new item((char*)"A baby");
  fossil->setItem(baby);
  
  currentRoom = outside;
  cout << "WELCOME TO ZUUL." << endl;
  cout << "You are planning to rob a museum." << endl; 
    cout << "Find and steal the prized art work and escape to the rooftop before the police come." << endl;
  //running commands
  while (running == true){
    
    //print room you are in
    cout << "You are " << currentRoom->getDescription() << endl; 
    currentRoom->printExits();
    cout << "Items in this room: ";
    currentRoom->printItems();
    cout << "Enter command: (GO, INVENTORY, GET, DROP, QUIT) " << endl;
    cin >> command;
    cin.ignore();
    
    //move room
    if(strcmp(command, "GO")==0){
      currentRoom = goRoom(currentRoom, exitMap);
    }
    else if(strcmp(command, "GET")==0){
      getItem(currentRoom, inventory);
    }
    else if(strcmp(command, "INVENTORY")==0){
      getInventory(inventory);
    }
    else if(strcmp(command,"DROP")==0){
      dropItem(currentRoom, inventory);
    }
    else if(strcmp(command, "QUIT") == 0){
      running = false;
    }
    
   
    else{
      moves++;
    running = checkWin(currentRoom, roof, inventory, moves);
    }
    moves++;
    cout << endl;
  }
  return 0;
}

room* goRoom(room* currentRoom, map<char*, room*>&exitMap){
  char direction[9];
  cout << "Direction? (NORTH, SOUTH, WEST, EAST): " << endl;
  cin >> direction;
  cin.ignore();
  int count = 0;
  //Check for exits, if found then move to that room
  for(auto &i: currentRoom->getExits()){
    if(strcmp(direction, i.first)==0){
      currentRoom = i.second;
      count++;
    }
  }
  //if theres no exit in that direction
  if(count == 0){
    cout << "There is no room in that direction!" << endl;
  }
  return currentRoom;
}
void printRoom(room* currentRoom){
  cout << "You are: " << currentRoom->getDescription() << endl;
  cout << "Items in the room: " << endl;
  currentRoom->printExits();
}
void getItem(room* currentRoom, vector<item*>&inventory){
  cout << "What do you want to get?" << endl;
  char input[50];
  cin.get(input, 50, '\n');
  cin.ignore();
  if(strcmp(input, "Empty artwork frame")==0||strcmp("A baby", input)==0||strcmp("Soap", input)==0){
    cout << "Did you really need this..?" << endl;
  }
  //push to inventory
  inventory.push_back(currentRoom->matchItem((char*)input));
  //delete item from room
  currentRoom->deleteItem(currentRoom->matchItem((char*)input));
}

void getInventory(vector<item*>&inventory){
  cout<< "Inventory: " << endl;
  for(int i = 0; i < inventory.size(); i++){
    cout << inventory[i]->getItem();
  }
  cout << endl;
  
}
void dropItem(room* currentRoom, vector<item*>&inventory){
  char input[20];
  cout << "Which item would you like to drop? " << endl;
  cin.get(input, 21, '\n');
  cin.ignore();
  item* drop;
  
  //remove from inventory
  //drop = currentRoom->matchItem((char*)input);
  for(int i=0; i < inventory.size(); i++){
    if(strcmp(input, inventory[i]->getItem())==0){
      drop = inventory[i];
      inventory.erase(inventory.begin()+i);
      
    }
  }
  //put back item in room
  currentRoom->setItem(drop);
}
bool checkWin(room* currentRoom, room* roof, vector<item*>&inventory, int moves){
  if(currentRoom == roof){
    for(int i =0; i < inventory.size();i++){
      if(strcmp(inventory[i]->getItem(), "Mona Lisa")==0){
	//stop game
	cout << "YOU WIN!" << endl;
	cout << "Congratulations!" << endl;
	cout << "You sucessfully escaped the museum with the Mona lisa!" << endl;
	return false;
      }
      
    }
  }
  else if(inventory.size() > 3){
    cout << "YOU LOSE." << endl;
    cout << "You got greedy and all those treasures slowed you down.."<< endl;
    cout << "You were not able to outrun the cops." << endl;
      return false;
  }
  else if(moves==30){
    cout << "YOU LOSE" << endl;
    cout << "You took too long and the cops found you before you could make it out :(" << endl;
    return false;
  }
  
  
    return true;
  
}
