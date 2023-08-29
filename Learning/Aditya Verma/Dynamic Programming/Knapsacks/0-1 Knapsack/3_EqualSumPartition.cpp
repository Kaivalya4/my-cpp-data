/**
Also do gfg.practice - Partition Equal Subset Sum

Time Complexity: O(sum*n)
Auxiliary Space: O(sum*n)

Please note that this solution will not be feasible for arrays with big sum.
*/


#include<iostream>

using namespace std;

bool func(int arr[] , int sum , int n)
{
    int t[n+1][sum+1];
    for(int i=0 ; i<n+1 ; i++)
    {
        for(int j=0 ; j<sum+1 ; j++)
        {
            if(i == 0)
                t[i][j] = false;
            if(j == 0)
                t[i][j] = true;
        }
    }
    for(int i=1; i<n+1 ; i++)
    {
        for(int j=1; j<sum+1 ; j++)
        {
            if(arr[i-1] <=j)
            {
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j] ;
            }
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}

bool solve(int arr[] , int n)
{
    int sum=0;
    for(int i=0 ; i<n ;i++)
        sum = sum + arr[i];
    if(sum %2 == 0)
        return func(arr , sum/2 , n);
    else
        return false;
}

int main()
{
    int arr[] = { 3, 1, 5, 9, 12 };
    cout << solve(arr , 5);
    return 0;
}
