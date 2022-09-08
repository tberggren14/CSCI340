/*	Trevor Berggren
*	z1906236
*	CSCI 340 
*	I certify that this is my own work and where appropriate an extension 
*	of the starter code provided for the assignment.
*/


#ifndef WORDSCANNER_H
#define WORDSCANNER_H

#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>

#define NO_ITEMS 4
#define ITEM_WORD_WIDTH 14
#define ITEM_COUNT_WIDTH 3

using namespace std;

void get_words(map<string, int>&);
void print_words(const map<string, int>&);
void clean_entry(const string&, string&);

map<string, int> word;
string original_line;
string clean_line;
int cnt;

#endif

