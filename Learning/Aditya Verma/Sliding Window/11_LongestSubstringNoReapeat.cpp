/**
Longest substring with no repeating charcaters - leetcode
->brute force will be to check every substring
->Optimal solution is to use variable size sliding window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char , int> umap;
        int i=0 , j=0;
        while(j<s.length())
        {
            umap[s[j]]++;
            if(umap.size() == j-i+1)
            {
                ans = max(ans , j-i+1);
            }
            if(umap.size() < j-i+1)
            {
                while(umap.size() < j-i+1)
                {
                    umap[s[i]]--;
                    if(umap[s[i]] == 0)
                        umap.erase(s[i]);
                    i++;
                }
            }

            cout << i <<  " " << j << "->" << ans << endl;
                        j++;
        }
        return ans;
    }
};
*/
#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
	cout << "Thank YOu" ;
	return 0;
}