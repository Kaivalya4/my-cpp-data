//recurively reverse the stack
/*
Time Complexity
O(N^2) where n is the number of elements in the stack.
Because when we push the element in the stack we may end up removing all the elements which are currently
 present in the stack and then insert it. This case occurs if the input is in decreasing order.

Space Complexity
O(N) because we used stack space for n elements. 
While removing elements to place our current element.
We had to store the removed elements, which gives us a linear space complexity.
*/

#include<iostream>
#include<stack>

using namespace std;

void insert(stack<int> &s , int val)
{
    if(s.size() == 0 )
    {
        s.push(val);
        return;
    }
    int temp = s.top();
    s.pop();
    insert(s , val);
    s.push(temp);
}

void reverse(stack<int> &s)
{
    if(s.size() == 1)
    {
        return ;
    }
    int val = s.top();
    s.pop();
    reverse(s);
    insert(s , val);
}

int main(int argc, char const *argv[])
{
    stack<int> s;
    s.push(7);
    s.push(1);
    s.push(5);
    s.push(2);
    s.push(6);
    
    //print - 6 2 5 1 7 in lifo manner
    
    reverse(s);

    int len  = s.size();  //as after each pop size of stack will change and hence we will get incomplete
        //stack . thats why we created len variable
    for(int i=0; i<len ; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }
    
    return 0;
}
