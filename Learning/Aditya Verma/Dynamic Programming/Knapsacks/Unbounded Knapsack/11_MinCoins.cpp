///Do leetcode - coin change 1
#include<iostream>

using namespace std;

int minCoins(int coins[] , int n , int val)
{
    int t[n+1][val+1];
    for(int i=0 ;i<n+1 ;i++)
    {
        for(int j=0 ;j<val+1; j++)
        {
            if(j==0)
                t[i][j] = 0;
            if(i==0)
                t[i][j] = INT_MAX-1;
        }
    }
    for(int j=1 ;j<val+1; j++)
    {
        if(j%coins[0] ==0)
            t[1][j] = j/coins[0];
        else
            t[1][j] = INT_MAX-1;
    }
    for(int i=2 ;i<n+1 ;i++)
    {
        for(int j=1 ;j<val+1 ;j++)
        {
            if(coins[i-1]<=j)
            {
                t[i][j] = min(1+t[i][j-coins[i-1]] , t[i-1][j]);
            }
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][val];
}

int main()
{
    int coins[] =  {9, 6, 5, 1};
    int m = sizeof(coins)/sizeof(coins[0]);
    int V = 11;
    cout << "Minimum coins required is "
         << minCoins(coins, m, V);
    return 0;
}
