///also do gfg.practice - Minimum sum partition
/**
my approach : do knapsack on (sum of all elements)/2 .
*/
#include<iostream>
#include<vector>

using namespace std;

int solve(int arr[] , int n)
{
    int sum = 0;
    for(int i=0 ; i<n ; i++)
        sum = sum + arr[i];
    bool t[n+1][sum+1];
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
                t[i][j] = (t[i-1][j-arr[i-1]]) || (t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }
    vector<int> vec;
    for(int i = 0 ; i<=sum/2 ; i++)
    {
        if(t[n][i] == true)
        vec.push_back(i);
    }
    int mins = INT_MAX;
    for(int i=0 ; i < vec.size() ; i++)
    {
        mins = min(mins , sum -2*vec[i]);
    }
    return mins;
}

int main()
{
    int arr[] = {3, 1, 4, 2, 2, 1};
    cout << solve(arr , 6);
    return 0;
}
