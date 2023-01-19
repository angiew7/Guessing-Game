#include <iostream>
#include "Student.h"
using namespace std;

Student::Student(){
  
}
void Student::setID(int newID){
  ID = newID;
}
int Student::getID(){
  return ID;
}
