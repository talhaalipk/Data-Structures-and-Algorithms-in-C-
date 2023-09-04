/*  REVERSE STACK  */

#include <iostream>
#include <stack>

using namespace std;


void insertAtBottemOfStack(stack <int> &s , int valueToInsert)
{
    //Base Case
    if(s.empty())
    {
        s.push(valueToInsert);
        return ;
    }

    // Removing and storing top value
    int top= s.top() ;
    s.pop();

    //Recursion Call
    insertAtBottemOfStack(s,valueToInsert);

    //insert top value again
    s.push(top);
}

void reverseStack(stack <int> &s)
{
    //Base case
    if(s.empty())
    {
        return  ;
    }

    //// Removing and storing top value
    int top= s.top() ;
    s.pop();

    //resursive Call

    reverseStack(s);

    //inser top at buttom
    insertAtBottemOfStack(s,top);
}

int main()
{
    stack <int> s1;

    //Inserting values
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);


    //Insert 5 at bottem
    reverseStack(s1) ;

    while(!s1.empty())
    {
        cout << s1.top() << endl ;
        s1.pop() ;
    }


}