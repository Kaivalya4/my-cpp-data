#include<iostream>

using namespace std;

//we could have done this using without l,r
/*
int longestSubarray(int arr[] , int n ,int k)
{
    int ctr = 0 , maxlen = 0;
    for(int i=0; i<n ;i++)
    {
        if(arr[i] >k)
            ctr++;
        else
        {
            maxlen = max(maxlen , ctr);
            ctr = 0;
        }
    }
    return ctr;
}
*/
int longestSubarray(int arr[] , int n , int k)
{
    int l = -1 , r=0 , maxlen = 0;
    while(r<n)
    {
        if(arr[r] > k)
        {
            if(l == -1)
            {
                l=r;
            }
        }
        else
        {
            if(l != -1){
            maxlen = max(maxlen , r-l);
            l=-1;
            }
        }
        r++;
    }
    return maxlen;
}

int main()
{
    int a[] = { 8, 25, 10, 19, 19, 18, 20, 11, 18 };
    int n = sizeof(a) / sizeof(a[0]);
    int k = 13;

    cout << longestSubarray(a, n, k);

    return 0;
}
