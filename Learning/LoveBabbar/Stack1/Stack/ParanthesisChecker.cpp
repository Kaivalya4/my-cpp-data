/**
gfg.practice
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> s;
        for(int i=0;i<x.length();i++)
        {
            if(x[i] == '{' || x[i] == '[' || x[i] == '(')
            {
                s.push(x[i]);
            }
            else{
                if(s.empty())
                {
                    return false;
                }
                char c= s.top();
                if(c == '[' && x[i] != ']')
                {
                    return false;
                }
                if(c == '{' && x[i] != '}')
                {
                    return false;
                }
                if(c == '(' && x[i] != ')')
                {
                    return false;
                }
                s.pop();
            }
        }
        if(!s.empty())
            return false;
        return true;
    }

*/
#include<iostream>

using namespace std;

int main()
{
    cout <<"Thank You";
    return 0;
}

