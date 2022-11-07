#include <iostream>
#include "movies.h"
using namespace std;

/*virtual void movies::print(vector<parent*>&list, int i){
  cout << "Duration (min): " << ((movies*)list[i])->getDuration() << endl;
}
*/
movies::movies(){

}
int movies::getDuration(){
  return duration;
}
void movies::setDuration(){
  int d = 0;
  cin >> d;
  cin.ignore(50, '\n');
  duration = d;
}
void movies::setRating(){
  float r = 0;
  cin >> r;
  rating = r;
}
float movies::getRating(){
  return rating;
}
