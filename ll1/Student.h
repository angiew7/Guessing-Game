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
private:
  int ID = 0;
};

#endif
