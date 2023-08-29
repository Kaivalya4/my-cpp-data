#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<bits/stdc++.h>

/**
0 15 21 40 16
10 0 18 35 14
6 30 0 12 8
16 42 7 0 20
11 23 33 50 0

answer is 76
*/

using namespace std;

int dp[20][1<<20-1];

int cost[20][20];

int solve(int from , int sets , int &total)
{
    ///if unvisited set becomes zero => all are visited.
    if(sets == 0)
        return cost[from][1];

    if(dp[from][sets] != -1)
        return dp[from][sets];

    int ans = INT_MAX;
    for(int to=0;to<total;to++){
        if(sets & (1<<to)){
            ans = min(ans , cost[from][to] + solve(to , sets ^ (1<<to) , total));
        }
    }

    return dp[from][sets] = ans;
}

int main()
{
    int n;
    cin >>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> cost[i][j] ;
        }
    }
    memset(dp,-1,sizeof(dp));
    cout << solve(0 , (1<<n) -1 , n); ///(starting node , unvisited set , total)
}
