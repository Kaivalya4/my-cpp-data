/* std::stack
 -> It is a container adapter class and internally it uses std::deque STL container by default
 -> It is LIFO - Last IN First Out Data srtructure
 -> push and pop only from back or rear
---> Some Fuctions -
    -> empty() - boolean function that returns 1 if stack is empty  - O(1) time complexity
    -> size() - returns the size of the stack - O(1) ......
    -> top() - returns a reference to the top mast element of the stack - O(1) .....
    -> push(x) - adds the element'x' at the top of the stack - O(1).....
    -> pop() - Deletes the top most element of the stack - O(1) .....
*/
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void print(stack<int> stk)
{
    while(stk.empty() !=1)
    {
        cout<< stk.top() << " " ;
        stk.pop();     // we cannot iterate over stack and queue hence we are poping to get next element in the stack
    }
}
void print1(stack<int,vector<int>> stk)
{
    while(stk.empty() !=1)
    {
        cout<< stk.top() << " " ;
        stk.pop();     // we cannot iterate over stack and queue hence we are poping to get next element in the stack
    }
}
int main()
{
    std::stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    print(stk);
    cout<<endl;

    //now we will overload our defintition and we will change default internal container deque used by the stack to vector for example
    stack<int , vector<int>> stk1;
    stk1.push(1);
    stk1.push(2);
    print1(stk1);  //although we not see any change but internally there is a change from deque to vector

    return 0;
}
