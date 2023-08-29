#include<iostream>
#include<string>

using namespace std;

void func(string ip , string op)
{
    if(ip.length() == 0)
    {
        cout << op << endl;
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(' ');
    op2.push_back(ip[0]);
    op1.push_back(ip[0]);
    ip.erase(ip.begin());
    func(ip , op1);
    func(ip , op2);
}

void solve(string str)
{
    string op ;
    op.push_back(str[0]);
    str.erase(str.begin() );
    func(str , op);
}

int main()
{
    string str;
    cin >> str;
    solve(str);
    return 0;
}