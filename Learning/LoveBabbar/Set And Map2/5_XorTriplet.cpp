/*
1.Brute Force using three loops - O(n^3)
2.Xor of two same element is zero -
a^b^c = 0 => a^b^c^b^c = 0^b^c => a = b^c so we need to find only pairs
O(n^2) time and O(n) space
*/
#include<iostream>
#include<unordered_map>

using namespace std;

int solve(int arr[] , int n)
{
    unordered_map<int , int> umap;
    for(int i=0 ;i<n ;i++)
        umap[arr[i]] = 1;
    int counts = 0;
    for(int i=0 ; i<n-1 ; i++)
    {
        for(int j=i+1 ; j<n ; j++)
        {
            int val = (arr[i])^(arr[j]);
            val = val^0;
            if(umap[val] == 1)
                //cout << arr[i] << " " << arr[j] << " " << val << endl;
                counts++;
        }
    }
    return counts/3; //since here we are founding triplet so to remove duplicate we divide by 3 instead of 2
    //which is used in pairs
}

int main()
{
    int arr[] = {1, 3, 5, 10, 14, 15};
    cout << solve(arr ,6);
    return 0;
}
