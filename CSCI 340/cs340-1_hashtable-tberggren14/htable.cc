/*	Trevor Berggren
*	z1906236
*	CSCI 340 
*	I certify that this is my own work and where appropriate an extension 
*	of the starter code provided for the assignment.
*/

#include "htable.h"

#define N1 10  // num of decimal digits
#define N2 26  // num of upper-case letters

// compare function used in sort
bool cmp(Entry *p, Entry *q) {return p->key < q->key;}

// Hash function, you may NOT modify this function
int HT::hash(const string &s) {
  int n = (N2 * N1) * (s[0] - 'A') + N1 * (s[1] - 'A') + (s[2] - '0');

  return n % hsize;
}

// Constructor
HT::HT(const unsigned &hs) : hsize(hs), hTable(hs){}

// Deconstructor
HT::~HT() 
{
  // loop through hash table then pop off
  for (unsigned i = 0; i < hTable.size(); i++)
    hTable.pop_back();

  // loop through pointer table then pop off
  for (unsigned j = 0; j < pTable.size(); j++)
    pTable.pop_back();
}

// insert function 
// @Param Entry &e
void HT::insert(const Entry &e) 
{
  // call hash function using e.key
  int index = hash(e.key);

  // Decalre and assign the index of hTable
  list<Entry> &l = hTable[index];

  // Find_if returns l.cend if key is not find
  auto it = find_if(l.begin(), l.end(),
  [&](const Entry &a) { return e.key == a.key;});

  // if not found will push to htable and push location to ptable
  // prints entry index
  if(it == l.cend())
  {
    l.push_front(e);
    pTable.push_back(&l.front());

    cout << " entry =  " << index << endl;
  }

    else  // if found wont insert
    {
      cout << " not inserted - duplicate key!!!" << endl;
    }

}

//search function 
// @param string &s
void HT::search(const string &s) 
{
  // call hash function using s 
  int index = hash(s);

  // Decalre and assign the index of hTable
  list<Entry> l = hTable[index];


  // Find_if returns l.cend if key is not found
  auto it = find_if(l.begin(), l.end(),
  [&](const Entry &a) { return a.key == s;});

  // search is succesful if it is not equal to cend
  // prints results of the search with key
  if(it != l.cend())
  {
    cout << " ==> number:" << setw(5) << hTable[index].back().num << " - item: " << hTable[index].back().desc << endl;
  }

  else
  cout << " not in table!!" << endl;

}

//Print the hTable
void HT::hTable_print() 
{
  // Decalre a temp Entry struc
  Entry temp;
  cout << endl;

  // loops through vector
  for(auto it = hTable.begin(); it != hTable.end(); ++it)
  {
    // loops through the Entry list
    for(auto iter = (*it).begin(); iter != (*it).end(); iter++)
    {
      // assigns to be able to print
      temp = *iter;
      cout << setw(4) << left << hash(temp.key) << ":" << setw(5) << temp.key << "  - " << setw(5) << temp.num
      << "  -  " << setw(ITEM_SZ) << temp.desc << endl;
    }
  }

}

// prints the pTable
void HT::pTable_print() 
{
  // sort the pointer table
  sort(pTable.begin(), pTable.end(),cmp);

    // loops through the pointer table
    for(auto &x : pTable)
    {
      cout << setw(6) << right << x->key << "  -" << setw(6) << right << x->num << "  -  " << x->desc << endl;
    }

    
}