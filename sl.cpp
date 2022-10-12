/*
  Angie Wang 
  10/11/2022
  Ask user for a command-
  ADD: asks user for first and last name, ID, and GPA
  PRINT: Prints out all students and their information
  DELETE: Asks user for a ID to delete 
  QUIT: Stops running
 */
#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;

struct Student{
  char firstname[10];
  char lastname[10];
  int id;
  float gpa;
};

void Add(vector<Student*>* v, Student*s);
void Print(vector<Student*>& v);
void Delete(vector<Student*>& v);

int main(){
  vector<Student*> list;
  Student *s;
  bool running = true;
  char input[7];
  //run until user quits
  while(running == true){
    //char input[7];
    //enter command
    cout << "Enter command: ADD, DELETE, PRINT, OR QUIT" << endl;
    cin.getline(input, 8, '\n');
    if(strcmp(input, "ADD") == 0){
      //create new student pointer
      Student *s = new Student();
      Add(&list, s);
    }
    else if(strcmp(input, "PRINT") == 0){
      Print(list);
    }
    else if(strcmp(input, "DELETE") == 0){
      Delete(list);
    }
    else if(strcmp(input, "QUIT") == 0){
      running = false;
    }
    //else{
    //cout << "Enter a real command!" << endl;
    //}
  }
  
  return 0;
}
void Add(vector<Student*>* v, Student*s){
  char first[10];

  //first name
  cout << "Enter first name:" << endl;
  cin.getline(first, 11, '\n');
  strcpy(s->firstname, first); 
  
  //last name
  cout << "Enter last name: " << endl;
  char last[10];
  cin.getline(last, 11, '\n');
  strcpy(s->lastname, last);

  //id
  cout << "Enter ID: " << endl;
  int i_d;
  cin >> i_d;
  s->id = i_d;

  //gpa
  cout << "Enter GPA: " << endl;
  float GPA;
  cin >> GPA;
  s->gpa = GPA;

  //push to element to back of vector
  v->push_back(s);
}

void Print(vector<Student*>&v){
  int size = v.size();
  for(int i = 0; i <  size; i++){
     cout << "First Name: " << v[i]->firstname << endl;
     cout << "Last Name: " << v[i]->lastname << endl;
     cout << "ID: " << v[i]->id << endl;
     //only print to 2 decimal places
     cout << setprecision(2) << fixed;
     cout << "GPA: " << v[i]->gpa << endl;

  }
  
}

void Delete(vector<Student*>&v){
  int newID = 0;
  cout << "Which ID would you like to be deleted?" << endl;
  cin >> newID;
  //look for the id inputed and then delete it
  for(int i = 0; i < v.size(); i++){
    if(v[i]->id == newID){
      v.erase(v.begin()+ i);
    }
  }
}
