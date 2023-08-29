/**
Given an array of n integers, find the sum of xor of all pairs of numbers in the array.

->Brute force will take O(n^2) time
->Optimized using bit manipulation
*/
#include<iostream>

using namespace std;

int bits[31];

int main()
{
    int n , arr[20];
    cin >> n;
    for(int i=0;i<n; i++)
        cin >> arr[i];
    for(int i=0;i<n;i++)
    {
        int val = arr[i];
        int ctr =0;
        while(val>0)
        {
            bits[ctr++] += val & 1;
            val = val >> 1;
        }
    }
    int res = 0;
    for(int i=0;i<31; i++)
    {
        int x = bits[i];
        int y = n - x;
        int numofOne = x*y;
        res += (numofOne << i);
    }
    cout << res << endl;
    return 0;
}
