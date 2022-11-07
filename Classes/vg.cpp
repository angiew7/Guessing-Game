#include <iostream>
#include "vg.h"
using namespace std;

vg::vg(){

}

float vg::getRating(){
  return rating;
}
void vg::setRating(){
  float r = 0;
  cin >> r;
  cin.ignore();
  rating = r;
}
