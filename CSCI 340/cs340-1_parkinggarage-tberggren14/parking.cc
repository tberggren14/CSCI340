#include "car.h"
#include "garage.h"
#include <stack>
#include <cstring>

//declare function before main
void get_input_vals(const std::string &line, char &xact_type, std::string &license);

int main()
{
    string line;        // declaring needed varis
    char xact_type;
    string license;
    garage G;           // garage OBJECT
    
    // while reading from file
    while(getline(cin,line))
    { 
        get_input_vals(line,xact_type,license);     // calls to function
    
        if(xact_type == 'A')                        // if arrival
        {
            G.arrival(license);
        }

        else if(xact_type == 'D')                   // if departure
        {
            G.departure(license);
        }

        else                                        // if none
        {
            cout << xact_type << " : invalid action!\n" << endl;
            
        }
    }

}

/********************************************************************************
 * void
 * @param string license
 * function adds to garage
 ********************************************************************************/
void garage::arrival(const std::string &license)
{
    int id = next_car_id;           // decalre car object
    car arrival_Car(id, license);
    
    

    if(parking_lot.size() == parking_lot_limit)     // if garage is at limit
    {
        cout << arrival_Car << " has arrived." << endl
         << setw(4) << ' ' << "But the garage is full!\n" << endl;
        
    }

    else                                            // if there is room
    {
        cout << arrival_Car << " has arrived.\n" << endl;
        parking_lot.push_front(arrival_Car);        // push car obj
        next_car_id++;                              // sets next_car_id
       
        
    }

}

/********************************************************************************
 * void
 * @param string license
 * function takes away from garage
 ********************************************************************************/
void garage::departure(const std::string &license)
{
    stack<car> temp;                    // temp stack to store
    bool found = false;                 // find car

    for(auto i:parking_lot)             // loops parking lot
    { 
       
        if(i.get_license() == license)  // gets license
        {
        found = true;
        temp.push(parking_lot.front());     // pushes to temp stack
        temp.push(parking_lot.front());

        // displays
        cout << parking_lot.front() << " has departed,\n" << setw(4) << ' '
        << "car was moved " << parking_lot.front().get_num_moves() << " time in the garage.\n" << endl; 
        parking_lot.pop_front();            // unworking part of code
        temp.push(parking_lot.front());
        parking_lot.front().move(); 
        parking_lot.pop_front();
        temp.pop();

        }
        
        temp.push(parking_lot.front());     // unworking part of code
        parking_lot.front().move();         // trying to get back into deque
        parking_lot.pop_front();
        
    }
   
        

    if(!found)      // if car isnt found
    {
        cout << "\nNo car with license plate " << license << " is in the garage.\n";

    }
    

}

/********************************************************************************
 * void
 * @param const string line
 * @param char xact_type
 * @param string license
 * function parse the line string
 ********************************************************************************/
void get_input_vals(const std::string &line, char &xact_type, std::string &license)
{
    char delimiter = ':';       // delin
    string str;
    
    for(size_t i = 0; i < line.length(); ++i) 
    {
        str = line.substr(0,line.find(delimiter));      // find delimiter
        license = line.substr(line.find(delimiter) + 1);    // find 2nd delimiter
        xact_type = str[0];                                 // copys to xact_type
        license.pop_back();                                 // pops : off
    }
}