///also do gfg.practice
#include<iostream>

using namespace std;

int t[4][51];

int solve(int val[] , int wt[] , int W , int n)
{
    for(int i=0 ; i<=n ; i++)
    {
        for(int j=0 ; j<=W ; j++)
        {
            if(i==0 || j==0)
            {
                t[i][j] =0;
            }
        }
    }
    for(int i=1; i<=n ; i++)
    {
        for(int j=1; j<=W ; j++)
        {
            if(wt[i-1] <= j)
                t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]] , t[i-1][j]);
            else if(wt[i-1] > j)
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][W];
}

int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    cout << solve(val , wt , W , 3);
    return 0;
}
