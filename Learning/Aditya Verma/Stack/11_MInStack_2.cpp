/**
Get minimum element in stack - gfg.practice
O(1) time and O(1) space solution -
class Solution{
    int minEle;
    stack<int> s;
    public:

       ///returns min element from stack
       int getMin(){
           if(s.empty())
                return -1;
            return minEle;
       }

       ///returns poped element from stack
       int pop(){
           if(s.empty())
            return -1;
            int val = s.top();
            if(val<minEle){
                val = minEle;
                minEle = 2*minEle - s.top();

            }
            s.pop();
            return val;
       }

       ///push element x into the stack
       void push(int x){
           if(s.empty())
           {
               s.push(x);
               minEle = x;
           }
           else{
                if(x<minEle)
                {
                    s.push(2*x - minEle);
                    minEle =x;

                }
                else
                    s.push(x);
           }

       }
};
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You";
    return 0;
}
