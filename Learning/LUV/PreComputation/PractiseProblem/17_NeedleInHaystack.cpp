#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string pattern ,text;
        cin >> pattern;
        cin >> text;
        unordered_map<char ,int> umap;
        unordered_set<char> sets;
        string ans = "NO";
        for(int i=0 ;i<pattern.length() ;i++)
            umap[pattern[i]] = 1;
        string str;
        for(int i=0 ;i<text.length() ;i++)
        {
            for(int j=i ; j<pattern.length() + i; j++)
            {
                if(umap[text[j]] == 1)
                    sets.insert(text[j]);
                else
                    break;
            }
            if(sets.size() == pattern.length())
            {
                ans = "YES";
                break;
            }
        }
        cout << ans<< endl;
    }
}
