#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack<int> stk;
    cout<< "we inserted  0 1 2 3 4 in stack ." << endl;
    for(int i=0 ; i<5 ;i++)
        stk.push(i);   // inserting or pushing elements in to the stack

    cout<< "size of the stack is : " <<stk.size() << endl; //size() returns the size of the stack

    cout<< "top element of the stack is : " << stk.top() << endl; // return top element of the stack

    stk.empty() ? cout << "stack is empty ." : cout << "stack is not empty";

    cout<< "elemnt of the stack(to display all elements of the stack we pop elements one by one) : " ;
    while(!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout<< endl <<"After we displayed all elemnts : " ;
    stk.empty() ? cout << "stack is empty ." : cout << "stack is not empty";

    //swap() - swap the elements in one stack to other
    stack<int> stk1 , stk2;
    cout<<"we created stk1 with element 10 11 12 13 14 ";
    cout<<endl <<"we created stk2 with element 20 21 22 23 24 ";
    for(int i=0 ; i<5 ;i++)
        stk1.push(10+i);
    for(int i=0 ; i<5 ;i++)
        stk2.push(20+i);
    stk1.swap(stk2);
    cout<< "After swap elements in the stk1 are : " ;
    while(!stk1.empty())
    {
        cout << stk1.top() << " ";
        stk1.pop();
    }
    cout<<endl;
    cout<< "After swap elements in the stk2 are : " ;
    while(!stk2.empty())
    {
        cout << stk2.top() << " ";
        stk2.pop();
    }

    return 0;
}
