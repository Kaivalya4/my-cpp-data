/*
Also do gfg.practice
Time Complexity: Since the number of Gaps is n-1,
there are total 2^(n-1) patters each having length ranging from n to 2n-1.
Thus overall complexity would be O(n*(2^n)).
*/

#include<iostream>
#include<string>

using namespace std;

void func(string ip , string op)
{
    if(ip.size() == 0)
    {
        cout << op << endl;
        return;
    }
    string op1 = op;
    string op2 = op;
    op1.push_back(ip[0]);
    op2.push_back(' ');
    op2.push_back(ip[0]);
    ip.erase(ip.begin());
    func(ip , op1);
    func(ip , op2);
}
void solve(string str)
{
    string op ;
    op.push_back(str[0]);
    str.erase(str.begin());
    string ip = str;
    func(ip , op);
}
int main()
{
    string str;
    cin >> str;
    solve(str);
    return 0;
}
