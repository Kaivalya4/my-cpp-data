///There is no platform to solve this problem . Hence directly do target sum . It is exactly like that.
//count number of subset with given difference
//See notes for problem statement
/*
int func(int arr[] , int n , int sum)
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

int solve(int arr[] , int n , int diff)
{
    int sum = 0 ;
    for(int i=0 ; i<n ; i++)
    {
        sum +=  arr[i];
    }
    sum = (sum+diff)/2;
    return func(arr , n , sum);
}
*/

#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You" ;
    return 0;
}
