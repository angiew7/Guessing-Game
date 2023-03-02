#include <iostream>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <fstream>
//#include "Table.h"
//#include <limits>
using namespace std;



struct Student{
  char* firstname = new char[30];
  char* lastname = new char[30];
  int id;
  Student* next = NULL;
  int hash;
  float gpa;
};
Student** Add(Student* student, Student** table, int size);
Student* Generate();
void Print(Student** table);
int Hash(Student* student, int size);
int main(){
  srand(time(NULL));
  bool running = true;
  int size = 100;
  Student** table = new Student*[size]; 
  //Add();
  //Table* current = new Table();
  while(running == true){
    cout << "Enter Command [ADD, PRINT, DELETE, QUIT]: ";
    char input[10];
    cin >> input;
    cin.ignore();

    if(strcmp(input, "ADD")==0){
      cout << "How many students do you want to generate? ";
      int num = 0;
      cin >> num;
      cin.ignore();
      int i = 0;
      //if(i<=num){
      
      for(int i = 0; i <num; i++){
	//srand((unsigned)time(NULL));

	//Student* newStu = new Student();
	Student* newStu = Generate();
	newStu->id = 418972;
	newStu->hash = Hash(newStu, size);
	if(table[Hash(newStu, size)]!=NULL){
	  table[Hash(newStu, size)]->next = newStu;
	  cout << "col: " << table[Hash(newStu, size)]->next->firstname;

	  }
	else{
	  table = Add(newStu, table, size);
	}
      }
      //if collision
    }

    if(strcmp(input, "PRINT")==0){
      Print(table);
    }
    if(strcmp(input, "QUIT")==0){
      running = false;
    }
    cout << endl;
  }
  return 0;
}
Student** Add(Student* student, Student** table, int size){
  //get hash
  /*student->hash = (student->id/2)%size;
  cout << student->hash;
  //collision
  if(table[student->hash]!=NULL){
    cout << "yes";
    table[student->hash] = collision;
    cout << "col: " << table[student->hash]->next->firstname;
  }
  else{
  */
    table[student->hash] = student;
  
    cout << table[student->hash]->firstname << endl;
  
    return table;
}

void Print(Student** table){
  //cout << "hi:";
  for(int i = 0; i < 100; i++){
  
  if(table[i]!=NULL){
      cout << "First Name: " << table[i]->firstname << endl;
     cout << "Last Name: " << table[i]->lastname << endl;
     cout << "ID: " << table[i]->id << endl;
     //only print to 2 decimal places
     cout << setprecision(2) << fixed;
     cout << "GPA: " << table[i]->gpa << endl;
     
     //if(table[i]->next!=NULL){
       Student* current = table[i];
       //cout << "hi";
       while(current->next!=NULL){
	 cout << "hi";
       cout << "First Name: " << current->firstname << endl;
       current = current->next;
       }
       cout << endl;
     
  }
  }
}
int Hash(Student* student, int size){
  //table[studnet->hash]->next = student;
  student->hash = (student->id/2)%size;
  cout << student->hash;
  return student->hash;
}
  
Student* Generate(){
  
  Student* student = new Student();
  //srand((unsigned int)time(NULL));
  //first name
  int fNameLine = rand()%100;
  
  int lineNum = 0;
  ifstream file("firstName.txt");
  char line[40];
  while(fNameLine!=lineNum && file.getline(line, sizeof(line))){
     //cout << "gelp";
     //cout << line<<endl;;
    ++lineNum;
  }
  if(lineNum==fNameLine){
    //file>>line;
    //cout << line <<endl;
     
    strcpy(student->firstname, line);
  
    //cout << student->firstname << endl;
  }
  file.close();
  cout << student->firstname << endl;
  
  //lastname
  int lNameLine = rand()%100;
  lineNum =0;
  ifstream lFile("lastName.txt");
  char* lLine = new char[40];
  while(lNameLine!=lineNum && lFile.getline(lLine, sizeof(line))){
     //cout << "gelp";
     //cout << line<<endl;;
    ++lineNum;
  }
  //cout << student->firstname << endl;
  if(lineNum==lNameLine){
    //file>>line;
    cout << lLine <<endl;
    strcpy(student->lastname, lLine);
    //cout << student->firstname << endl;

  }
  lFile.close();
  //cout << student->lastname << " " << student->firstname << endl;
  int studentID = rand()%600000;
  student->id = studentID;
  //gpa
  //srand((unsigned int)time(NULL));
  float a = rand()%100;
  float gpa = float(rand()%5+float(0.01*a));
  student->gpa = gpa;
  cout << setprecision(2) << fixed;
  cout << gpa << endl;
  cout << student->id << endl;
  return student;
}
