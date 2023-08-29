///also do gfg.practice
#include<iostream>
#include<cstring>

using namespace std;

//considering that some constraints are given I have created this matrix
/*
Time Complexity: O(N*W).
As redundant calculations of states are avoided.
Auxiliary Space: O(N*W).
The use of 2D array data structure for storing intermediate states-:
*/
int t[4][51] ;

int solve(int val[] , int wt[] , int W , int n)
{
    if(n==0 || W == 0)
    {
        return 0;
    }
    if(t[n][W] != -1)
        return t[n-1][W];
    if(wt[n-1] <= W)
        return t[n][W] = max(val[n-1] + solve(val , wt , W-wt[n-1] , n-1) , solve(val , wt , W , n-1));
    else
        return t[n][W] = solve(val , wt , W , n-1);
    return t[n][W];
}

int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    for(int i=0 ;i<4 ; i++)
    {
        for(int j=0 ; j<51 ; j++)
        {
            t[i][j] = -1;
        }
    }
    cout << solve(val , wt , W ,3);
    return 0;
}

