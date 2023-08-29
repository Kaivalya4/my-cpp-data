/*
Method1 - Brute Force - We can iterate over all the pairs of the given array,
and then count the pairs whose sum is equal to K.
O(n^2)
 -> I also tried recursion but it is also time consuming

Method2 - using map , we can count number of occurrences of element
sppose - arr: 1,5,1,.... k = 6 Then umap[k-arr[1]] = umap[1] = 2
    then count += umap[k-arr[i]]

*/

//method2 -
#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
    unordered_map<int , int> umap;
    int arr[20];
    int n , k;
    cin >> n >> k;
    for(int i=0 ; i<n ; i++ ){
        cin >> arr[i];
        umap[arr[i]]++;
    }
    int counts = 0;
    for(int i=0 ;i<n ;i++)
    {
        counts += umap[k - arr[i]];

        //to remove self duplicate suppose umap[22] = 2
        //k = 44 then umap[44 - 22] = 2 in which one element is counting itself
        if(k - arr[i] == arr[i])
        {
            counts--;
        }
    }
    cout << counts/2 ;
    return 0;
}
