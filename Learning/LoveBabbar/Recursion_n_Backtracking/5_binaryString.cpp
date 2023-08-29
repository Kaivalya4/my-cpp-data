//print all binary string without consequtive string

#include<iostream>
#include<string>

using namespace std;

void func(string op , int n , int k)
{
    if(n == 0)
    {
        cout << op << endl;
        return; 
    }
    if(op[k-1] == '0')
    {
        string op1 = op;
        string op2 = op;
        op1.push_back('1');
        op2.push_back('0');
        func(op1 , n-1 , k+1);
        func(op2 , n-1 , k+1);
    }
    else{
        string op1 = op;
        op1.push_back('0');
        func(op1 , n-1 , k+1);
    }
}

void solve(int n)
{
    string op1 = "1";
    string op2 = "0";
    n--;
    int k = (int)op1.size();
    func(op1 , n , k);
    func(op2 , n , k);
}

int main()
{
    int n;
    cin >> n;
    solve(n);
    return 0;
}