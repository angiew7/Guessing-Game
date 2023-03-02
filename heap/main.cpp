/*
Angie Wang
3/2/2022
This program uses a max heap to store up to 100 values using user input or randomly generated from file.
Can delete the biggest element or all the elements
 */
#include <iostream>
#include <ctime>
#include <fstream>
#include <cstring>
#include<ctype.h>
#include <string>

using namespace std;
void Add(int num, int* arr);
void Print(int* arr, int i, int depth);
void Delete(int* arr, int i);
main(){
  srand(time(NULL));
  int arr[101]; 
  bool running = true;
  for(int i = 0; i<=100; i++){
    arr[i] = 0;
  }
  while(running == true){
    char input[8];
    cout << "Type a command [ADD, DELETE, PRINT, QUIT] ";
    cin >> input;
    cin.ignore();
    if(strcmp(input, "ADD")==0){
	cout << "[GENERATE] or [MANUAL] ";
	cin >> input;
	cin.ignore();
	if(strcmp(input, "MANUAL")==0){
	    int num = 0;
	    cout << "Enter Num: ";
	    cin >> num;
	    Add(num, arr);
	  }
	if(strcmp(input, "GENERATE")==0){
	  cout << "How many numbers do you want to generate? ";
	  int n = 0;
	  cin >> n;
	  cin.ignore();
          for(int i = 0; i < n; i++){
	  ifstream file("numbers.txt");
	    int count = 0;
	    int random = rand()%100;
	    int num = 0;
	    char* word = new char();
	    while(file>>word && count != random){
	      num = stoi(word);
	      count++;
	    }
	    cout << word <<"num "<< num << endl;
	    Add(num, arr);
	    file.close();
      }
	}
    }
    
    if(strcmp(input, "PRINT")==0){
      //cout << arr[1] << endl;
      Print(arr, 1, 0);
      }
    if(strcmp(input, "DELETE")==0){
      cout << "DELETE [ALL] or [ONE] (One deletes the largest number) ";
      cin >> input;
      cin.ignore();
      if(strcmp(input, "ONE")==0){
	
	int i = 1;
	/*
	while(arr[i] != num){
	  //num++;
	  i++;
	}
	*/
	cout << "i:" << i << endl;
	Delete(arr, 1);

      }
      if(strcmp(input, "ALL")==0){
	int i = 1;
	while(arr[i]!=0){
	  Delete(arr, i);
	}
      }
      }

    if(strcmp(input, "QUIT")==0){
      //cout << arr[1] << endl;
      running = false;
      }

  }
  return 0;
}
void Add(int num, int* arr){
  bool placed = true;
  int i = 1;
  
  
  
  //count # of elements
  while(arr[i]!=0){
    i++;
  }
  cout << "i" << i << endl;
  
  arr[i] = num;
  //swap with parent if bigger
    while(arr[i/2]<num && i!=1){
      int temp = arr[i];
      arr[i] = arr[i/2];
      arr[i/2] = temp;
      i = i/2;
    }
    /*
  for(int i = 0; i <= 100; i++){
    if(arr[i]!=0){
      cout << i << " , " << arr[i] << endl;
    }
    }
    */

}
void Print(int* arr, int i, int depth){
  //right 
  if(arr[i*2+1] != 0){
    Print(arr, i*2+1, depth+1);
  }
  //print tabs 
    for(int x = 0; x < depth; x++){
      cout << '\t';
    }
    cout << arr[i] << endl;
    //check left
    if(arr[i*2]!=0){
      Print(arr, i*2, depth+1);
    }
    
}
void Delete(int* arr, int i){
  //output
  cout << "Deleted: " << arr[i] << endl;
  //set as root
  int size = 1;
  while(arr[size]!=0){
    size++;
  }
  size = size-1;
  
  //swap last element with deleted
  arr[i] = arr[size];
  arr[size] = 0;
  
  //find biggest child
  
  int biggest = 0;
  int x = i;
  
  while(arr[x]<arr[x*2]||arr[x]<arr[x*2+1]){
    int temp = 0;
    //smaller than left
  if(arr[x]<arr[x*2] && arr[x*2+1]<=arr[x*2]){
   
       temp = arr[x];
       arr[x] = arr[x*2];
       arr[x*2] = temp;
       x = x*2;
    
  }
  //smaller than right
  else if(arr[x]<arr[x*2+1]&&arr[x*2+1]>=arr[x*2]){
    temp = arr[x];
    arr[x] = arr[x*2+1];
    arr[x*2+1] = temp;
    x = x*2+1;
  }
  }
  
}

