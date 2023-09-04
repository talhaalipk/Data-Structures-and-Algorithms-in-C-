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

int main()
{
    stack <int> s1;

    //Inserting values
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(5);


    //Insert 5 at bottem
    insertAtBottemOfStack(s1,5) ;

    while(!s1.empty())
    {
        cout << s1.top() << endl ;
        s1.pop() ;
    }


}