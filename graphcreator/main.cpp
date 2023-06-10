/*
  Angie Wang
  6/9/2023
  Using an adjancency table and list to represent a graph, the user can add vertices and edges, delete, and find the shortest path between two vertices
 */
#include <iostream>
#include <cstring>
#include <vector>
#include <limits>
using namespace std;

struct Node{
  char label;
  int index;
};
void addVertex(vector<Node*>&list);
void addEdge(int table[20][20], vector<Node*>&list);
void Print(int table[20][20], vector<Node*>&list);
void removeVertex(int table[20][20], vector<Node*> &list);
void removeEdge(int table[20][20],  vector<Node*> &list);
void shortPath(int table[20][20], vector<Node*> &list);
  
int main(){
  //Node* list [21];
  vector<Node*>list;
  int table[20][20];
  bool running = true;

  for(int i = 0; i<20;i++){
    for(int j = 0; j<20; j++){
      table[i][j] = 0;
    }
  }
  while(running == true){
    cout << "Enter a command: [ADD] [PRINT] [DELETE] [SHORT] [QUIT]" << endl;
    char input[10];
    cin >> input;
    cin.ignore();
    if(strcmp(input, "ADD")==0){
      cout << "Add a [VERTEX] or [EDGE]? ";
      cin >> input;
      cin.ignore();
      if(strcmp(input, "VERTEX")==0){
	addVertex(list);
      }
      if(strcmp(input, "EDGE")==0){
	addEdge(table, list);
      }
      
    }
    if(strcmp(input, "PRINT")==0){
      Print(table, list);
    }
    if(strcmp(input, "DELETE")==0){
     cout << "Remove a [VERTEX] or [EDGE]? ";
      cin >> input;
      cin.ignore();
      if(strcmp(input, "VERTEX")==0){
        removeVertex(table, list);
      }
      if(strcmp(input, "EDGE")==0){
        removeEdge(table, list);
      }

    }
    if(strcmp(input, "SHORT")==0){
      shortPath(table, list);
    }

    if(strcmp(input, "QUIT")==0){
      running = false;
    }
  }
  
  return 0;
}

void addVertex(vector<Node*>& list){
  Node* node = new Node();
  cout << "Enter a single char label: ";
  char newLabel;
  cin >> newLabel;
    node->label = newLabel;
  
  list.push_back(node);
  node->index = list.size()-1;
}
void addEdge(int table[20][20], vector<Node*>&list){
  char label1;
  cout << "Enter first vertex label: ";
  cin >> label1;
  char label2;
  cout << "Enter second vertex label: ";
  cin >> label2;
  int weight = 0;
  cout << "Enter weight of edge: ";
  cin >> weight;
  int x, y;
  for(int i = 0; i < list.size(); i++){
    if(list[i]->label == label1){
      x = i;
      cout << x << endl;
    }
    if(list[i]->label == label2){
      y = i;
      cout << y << endl;
    }
  }
  table[x][y] = weight;
  
}

void Print(int table[20][20], vector<Node*>&list){
  //print list
  for(int i = 0; i < list.size(); i++){
    if(list[i]!=NULL){
      cout << list[i]->index << ". " << list[i]->label << endl;
    }
  }
  cout << endl;
  
  
  cout << endl;
  for(int x = 0; x < list[list.size()-1]->index+1; x++){
    //cout << x << '\t';
    for(int y = 0; y < list[list.size()-1]->index+1; y++){
      //if nothing there
      if(table[x][y]==0){
	cout << "0 ";
      }
      else{
	cout << table[x][y]<<' ';
      }
    }
    cout << ' ' << endl;
  }
  
}
void removeVertex(int table[20][20], vector<Node*> &list){
  char input;
  cout << "Enter the label of the vertex that you want to remove: ";
  cin >> input;
  int index = 0;
  for (int i = 0; i< list.size(); i++){
    if(list[i]->label == input)
      index = i;
  }
  // Erase all edges with that vertex
  for (int x = 0; x< 20; x++){
    for (int y = 0; y< 20; y++){
      if(x == index || y == index){
	table[x][y] = 0;
	
      }
    }
  }
  list.erase(list.begin()+index);
}

void removeEdge(int table[20][20], vector<Node*> &list){
  char label1;
  cout << "Enter first vertex label: ";
  cin >> label1;
  char label2;
  cout << "Enter second vertex label: ";
  cin >> label2;
  int x, y;
  // find vertex index and delete
  for(int i = 0; i < list.size(); i++){
    if(list[i]->label == label1){
      x = i;
    }
    if(list[i]->label == label2){
      y = i;
    }
  }
  table[x][y] = 0;

  
}

void shortPath(int table[20][20], vector<Node*> &list) {
  char label1;
  cout << "Enter first vertex label: ";
  cin >> label1;
  char label2;
  cout << "Enter second vertex label: ";
  cin >> label2;

  int source = -1, end = -1;

  // find vertex indices
  for (int i = 0; i < list.size(); i++) {
    if (list[i]->label == label1) {
      source = i;
    }
    if (list[i]->label == label2) {
      end = i;
    }
  }

  if (source == -1 || end == -1) {
    cout << "One or both vertices not found." << endl;
    return;
  }

  int INF = 1000;
  vector<int> path(list.size());
  int dist[20];
  bool visited[20];

  // initialize
  for (int i = 0; i < 20; i++) {
    visited[i] = false;
    dist[i] = INF;
  }

  dist[source] = 0;
  path[source] = -1;

  int current, closest;
  bool pathFound = false;

  for (int count = 0; count < list.size() - 1; count++) {
    current = -1;
    closest = INF;

    // Find the closest unvisited vertex
    for (int i = 0; i < list.size(); i++) {
      if (!visited[i] && dist[i] <= closest) {
        current = i;
        closest = dist[i];
      }
    }

    visited[current] = true;

    // Update distances
    for (int j = 0; j < list.size(); j++) {
      if (!visited[j] && table[current][j] != INF && dist[current] != INF && dist[current] + table[current][j] < dist[j]) {
        dist[j] = dist[current] + table[current][j];
        path[j] = current;
      }
    }
    
    // Mark vertices with weight 0 as visited
    for (int j = 0; j < list.size(); j++) {
      if (table[current][j] == 0) {
        visited[j] = true;
      }
    }
  }

  if (dist[end] == INF||dist[end]==0) {
    cout << "No path exists between the vertices." << endl;
    return;
  }

  // Print the minimum distance and path
  cout << "Minimum distance: " << dist[end] << endl;
  cout << "Path: ";

  vector<int> actualPath;
  int vertex = end;

  while (vertex != -1) {
    actualPath.push_back(vertex);
    vertex = path[vertex];
  }

  for (int i = actualPath.size() - 1; i >= 0; i--) {
    cout << list[actualPath[i]]->label;
    if (i != 0) {
      cout << " -> ";
    }
  }

  cout << endl;
}

