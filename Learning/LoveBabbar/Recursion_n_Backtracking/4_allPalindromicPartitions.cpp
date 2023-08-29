#include<iostream>
#include<string>
#include<vector>

using namespace std;

void findsubset(string ip , string op)
{
    if(ip.size() == 0 && op.size() != 0)
    {
        if(check(op))
        {
            cout << op << endl;
        }
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin());
    solve(ip , op1);
    solve(ip , op2);
}

void subset(string str)
{
    string op = "";
    findSubset(str , op);
}

int main()
{
    string str;
    cin >> str;
    subset(str);
    return 0;
}