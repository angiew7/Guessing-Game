/*
  This program stores students in a linked table. User can ask to add a student
  manually or by generating a certain amount randomly.
  Angie Wang
  2/17/2023
 */
#include <iostream>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <time.h>
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
void Print(Student** table, int size);
Student** Collision(Student** table, int size);
int Hash(Student* student, int size);
void Delete(Student** table, int size);
int main(){
  srand(time(NULL));
  bool running = true;
  int size = 100;
  Student** table = new Student*[size];
  
  while(running == true){
    //enter command
    cout << "Enter Command [ADD, PRINT, DELETE, QUIT]: ";
    char input[10];
    cin >> input;
    cin.ignore();

    if(strcmp(input, "ADD")==0){
      cout << "[MANUAL] or [GENERATE] entry? ";
      cin >> input;
      cin.ignore();
      if(strcmp(input, "GENERATE")==0){
      cout << "How many students do you want to generate? ";
      int num = 0;
      cin >> num;
      cin.ignore();
      int i = 0;
      
      
      for(int i = 0; i <num; i++){

	Student* newStu = Generate();
	
	
	  table = Add(newStu, table, size);
	
        
    
	  cout << endl;
      
	  /*
      int collisions = 1;
      //check for collisions
      for(int i = 0 ; i<size && collisions<3; i++){
	collisions = 0;
	Student* current = table[i];
	if(current!=NULL){

	while(current!=NULL){
	  collisions++;
	  current = current->next;
	}
	}
	if(collisions > 3){

	  size = size*2;
	  table = Collision(table, size);
	}
	
      }
      }
	  */
	  
      }
      }
      //manual add
      else if(strcmp(input, "MANUAL")==0){
	Student* student = new Student();
	cout << "ID: ";
	cin >> student->id;
	cin.ignore();
	cout << "First Name: ";
	cin >> student->firstname;
	cin.ignore();
	cout << "Last Name: ";
        cin >> student->lastname;
        cin.ignore();
	cout << "GPA: ";
        cin >> student->gpa;
        cin.ignore();

	table = Add(student, table, size);
	}
      }
      

    if(strcmp(input, "PRINT")==0){
      Print(table, size);
    }
    if(strcmp(input, "DELETE")==0){
      Delete(table, size);
    }
    if(strcmp(input, "QUIT")==0){
      running = false;
    }
    cout << endl;
  }
  return 0;
}
Student** Add(Student* student, Student** table, int size){
   student->hash = Hash(student, size);
  Student* current = table[student->hash];
	int collisions = 1;
      	//no collisions
	if(current == NULL){
          
          table[student->hash] = student;
        }
	//if something is already there
	else if(table[student->hash]!=NULL){
	  
	  
          while(current->next!=NULL){
            current = current->next;
          
            collisions++;
          
	  }
	  
	  current->next = student;

	    if(collisions>=3){
	      size = size*2;
	      //Student** temp = (Student**)malloc(sizeof(Student*)*size);
              
              //temp = table;
              //table = new Student*[size];
              //cout << "hi " << size << endl;

              //table = (Student**)malloc(sizeof(Student*)*size);
	      cout << "collde" << endl;
	      table = Collision(table, size);

	    }
	    
	    

        }

	
  
    return table;
}

void Print(Student** table, int size){
  //cout << "hi:";
  for(int i = 0; i < size; i++){
    //print head
    if(table[i]!=NULL){
      cout << "First Name: " << table[i]->firstname << endl;
     cout << "Last Name: " << table[i]->lastname << endl;
     cout << "ID: " << table[i]->id << endl;
     //only print to 2 decimal places
     cout << setprecision(2) << fixed;
     cout << "GPA: " << table[i]->gpa << endl;
     cout<< endl;

       Student* current = table[i];


       //print the linked students
       while(current->next!=NULL){
	 
	 current = current->next;
	 cout << "next First Name: " << current->firstname << endl;
	 cout << "Last Name: " << current->lastname << endl;
	 cout << "ID: " << current->id << endl;
	 //only print to 2 decimal places
	 cout << setprecision(2) << fixed;
	 cout << "GPA: " << current->gpa << endl;
	 cout<< endl;
       }
       
     
  }
  }
}
int Hash(Student* student, int size){
  student->hash = student->id%size;
 
  return student->hash;
}
  
Student* Generate(){
  
  Student* student = new Student();
  int fNameLine = rand()%100;
  
  int lineNum = 0;
  ifstream file("firstName.txt");
  char line[40];
  //go thru each line until reaches random generated line number
  while(fNameLine!=lineNum && file.getline(line, sizeof(line))){
     
    ++lineNum;
  }
  if(lineNum==fNameLine){
    
     
    strcpy(student->firstname, line);
  
    
  }
  file.close();
  cout << student->firstname << endl;
  
  //lastname
  int lNameLine = rand()%100;
  lineNum =0;
  ifstream lFile("lastName.txt");
  char* lLine = new char[40];
  while(lNameLine!=lineNum && lFile.getline(lLine, sizeof(line))){
     
    ++lineNum;
  }
  
  if(lineNum==lNameLine){
  
    cout << lLine <<endl;
    strcpy(student->lastname, lLine);


  }
  lFile.close();

  int studentID = rand()%600000;
  student->id = studentID;
  //randomize gpa and id
  float a = rand()%100;
  float gpa = float(rand()%5+float(0.01*a));
  student->gpa = gpa;
  cout << setprecision(2) << fixed;
  cout << gpa << endl;
  cout << student->id << endl;
  return student;
}
Student** Collision(Student** table, int size){

  cout << size;

  Student** oldTable = table;
  table = new Student*[size];
  //clear table
  for(int h=0; h<size; h++){
    table[h] = NULL;
  }
  
  for(int i = 0; i < size/2; i++){
    Student* current = oldTable[i];
    if(current!=NULL){
    cout << "yass" << oldTable[i]->firstname<< endl;

      Student* current = oldTable[i];
      
	while(current!=NULL){
	  current->hash = Hash(current, size);
	  Student* temp = new Student();
	  // copy  student
	  temp->next = NULL;
	  temp->firstname = current->firstname;
	 
	  temp->lastname = current->lastname;
	  temp->gpa = current->gpa;
	  temp->id = current->id;
	 
	  table = Add(temp, table, size);
	  current = current->next;
	 
	  }
      
	}
    }
  delete oldTable;
  return table;
}
void Delete(Student** table, int size){
  int id = 0;
  
  cout << "Which ID do you want to delete? ";
  cin >> id;
  cin.ignore();
  for(int i = 0; i < size; i++){
    
    if(table[i]!=NULL){
      Student* temp = table[i];
      //head
      
      //if theres no chain
      if (temp->next == NULL){
	cout << "no chain"<<endl;
          if(temp->id==id){
	    table[i]=NULL;
	    //delete temp;
	    
	    
          }
        }
      //if it is the head of chain
      else if(table[i]->id==id){
        table[i] = table[i]->next;
      }

      else{
	Student* temp2;
	cout << "tem " << temp->next->firstname << endl;
	while(temp->id!=id){
	
	  temp2 = temp;
	  temp = temp->next;
	}
	
	
	temp2->next = temp->next;
	
	
      }
	  
    }
  }
	
	
}
    
      


      
  
  
  

