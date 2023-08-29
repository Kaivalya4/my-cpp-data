//O(n^2) time and O(n) space
#include<iostream>

using namespace std;

//we write tabualtion with help of memoisation and recursion
int minJumps(int arr[] , int n)
{
    int t[n];
    for(int i=0;i<n;i++)
    {
        t[i] = INT_MAX;  //just like each level first contains minjump = INT_MAX
    }
    t[0] =0;  //we make it zero because to reach from 0 to 0 we need 0
    //we find min number of jumps required to reach j from 0. hence solution will be at t[n-1]
    for(int i=0;i<n;i++)
    {
        //see loop is running same as recursion . except we have an outer loop instead of recursion with value
        //start . min is used so that we not get outofbound.
        for(int j=i+1;j<=min(i+arr[i],n) ;j++)
        {
            int jump = t[i]; //jump required to move at j form i
            if(jump != INT_MAX)
                t[j] = min(t[j],t[i]+1);
        }
    }
    if(t[n-1] == INT_MAX)
        return -1;
    else
    return t[n-1];
}

int main()
{
    //int arr[] = { 1, 3, 6, 3, 2,3, 6, 8, 9, 5 };
    //int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    //int arr[] = {1, 4, 3, 2, 6, 7};
    //int arr[] = {0,1,1,1,1};
    //int arr[] = {1,0,1,1,1};
    //int arr[] = {2,0,1,1,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of jumps to";
    cout << " reach the end is " << minJumps(arr, n);

    return 0;
}
