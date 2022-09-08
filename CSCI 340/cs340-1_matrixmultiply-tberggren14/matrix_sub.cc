/* 	Trevor Berggren
	z1906236
	CSCI 340 
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

#include "matrix.h"

/********************************************************************************
 * void
 * @param ifstream is1
 * @param ifstream is2
 * function opens the file
 ********************************************************************************/
void open_files(ifstream &is1, ifstream &is2) 
{

    is1.open(FILE1);    // opens file 1

    if(!is1.is_open())      // check to see if file opened
    {                       // prints error it fail
        cout << "Error opening file 1";
        exit(0);
    }

    is2.open(FILE2);        // opens file 2

    if(!is2.is_open())      // checks if opened
    {                       // prints error if fail
        cout << "Error opening file 2";
        exit(0);
    }
    
    
}

/********************************************************************************
 * void
 * @param vector m
 * @param ifstream is
 * function reads data for file
 ********************************************************************************/
void read_data(ifstream &is, vector<vector<int>> &m)
{
    int temp;       // declare temp varible

    for(size_t i = 0; i < m.size(); ++i)    // loop to go over the rows 
    {
        for(size_t j = 0; j < m[i].size(); ++j)
        {                                   // loops through and stores data in temp
            is >> temp;                     // then puts into vector
            m[i][j] = temp;
        }
    
    }
    

}

/********************************************************************************
 * void
 * @param vector v
 * @param int x
 * function does a linear search 
 ********************************************************************************/
void print_data(const vector<vector<int>> &m)
{
    int col;                
    for (size_t i = 0; i < m.size(); i++)   // gets the amount of columns 
    {
        col = m[i].size();
    }
    cout << m.size() << " X " << col << endl;   // prints how many rows and cols there are
    cout << "----------------------------------------------------------------------" << endl;

    for (size_t i = 0; i < m.size(); i++)       // prints the data needed
    {                                           // in the right amount of rows and cols 
		for(size_t j = 0; j < m[i].size(); j++)
        {
        cout << setw(ITEM_W) << m[i][j];
        }
        cout << '\n';
	}
}

/********************************************************************************
 * void
 * @param vector A
 * @param vector B
 * @param vector C
 * function generate the data 
 ********************************************************************************/
void gen_data(const vector<vector<int>> &A, const vector<vector<int>> &B, vector<vector<int>> &C) 
{
    
    for(size_t i = 0; i < A.size(); i++)    // loops over vector a
        for (size_t j = 0; j < B[i].size(); j++)        // loops over the cols of data B
            for(size_t k = 0; k < B.size(); k++)        // loops over the rest of B
    {
                C[i][j] += A[i][k] * B[k][j];           // the * of the matrix
    } 
    
}
