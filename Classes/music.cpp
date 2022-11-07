#include <iostream>
#include <cstring>
#include "music.h"
using namespace std;

music::music(){
}

float music::getDuration(){
  return duration;
}
void music::setDuration(){
  float d = 0;
  cin >> d;
  cin.ignore();
  duration = d;
}
void music::setArtist(){
  char ar[100];
  cin.get(ar, 100, '\n');
  cin.ignore();
  strcpy(artist, ar);
}
char* music::getArtist(){
  char* ar = (char*)malloc(100*sizeof(char));
  strcpy(ar, artist);
  return artist;
}
