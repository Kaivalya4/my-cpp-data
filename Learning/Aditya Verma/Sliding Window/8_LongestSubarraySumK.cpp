/**
part7 - is just theory
Longest Subarray of the sum K - gfgPractise
->Novice approach will be to check sum of each substring 
->If all elements are positive  then we can use the sliding window
->If negative elements are also present then we can use the prefix sum idea along with map -
	=> Initialize sum = 0 and maxLen = 0.
	=>Create a hash table having (sum, index) tuples.
	=>For i = 0 to n-1, perform the following steps:
			Accumulate arr[i] to sum.
			If sum == k, 
				update maxLen = i+1.
			Check whether sum is present in the hash table or not. 
			If not present, 
				then add it to the hash table as (sum, i) pair.
			Check if (sum-k) is present in the hash table or not. (//concept of prefix sum) 
			If present, 
				then obtain index of (sum-k) from the hash table as index. 
			Now check if maxLen < (i-index), then update maxLen = (i-index).
	=>Return maxLen.
	class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int N, int k) 
    { 
        // Complete the function
        int sum =0;
        int ans = 0;
        unordered_map<int,int> umap;
        for(int i=0;i<N;i++)
        {
            sum += arr[i];
            if(!umap[sum])  //at index 2 and 5 we get cumulative sum = 10 then we consider index 2 to maximize the length of subarray 
                umap[sum] = i+1;
            if(sum == k)      
            {
                ans = i+1;
            }
            else if(umap[sum-k])
            {
                ans = max(ans ,  i+1 - umap[sum-k] );
            }
            
        }
        return ans;
    } 

};
*/
#include<iostream>

using namespace std;

int main()
{
	cout << "Thank YOu";
	return 0;
}
