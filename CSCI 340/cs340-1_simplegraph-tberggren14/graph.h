/* 	Trevor Berggren
	z1906236
	CSCI 340 
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

class Graph {
 private:
  int                          size;
  std::vector<std::list<int> > adj_list;
  std::vector<char>            labels;
  map<int, bool>                 visited;


 public:
  Graph(const char* filename);
  ~Graph();
  int  Getsize() const;
  void Traverse();
  void Print() const;
};

#endif  // GRAPH_H
