/**
Also do gfg.practice - Perfect Sum Problem

Time Complexity: O(sum*n), where the sum is the ‘target sum’ and ‘n’ is the size of the array.

Auxiliary Space: O(sum*n), as the size of the 2-D array, is sum*n.
*/

//to see how zeros have been handled see leetcode -> target sum
#include<iostream>

using namespace std;

int solve(int arr[] , int n , int sum)
{
    int t[n+1][sum+1];
    for(int i=0 ; i<n+1 ; i++)
    {
        for(int j=0 ; j<sum+1 ; j++)
        {
            if(i == 0)
                t[i][j] =0;
            if(j == 0 )
                t[i][j] = 1;
        }
    }
    for(int i=1 ; i<n+1 ; i++)
    {
        for(int j = 1 ; j<sum+1 ; j++)
        {
            if(arr[i-1] <= j)
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}

int main()
{
    //int arr[] = { 3, 3, 3, 3 };
    //int x = 6;
    //int arr[] = {0,0,0,0,0,0,0,0,1} ;
    //int x = 1;
    int arr[] = {1,0};
    int x = 1;
    cout << solve(arr ,2 , x);
    return 0;
}
