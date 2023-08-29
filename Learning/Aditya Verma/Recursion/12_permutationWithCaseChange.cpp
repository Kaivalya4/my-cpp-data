//considering that input contains only small case letters  . Also do leetcode

#include<iostream>
#include<string>

using namespace std;

void func(string ip , string op )
{
    if(ip.size() == 0)
    {
        cout << op << endl;
        return ;
    }
    string op1 = op;
    string op2 = op;
    op1.push_back(ip[0]);
    op2.push_back(toupper(ip[0]));
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
    cin >> str;
    solve(str);
    return 0;
}
