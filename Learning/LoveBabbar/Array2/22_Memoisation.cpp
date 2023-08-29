#include<bits/stdc++.h>
//time = ? , space = O(n)

using namespace std;

int t[15]; //only start is changing and it can vary 0 ,....n-1 i.e. total n

int calcJump(int arr[] , int start  ,int n)
{
    if(start == n-1)
        return 0;
    if(start >= n || arr[start] ==0)
        return INT_MAX;
    if(t[start] != -1)
        return t[start];
    int minjump = INT_MAX; //in each level we make it maximum . if arr[start] =5 , then which  of next 5 steps
        //will give us the min answer
    for(int i=start+1;i<=start+arr[start];i++)
    {
        int jump = calcJump(arr,i,n);
        if(jump != INT_MAX)
            minjump = min(minjump , jump+1);
    }
    return t[start] = minjump;
}

int minJumps(int arr[] , int n)
{
    if(arr[0] == 0)
        return -1;
    memset(t , -1 , (sizeof(int))*n);
    int val =  calcJump(arr, 0 , n );
    if(val == INT_MAX)
        return -1;
    else
        return val;
}

int main()
{
    int arr[] = { 1, 3, 6, 3, 2,3, 6, 8, 9, 5 };
    //int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    //int arr[] = {1, 4, 3, 2, 6, 7};
    //int arr[] = {0,1,1,1,1};
    //int arr[] = {1,0,1,1,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of jumps to";
    cout << " reach the end is " << minJumps(arr, n);
    return 0;
}
