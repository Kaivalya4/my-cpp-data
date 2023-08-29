/**
Get Minimum element in stack - gfg.practice
O(n) space:
class Solution{
    int minEle;
    stack<int> s;
    stack<int> min;
    public:

       int getMin(){
           if(min.empty())
                return -1;
            return min.top();
       }

       int pop(){
           if(s.empty())
            return -1;
           int val = s.top();
           s.pop();
           if(val == min.top())
                min.pop();
            return val;

       }

       //push element x into the stack
       void push(int x){
           if(s.empty())
           {
               s.push(x);
               min.push(x);
           }
           else{
               s.push(x);
               if(x<=min.top())
               {
                   min.push(x);
               }
           }

       }
};
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank YOu";
    return 0;
}
