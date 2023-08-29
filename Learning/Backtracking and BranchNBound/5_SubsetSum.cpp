/**
gfg.practice - Dp for optimization

class Solution{
public:
    int t[101][10001];
    int solve(int n , int arr[], int sum)
    {
        if(sum ==0)
            return 1;
        if(n == 0)
            return 0;
        if(t[n][sum] != -1)
            return t[n][sum];
        if(arr[n-1]>sum)
            return t[n][sum]  = solve(n-1,arr,sum);
        else{
            return t[n][sum] = solve(n-1,arr,sum-arr[n-1])
                                || solve(n-1 ,arr ,sum);
        }

    }
    bool isSubsetSum(int N, int arr[], int sum){
        // code here
        for(int i=0;i<=100;i++)
        {
            for(int j=0;j<=10000;j++)
            {
                t[i][j] =-1;
            }
        }
        int val = solve(N , arr , sum);
        if(val)
            return true;
        return false;
    }
};
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You";
    return 0;
}
