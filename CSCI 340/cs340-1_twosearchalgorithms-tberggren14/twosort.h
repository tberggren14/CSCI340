/* 	Trevor Berggren
	z1906236
	CSCI 340 
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

#ifndef TWOSORT_H
#define TWOSORT_H

#include <iostream>
#include <ostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iomanip>


using namespace std;

#define ARRAY_SIZE 200
#define TEST_ARRAY_SIZE 100
#define NUM_ITEMS 16
#define ITEM_W 4
#define LOW 1
#define HIGH 1000

void generateVectors(vector<int> &v1, vector<int> &v2, int s1, int s2);
bool linearSearch(const vector<int> &v, int x);
bool binarySearch(const vector<int> &v, int x);
int searchVector(const vector<int> &v1, const vector<int>& v2, bool(*p)(const vector<int> &, int));
void sortVector(vector<int> &v);
void printVector(const vector<int > &v);
void printStat(int totalSucCnt, int vectorSz);

#endif
