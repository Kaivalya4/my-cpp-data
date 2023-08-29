///Also do gfg practice
#include<iostream>
#include<string>

using namespace std;

void func(int one , int zero , int n , string op)
{
    if(n == 0)
    {
        cout << op << endl;
        return ;
    }

    string op1 = op;
    op1.push_back('1');
    func(one +1 , zero , n-1 , op1);
    if(one > zero)
    {
        string op2 = op;
        op2.push_back('0');
        func(one , zero + 1 , n-1 , op2);
    }
}

void solve(int n)
{
    string op = "";
    func(0 ,0 , n , op );
}

int main()
{
    int n;
    cin >> n;
    solve(n);
    return 0;
}
