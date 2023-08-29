/**
Longest Substring with K unique characters - practise gfg
->Novice approach will be to check every substring 
->Sliding window with mapping
class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        unordered_map<char , int> umap;
        int ans =-1;
        int i=0  ,j =0;
        while(j< (s.length()) )
        {
            umap[s[j]] ++;
            int sizes = umap.size();
            if(sizes == k)
            {
                ans = max(ans , j-i+1);
            }
            else if(sizes > k)
            {
                while(sizes > k)
                {
                    umap[s[i]] --;
                    if(umap[s[i]] == 0)
                        umap.erase(s[i]);
                    i++;
                    sizes--;
                }
            }
            j++;
        }
        return ans;
    
    }
};
*/
#include<bits\stdc++.h>

using namespace std;

int main()
{
	cout << "Thank You";
	return 0;
}
