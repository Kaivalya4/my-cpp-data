#include<iostream>

using namespace std;

int solve(int wt[] , int val[] , int W , int n)
{
    int t[n+1][W+1];
    for(int i=0 ; i<n+1; i++)
    {
        for(int j=0 ; j<W+1 ; j++)
        {
            if(i==0)
                t[i][j] = 0;
            if(j==0)
                t[i][j] = 0;
        }
    }
    for(int i=1; i<n+1 ; i++)
    {
        for(int j=1 ; j<W+1 ; j++)
        {
            if(wt[i-1]<=j)
                t[i][j] = max(val[i-1] + t[i][j-wt[i-1]] , t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][W];
}

int main()
{
    int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};

    //int wt[] = {2, 3, 4, 5, 6};
    //int val[] = {2, 4, 6, 8, 9};
    //int W = 13;
    cout << solve(wt , val , W , 3);
    return 0;
}
