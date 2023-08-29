#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int counts = 0;
void solve(string s)
{
    stringstream sso;
    sso << s;
    string word;
    while(sso >> word)
        counts ++;
    return ;
}

int main()
{
    string s;
    getline(cin , s);
    solve(s);
    cout << "number of words : " << counts;
    return 0;
}
