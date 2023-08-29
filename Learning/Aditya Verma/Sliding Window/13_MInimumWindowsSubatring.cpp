/**
Minimum Window Substring - leetcode
->optimized using variable size sliding window
class Solution {
public:
    string minWindow(string s, string t) {
        string str;
        int ans = INT_MAX;
        unordered_map<char , int> umap;
        for(int i=0;i<t.length();i++)
        {
            umap[t[i]] ++;
        }
        int counts = umap.size();
        int i=0 , j =0;
        pair<int ,int> p;
        while(j<s.length())
        {
            umap[s[j]]--;
            if(umap[s[j]] == 0)
                counts--;
            if(counts == 0)
            {
                while(counts == 0)
                {
                    if(j-i+1 < ans)
                    {
                        p.first = i ;
                        p.second  = j;
                        ans = j-i+1;
                    }
                    umap[s[i]]++;
                    if(umap[s[i]] == 1)
                        counts++;
                    i++;
                }
            }
            j++;
        }
        if(ans != INT_MAX)
            for(int i = p.first ; i<=p.second ;i++)
                str.push_back(s[i]);
        return str;
    }
};
*/
#include<iostream>

using namespace std;

int main()
{
	cout << "Thank You";
	return 0;
}