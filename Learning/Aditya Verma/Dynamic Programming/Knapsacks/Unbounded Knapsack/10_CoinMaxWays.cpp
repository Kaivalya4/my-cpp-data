///do gfg.practice
#include<iostream>

using namespace std;

int solve(int arr[] , int n , int tar)
{
    int t[n+1][tar+1];
    for(int i=0 ; i<n+1 ; i++)
    {
        for(int j=0 ; j<tar+1 ; j++)
        {
            if(i==0)
                t[i][j] = 0;
            if(j==0)
                t[i][j] = 1;
        }
    }
    for(int i=1 ; i<n+1 ; i++)
    {
        for(int j=1 ; j<tar+1 ; j++)
        {
            if(arr[i-1] <= j)
                t[i][j] = t[i][j-arr[i-1]] + t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][tar];
}
int main()
{
    int arr[] = {1, 2, 3};
    int target = 4;
    cout << solve(arr ,3 , target);
}
