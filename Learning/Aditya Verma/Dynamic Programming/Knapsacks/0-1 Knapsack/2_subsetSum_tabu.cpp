///also solve gfg.practice
#include<iostream>

using namespace std;

bool t[7][10];

bool solve(int arr[] , int sum , int n)
{
    for(int i=0 ; i<n+1 ; i++)
    {
        for(int j=0 ; j<sum+1 ; j++)
        {
            if(i==0)
                t[i][j] = false;
            if(j == 0)
                t[i][j] = true;
        }
    }
    for(int i=1; i<n+1 ; i++)
    {
        for(int j=1 ; j<sum+1 ; j++)
        {
            if(arr[i-1] <=j)
            {
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}

int main()
{
    int sets[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    cout << solve(sets , sum , 6);
    return 0;
}
