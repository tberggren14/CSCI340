/*	Trevor Berggren
*	z1906236
*	CSCI 340 
*	I certify that this is my own work and where appropriate an extension 
*	of the starter code provided for the assignment.
*/

#include "stack.h"

/********************************************************************************
 * bool
 * function returns true if both queues are empty 
 ********************************************************************************/
bool Stack::empty() const
{
    if(q1.size() == 0 && q2.size() == 0)
        return true;        // returns true if both are empty

    else
        return false;
}

/********************************************************************************
 * int
 * function returns the size
 ********************************************************************************/
int Stack::size() const
{   // if q1 is empty returns q2 size 
    if(q1.size() == 0)
        return q2.size();

    else            // returns q1 if q1 is not empty
    return q1.size();
  
}

/********************************************************************************
 * int
 * function returns the front of the queue
 ********************************************************************************/
int Stack::top()
{
    if(!q1.empty())     // returns the back of q1 if not empty
        return q1.back();

    else                // returns the back of q2 if not empty
        return q2.back();
    
   
}

/********************************************************************************
 * void
 * @param int val
 * function pushes a value on the queue 
 ********************************************************************************/
void Stack::push(const int &val)
{
     if(q1.empty())
    {
        q2.push(val);
    }
    else
    {
        q1.push(val);
    }


}

/********************************************************************************
 * void
 * function pops the queue
 ********************************************************************************/
void Stack::pop()
{

    if(!q1.empty())
    {
        while(q1.size() != 1)           // while there is more than 1 in the queue
        {
            q2.push(q1.front());        // pushes front of q1 to q2 then pops off all elements
            q1.pop();
        }
        
        q1.pop();
    }

    else
    {
        while(q2.size() != 1)            // while there is more than 1 in the queue
        {
            q1.push(q2.front());        // pushes front of q1 to q2 then pops off all elements
            q2.pop();
        }
        q2.pop();
    }
}


