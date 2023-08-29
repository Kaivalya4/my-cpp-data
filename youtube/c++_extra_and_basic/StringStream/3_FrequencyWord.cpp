#include<iostream>
#include<sstream>
#include<string>
#include<unordered_map>

using namespace std;

void solve(string str)
{
    stringstream sso;
    sso << str;
    string word;
    unordered_map<string , int> umap;
    while(sso >> word)
    {
        umap[word]++;
    }
    for(pair<string , int> i:umap)
    {
        cout << i.first << " -> " << i.second << endl;
    }
    return;
}
int main()
{
    string str;
    getline(cin , str);
    solve(str);
    return 0;
}
