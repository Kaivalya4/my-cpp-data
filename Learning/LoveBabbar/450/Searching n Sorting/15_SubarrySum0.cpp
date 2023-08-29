/**
gfg.practice
->Brute is to check each and every subarray
->Optimized is to use prefix sum and mapping - O(n) time and space
    if prefix sum at[j] = prefix sum at[i] => things that were added in between i and j cancelled each other
    Also prefix at[k] = prefix at[j] = at[i] = at[l] with l<i<j<k then we need to count
    i-k , j-k , l-k subarrays as well for index k. -----*
 class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        unordered_map<long long , long long> umap;
        long long counts = 0;
        long long sum =0 ;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
            if(sum == 0)  ///i.e. we got solution w.r.t. 0
            {
                counts++;
            }
            ///but what if arr : 0,0,0,.... then for index =2 we need the below if condition which initally store umap[0] =2
            /// whcih later becomes umap[0] =3 with help of last statement of for loop
            if(umap[sum])   /// this is for '*' purpose
            {
                counts += umap[sum];
            }
            umap[sum]++;
        }
        return counts;
    }
};
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You" ;
    return 0;
}
