/**
gfg.practice
-> to solve we must use recursion - very easy : either I can choose(if i choose then i skip adjacent house) or i
    cannot choose(then i can choose adjacent house)
    class Solution
    {
    public:
    static int recursion(int arr[] , int n)
    {
        if(n == 0)
            return arr[0];
        if( n == 1)
            return max(arr[1] , arr[0]);

        int ans1 = arr[n] + recursion(arr , n-2);
        int ans2 =  recursion(arr, n-1);

        return max(ans1 , ans2);
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        return recursion(arr, n-1);
    }
};

->Accepted memosized solution
    class Solution
{
    public:
     int dp[10001] = {-1};
     int recursion(int arr[] , int n)
    {
        if(n == 0)
            return arr[0];
        if(n == 1)
            return max(arr[1] , arr[0]);
        if(dp[n] != -1)
            return dp[n];
        int ans1 = arr[n] + recursion(arr , n-2);
        int ans2 =  recursion(arr, n-1);

        return dp[n] = max(ans1 , ans2);
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        for(int i=0;i<n;i++)
            dp[i] = -1;
        return recursion(arr, n-1);
    }

->in bottom up dp
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int dp[n];
        dp[0] = arr[0];
        dp[1] = max(dp[0] , arr[1]);
        for(int i=2;i<n;i++)
        {
            dp[i] = max(dp[i-2]+arr[i] , dp[i-1]);
        }
        return dp[n-1];
    }
};
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank YOu" ;
    return 0;
}
