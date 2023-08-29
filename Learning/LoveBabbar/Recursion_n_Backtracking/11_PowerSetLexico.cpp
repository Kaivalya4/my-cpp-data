#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void func(string ip , string op , vector<string> & vec)
{
    if(ip.length() == 0)
    {
        vec.push_back(op);
        return ;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin());
    func(ip , op1 , vec);
    func(ip , op2 , vec);
}

void solve(string str)
{
    vector<string> vec;
    func(str , "" , vec);
    sort(vec.begin() , vec.end());
    for(int i=1 ; i<(int)vec.size() ; i++)
        cout << vec[i] << "  ";
}

int main()
{
    string str;
    getline(cin , str);
    solve(str);
    return 0;
}
