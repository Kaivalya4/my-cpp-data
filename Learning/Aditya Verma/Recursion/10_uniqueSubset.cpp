//same as before  but print unique subset . Also do gfg.practice

//time = O(n.2^n)

#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

void func(string ip , string op , unordered_map<string , int > & umap)
{
    if(ip.size() == 0)
    {
        umap[op] = 1;
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin());
    func(ip , op1 , umap);
    func(ip , op2 , umap);
}

void solve(string str)
{
    string ip = str;
    string op = " ";
    unordered_map<string  , int> umap;
    func(ip , op , umap);
    for(auto i:umap)
        cout << i.first << endl;
}

int main()
{
    string str;
    cin >> str;
    solve(str);
    return 0;
}
