#include<iostream>
#include<sstream>
#include<string>
#include<unordered_map>
#include<sstream>

using namespace std;


void solve(string str)
{
    unordered_map<string ,int> umap;
    string s;
    for(int i=0 ; i<str.length() ; i++)
    {
        if(isdigit(str[i]))
        {
            s.push_back(str[i]);
        }
        if(str[i] == '-')
            s.clear();
        if(s.length() == 4)
        {
            umap[s] = 1;
            s.clear();
        }
    }
    int counts = 0;
    for(auto i:umap)
        counts++;
    cout << counts << endl;
    return;
}

int main()
{
    string str;
    getline(cin , str);
    solve(str);
    return 0;
}
