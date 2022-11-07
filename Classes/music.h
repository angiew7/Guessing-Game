#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include "parent.h"
using namespace std;

class music : public parent{
 public:
  music();
  //Destructor
  virtual ~music(){
    cout << "Deleted." << endl;
  }
  // Virtual Print Function
  virtual void print(vector<parent*>&list, int i){
    cout << "Music:" << endl;
    cout << "Title: " << ((parent*)list[i])->getTitle() << endl;
    cout << "Artist: "<< ((music*)list[i])->getArtist() << endl;
    cout << "Year: " << ((parent*)list[i])->getYear() << endl;
    cout << "Duration (min): " << ((music*)list[i])->getDuration() << endl;
    cout << "Publisher: " << ((parent*)list[i])->getAuthor() << endl;
  }
  float getDuration();
  void setDuration();

  char* getArtist();
  void setArtist();
  
 protected:
  char artist[100];
  float duration;
};

#endif
