/*
two methods I able to come up -
1.Sort and find
2.map and find
*/

//method1
#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

int solve(int arr[] , int k , int n)
{
    sort(arr , arr+n);
    int counts = 0;
    for(int i=0 ; i<n-1 ; i++)
    {
        int diff = arr[i+1] - arr[i] - 1;
        int val = arr[i];
        while(diff != 0)
        {
            counts++;
            val++;
            if(counts == k){
                return val;
            }
            diff--;
        }
    }
    return -1;
}

//method2
int hashsolve(int arr[] , int k , int n)
{
    unordered_map<int , int> umap;
    int mins = 99999;
    int maxs = -99999;
    for(int i=0 ; i<n ; i++)
    {
        umap[arr[i]] = 1;
        if(arr[i] > maxs)
            maxs  = arr[i];
        if(arr[i] < mins)
            mins = arr[i];
    }
    int counts = 0;
    for(int i=mins ; i<=maxs ; i++)
    {
        if(umap[i] == 0)
            counts++;
        if(counts == k)
            return i;
    }
    return -1;

}
int main()
{
    int arr[] = {2, 4, 10, 7}, k = 5;
    cout << k <<"th missing element possible is(if) : " << solve(arr , k , 4);
    cout << endl;

    int arr1[] = { 2, 10, 9, 4 };
    int k1 = 5;
    cout << k1 <<"th missing element possible is(if) : " << hashsolve(arr1 , k1 , 4);
    return 0;
}
