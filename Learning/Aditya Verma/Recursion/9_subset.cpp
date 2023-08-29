//given its subset . print all its subset
/*
Here we are generating every subset using recursion. The total number of subsets of a given set of size n = 2^n.

Time Complexity :  O( 2^n)
space complextiy :  O(n) for extra array subset.
*/

#include<iostream>
#include<string>

using namespace std;

void func(string ip , string op)
{
    if(ip.size() == 0)
    {
        cout<< op << endl;
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin());
    func(ip , op1);
    func(ip , op2);
}

void solve(string str)
{
    string ip = str;
    string op = " ";
    func(ip , op); 
}

int main()
{
    string str;
    cin>> str;
    solve(str);
    return 0;
}