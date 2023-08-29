///also try gfg.practice - generate parenthesis
#include<iostream>
#include<string>

using namespace std;

void func(int open , int close ,  string op)
{
    if(open == 0 && close == 0)
    {
        cout << op << endl;
        return;
    }
    if(open != 0)
    {
        string op1 = op;
        op1.push_back('(');
        func(open - 1 , close  , op1);
    }
    if(close - open != 0)
    {
        string op2 = op;
        op2.push_back(')');
        func(open , close - 1 , op2);
    }
}

void solve(int n)
{
    int open  = n;
    int close = n;
    string op;
    func(open , close , op);
}

int main()
{
    int n;
    cin >> n;
    solve(n);
    return 0;
}
