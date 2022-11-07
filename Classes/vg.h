#ifndef VG_H
#define VG_H
/*
Video Games header file
 */
#include <iostream>
#include "parent.h"
using namespace std;

class vg : public parent{
 public:
  vg();
  virtual ~vg(){
    cout << "Deleted. "<< endl;
  }
  virtual void print(vector<parent*>&list, int i){
    cout << "Video game:" << endl;
    cout << "Title: " << ((parent*)list[i])->getTitle() << endl;
    cout << "Year: " << ((parent*)list[i])->getYear() << endl;
    cout << "Publisher: " << ((parent*)list[i])->getAuthor() << endl;
    cout << "Rating: " << ((vg*)list[i])->getRating() << "/10" << endl;
  }
  void setRating();
  float getRating();
  protected:
    float rating;
};
#endif
