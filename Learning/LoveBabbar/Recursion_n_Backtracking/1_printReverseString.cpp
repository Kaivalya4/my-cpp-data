#include<string>
#include<iostream>

using namespace std;

void  solve(string str)
{
    if(str.size() == 0)
    {
        return;
    }
    char val = str[0];
    str.erase(str.begin());
    solve(str);
    str.push_back(val);
    cout << val;
}

int main()
{
    string str;
    cin>> str;
    solve(str);
    return 0 ;
}