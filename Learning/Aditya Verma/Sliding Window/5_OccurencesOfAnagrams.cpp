/**
Count Occurences of Anagrams - gfgPractise
Optimized -
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int k = pat.size();
	    unordered_map<char , int> umap1;
	    unordered_map<char, bool> umap2;
	    for(auto i:pat)
	    {
	        umap2[i] = true;
	        umap1[i] ++;
	    }
	    int counts = umap1.size();
	    int i=0 , j=0;
	    int n = txt.size();
	    int ans = 0;
	    while(j<txt.size())
	    {
	        umap1[txt[j]]--;
	        if(umap1[txt[j]] ==0)
	            counts--;
	        if(j-i+1 == k)
	        {
	            if(counts == 0)
	            {
	                ans++;
	            }
	            if(umap2[txt[i]])
	            {
	                umap1[txt[i]]++;
	                if(umap1[txt[i]] == 1)
	                    counts++;
	            }

	            i++;
	        }
	        j++;
	    }
	    return ans;
	}

};
*/
#include<iostream>

using namespace std;

int main()
{
    cout <<"Thank YOU" << endl;
    return 0;
}
