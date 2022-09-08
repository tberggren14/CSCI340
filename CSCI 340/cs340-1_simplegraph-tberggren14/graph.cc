/* 	Trevor Berggren
	z1906236
	CSCI 340 
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

#include "graph.h"

// does DFS 
//constructor
Graph::Graph(const char* filename)
{
    ifstream file(filename);    //prepare file
    list<int> temp;             // temp
    adj_list.resize(7);         // resizes
    adj_list.push_back(temp);   // preps adj_list

    char c;                 
    string line,ignore;
    char foo;
    int x;
    int index = 0;
    
    file >> size;               // puts first text into size

    for(int i = 0; i < size; i++)   // loops to get all the labels
    {
        file >> c;
        labels.push_back(c);        // pushs them onto labels
    }

    getline(file,ignore);           // ignores no line
   

    while(getline(file,line))       // loops to get matrix
    {  
        istringstream iss (line);
        iss >> foo;
       
       
        while(iss >> x)             // get the numbers
        {
            if(x == 1)              // if is a adj pushes that and the index
            {
                adj_list[index].push_front(x);
                
        
            }
        } 

    index++;
    }
}

//deconstructor
Graph::~Graph()
{
    for (unsigned i = 0; i < labels.size(); i++)    //loops and pops
    labels.pop_back();

  
  for (unsigned j = 0; j < adj_list.size(); j++)    //loops and pops
    adj_list.pop_back();

}

// returns the size 
int Graph::Getsize() const 
{ 
    return size;
  
}

//traverse the graph and call Depthfirst


//print function
void Graph::Print() const 
{
    
    cout << "\nNumber of vertices in the graph: " << size << endl;

    cout << "\n-------- graph -------";

    for(int i = 0; i < size; i++)       
    {
       cout << endl << labels[i] << ": ";
      

       for(auto x : adj_list[i])        
       {
           cout << adj_list[x].front() << ", " ; 
       }
    }

    cout << endl << "------- end of graph ------\n";
 

}