/* 	Trevor Berggren
	z1906236
	CSCI 340 
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

#include "twosort.h" 

int
main()
{
    // declaring varibles
    int SEED1 = 1;
    int SEED2 = 3;
    vector<int> v1(ARRAY_SIZE);
    vector<int> v2(TEST_ARRAY_SIZE);
    
    // calling needed functions
    generateVectors(v1, v2, SEED1, SEED2);

    printVector(v1);

    sortVector(v1);

    printVector(v1);

    printVector(v2);

    //assigning totalSuccnt to the results of search vecotr for linear search 
    int totalSucCnt = searchVector(v1, v2, linearSearch);
    // assigning the vector size to v2
    int vectorSz = v2.size();

    // prints the stats of the search 
    cout << "Linear Search: Percent of Successful Searches = ";
    printStat(totalSucCnt,vectorSz);

    //assigning totalSuccnt to the results of search vecotr for binary search 
    totalSucCnt = searchVector(v1, v2, binarySearch);

    // assigning the vector size to v2
    vectorSz = v2.size();

    // prints the stats of the search 
    cout << "Linear Search: Percent of Successful Searches = ";
    printStat(totalSucCnt, vectorSz);

	return 0;

}// End of main() routine.


/********************************************************************************
 * void
 * @param vector v1 
 * @param vector v2
 * @param int s1 seed1
 * @param int s2 seed2
 * function generates the vector
 ********************************************************************************/
void generateVectors(vector<int> &v1, vector<int> &v2, int s1, int s2) 
{
    srand(s1);  // sets the seed
    for (int x = 0; x < ARRAY_SIZE; x++)    // loop to fill the vector
    {                                       // with rand numbers
    v1[x] = ( rand() % (HIGH - LOW +1 ) + LOW);
    }
    

    srand(s2);  // sets the seed
    for (int x = 0; x < TEST_ARRAY_SIZE; x++)// loop to fill the vector
    {                                       // with rand numbers
    v2[x] = ( rand() % (HIGH - LOW +1 ) + LOW);
    }
    


}

/********************************************************************************
 * returns a bool
 * @param vector v
 * @param int x
 * function does a linear search 
 ********************************************************************************/
bool linearSearch(const vector<int> &v, int x)
{   // stl find to binary search 
  auto it = find(v.begin(),v.end(),x);
  return (it != v.end());   // return it 

}

/********************************************************************************
 * returns a bool
 * @param vector v
 * @param int x
 * function does a binary search
 ********************************************************************************/
bool binarySearch(const vector<int> &v, int x)
{   // returns the bool binary search 
    return (binary_search(v.begin(), v.end(), x));
}

/********************************************************************************
 * returns a int
 * @param vector v1 
 * @param vector v2
 * @param *p
 * function searches the pointer and incement counts
 ********************************************************************************/
int searchVector(const vector<int> &v1, const vector<int>& v2, bool(*p)(const vector<int> &, int x))
{   // declare count
    int count;

    // loop v2 size 
    for (size_t x = 0; x < v2.size(); x++)
    {
        if(p(v1,v2[x]))
        {   // incerment count
            count++;
        }
    }   // return count
    return count;
}

/********************************************************************************
 * void
 * @param vector v
 * function sorts
 ********************************************************************************/
void sortVector(vector<int> &v)
{   // sort vector
    sort(v.begin(),v.end());
}

/********************************************************************************
 * void
 * @param vector v
 * function prints
 ********************************************************************************/
void printVector(const vector<int > &v)
{
    // loop through v 
    for(size_t t = 0; t < v.size(); t++)
    {   // print with a width and the vector
        cout << setw(ITEM_W) << v[t];
        if((t + 1)%NUM_ITEMS == 0)  // if == 16 newline
        {
            cout << '\n';
        }
    }
    cout << endl;
    }
    
/********************************************************************************
 * void
 * @param int totalSucCnt
 * @param int vectorSz
 * function prints stats of the search 
 ********************************************************************************/
void printStat(int totalSucCnt, int vectorSz)
{   // prints the stats of the total search matches
    cout << fixed << setprecision(2) << ((double )totalSucCnt*100)/vectorSz << " %" << endl << endl;;
    
}
