#include "heap.h"

template <typename T>
void get_list(vector<T> &v, const char *path) 
{

  while(!v.empty())         // while v isnt empty 
    v.pop_back();           // delete contents

  ifstream in(path);        // declare ifstream vari and temp T
  T temp;

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

  in.close();               // closes file in use

}

template <typename T, typename P>
void construct_heap(vector<T> &v, P pred) 
{
  make_heap(v.begin(), v.end(),pred ); // using make_heap from stl
  sort_heap(v.begin(), v.end(),pred);  // using sort_heap from stl
}


int main() {
  vector<int>    v1;  // heap of integers
  vector<float>  v2;  // heap of floating-pt nums
  vector<string> v3;  // heap of strings

  // print header message
  cout << "      *** Heaps and Heapsort - Output ***\n\n";

  // first heap

  cout << "first heap - ascending order:\n\n";
  get_list(v1, D1);
  construct_heap(v1, less<int>());
  print_list<int> print1(v1.size(), INT_SZ, INT_LN);
  for_each(v1.begin(), v1.end(), print1);

  cout << "first heap - descending order:\n\n";
  get_list(v1, D1);
  construct_heap(v1, greater<int>());
  for_each(v1.begin(), v1.end(), print1);

  // second heap

  cout << "second heap - ascending order:\n\n";
  get_list(v2, D2);
  construct_heap(v2, less<float>());
  print_list<float> print2(v2.size(), FLT_SZ, FLT_LN);
  for_each(v2.begin(), v2.end(), print2);

  cout << "second heap - descending order:\n\n";
  get_list(v2, D2);
  construct_heap(v2, greater<float>());
  for_each(v2.begin(), v2.end(), print2);

  // third heap

  cout << "third heap - ascending order:\n\n";
  get_list(v3, D3);
  construct_heap(v3, less<string>());
  print_list<string> print3(v3.size(), STR_SZ, STR_LN);
  for_each(v3.begin(), v3.end(), print3);

  cout << "third heap - descending order:\n\n";
  get_list(v3, D3);
  construct_heap(v3, greater<string>());
  for_each(v3.begin(), v3.end(), print3);

  // print termination message
  cout << "      *** end of program execution ***\n\n";
  return 0;
}
