#include <iostream>
#include <cstring>
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
void Student::setFirstName(){
  char f[50];
  //cin >> t;
  cin.get(f, 50, '\n');
  cin.ignore(50, '\n');
  strcpy(firstName, f);
}
char* Student::getFirstName(){
  char* f = (char*)malloc(50*sizeof(char));
  strcpy(f, firstName);
  return firstName;

}

void Student::setLastName(){
    char l[50];
  //cin >> t;
  cin.get(l, 50, '\n');
  cin.ignore(50, '\n');
  strcpy(lastName, l);
  }
char* Student::getLastName(){
  char* l = (char*)malloc(50*sizeof(char));
  strcpy(l, lastName);
  return lastName;

}
void Student::setGPA(){
  float g = 0;
  cin >> g;
  cin.ignore();
  gpa=g;
}
float Student::getGPA(){
  return gpa;
}
