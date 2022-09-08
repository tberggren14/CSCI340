/* 	Trevor Berggren
	z1906236
	CSCI 340 
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/ 

#include "josephus.h"

int main()
{
	args in;
	cin >> in.N >> in.M >> in.K;	// gets the values needed from stdo

	list<string> L (in.N);			//  declares and sets list size
	
	size_t strings_count = 0;		// declare varibles
	size_t j = 0;

	init_vals(L,in); 				// calls func

	print_list(L,strings_count); 	// calls print 

	auto p = L.begin();				// sets p to the list begin
	
			while(L.size() != 1)		// runs while the list is not empty
			{
				j = (j + (in.M - 1)) % L.size();
		
			advance(p, j);				// makes j and itorator
			p = L.erase(p);				// erase and incement
			strings_count++;	

			if(strings_count % in.K == 0)	// if 7 calls priont
			print_list(L,strings_count);

			p = L.begin();
			}
			print_list(L,strings_count);		// prints one last time

		
        
}

/********************************************************************************
 * void
 * @param list string
 * @param args in
 * function init values
 ********************************************************************************/
void init_vals(list<string> &L, args &in) 
{
	// gets values from input
	cout << "Number of people? " << in.N << endl;
	cout << "Index for elimination? " << in.M << endl;;
	cout << "Index for printing? " << in.K << endl << endl;

	SEQ N;
	// generates the circle
	generate(L.begin(),L.end(),SEQ(N));
	
	
}

/********************************************************************************
 * void
 * @param int list <string> L
 * @param int strings count
 * function prints the list 
 ********************************************************************************/
void print_list(const list<string> &L, const unsigned &strings_count)
{ // see if it is the first call to print
	if(strings_count < 1)
	{
		cout << "Initial group of people\n";
	cout << "-----------------------\n";
	}
	// if over first call to print
	if(strings_count > 1 )
	{
		cout << "\nAfter eliminating " << strings_count << "th person\n";
			cout << "----------------------------\n";
	}

	// loops through the list and prints 12 per line
	for (auto const &i: L) {
		int num_line;
        cout << i << " ";
		num_line++;
		if((num_line)%NO_ITEMS == 0)
        {
            cout << '\n';
        }
    }
	cout << endl;
	
}