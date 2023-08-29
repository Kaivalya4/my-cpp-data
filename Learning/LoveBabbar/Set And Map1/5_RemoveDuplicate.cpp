#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

//we can use string stream here , it make our task easy
void solve(string str)
{
    unordered_map<string , int> umap;
    string word;
    for(int i=0 ; i<str.length() ; i++)
    {
        if(str[i] == '\0' || str[i] == ' ')
        {
            if(umap[word] != 0)
            {
                word = "";
                continue;
            }
            umap[word]++ ;
            cout << word << str[i];
            word = "";
        }
        else
            word.push_back(str[i]);
    }

}
int main()
{
    string str;
    getline(cin , str);
    solve(str);
    return 0;
}
