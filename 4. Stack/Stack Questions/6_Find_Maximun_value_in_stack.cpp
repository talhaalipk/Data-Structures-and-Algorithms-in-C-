/*  FIND MINIMUM VALUE STACK  */

#include <iostream>
#include <limits.h> // for int max
#include <stack>

using namespace std;


int findMinimun(stack <int> &s)
{
    //Base case
    if(s.empty())
    {
        return  INT_MIN;
    }

    //// Removing and storing top value
    int top= s.top() ;
    s.pop();

    //resursive Call

    int ret = findMinimun(s);

    
    int max ;
    // finding max
    if(ret > top)
    {
        max = ret ;
    }
    else
    {
        max = top ;
    }

    s.push(top);

    return max;
}

int main()
{
    stack <int> s1;

    //Inserting values
    s1.push(8);
    s1.push(1);
    s1.push(9);
    s1.push(-55);


    //Insert 5 at bottem
    cout << " Maximum Value  : " << findMinimun(s1) << endl ;

    while(!s1.empty())
    {
        cout << s1.top() << endl ;
        s1.pop() ;
    }


}