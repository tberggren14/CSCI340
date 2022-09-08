/*	Trevor Berggren
*	z1906236
*	CSCI 340 
*	I certify that this is my own work and where appropriate an extension 
*	of the starter code provided for the assignment.
*/


#include "wordscanner.h"

int main()
{
    // calls get_words to get words from stdin
    get_words(word);

    print_words(word);  // calls print_words to print the map

}

/********************************************************************************
 * void
 * @param int val
 * function pushes a value on the queue 
 ********************************************************************************/
void get_words(map<string, int>& word)
{                     
    while(cin >> original_line)         // will run while getting from cin
    { 
        clean_entry(original_line,clean_line);      // calls clean_entry to clean the input

        if(clean_line.length() == 0)                // if clean_line is all punc
        {                                           // just skips that word 
            return;
        }
        else
        word[clean_line]++;                         // adds clean_line to map word and adds 1
        cnt++;                                      // adds one to count 

   
    }

}

/********************************************************************************
 * void
 * @param int val
 * function pushes a value on the queue 
 ********************************************************************************/
void print_words(const map<string, int>& word)
{
    int num_line = 0;                               // decalring varibles needed
    auto map_it = word.begin();                     // num_line is for lines and map_it is start of word

    while(map_it != word.end())                     // will run while not the end 
    {
        num_line++;                                 // adds one to num_line and prints first and second from map
        cout << setw(ITEM_WORD_WIDTH) << left << map_it->first << ":" << setw(ITEM_COUNT_WIDTH)  << left  << map_it->second;

        if((num_line % NO_ITEMS) == 0)              // if num_line == 4 prints new line
        {
            cout << endl;
            num_line = 0;                           // resets num_line
        }
        ++map_it;                                   // next value of map_it
    }
    cout << endl;                                   // prints number of inputs and then what we changed
    cout << "number of words in input stream " << setw(ITEM_COUNT_WIDTH) << right << ":" << cnt << endl;
    cout << "number of words in output stream" << setw(ITEM_COUNT_WIDTH) << right << ":" << word.size() << endl;


}

/********************************************************************************
 * void
 * @param int val
 * function pushes a value on the queue 
 ********************************************************************************/
void clean_entry(const string& original_line, string& clean_line )
{
    size_t start = 0;                               // index varibles
    size_t end = 0;

    // will run while not a alphanum
    while(!isalnum(original_line[start]) && start < original_line.length())     
        start++;

    end = start;                                    // end is the start
    
    // will run while getting alphanum
    while(isalnum(original_line[end]) && end < original_line.length())
            end++;

    // assigning to clean line and putting everything to lowercase using a lambda expressions
    clean_line = original_line.substr(start,(end - start));
    for_each(clean_line.begin(),clean_line.end(),
    [](char &c) { c = tolower(c); });
}
