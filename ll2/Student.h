/*
Student class, all the information for the students go here.
 */
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;
class Student{
 public:
  Student();
  void setID(int newID);
  int getID();
  void setFirstName();
  char* getFirstName();
  void setLastName();
  char* getLastName();
  void setGPA();
  float getGPA();
private:
  float gpa;
  char firstName[50];
  char lastName[50];
  int ID = 0;
};

#endif
