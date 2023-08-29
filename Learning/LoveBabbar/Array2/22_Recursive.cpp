/*
the idea is to recur for all elements reachable from the source and consider their
minimum cost . The recurrence relation T(n) can be written as:
T(source,dest) = min(T(start,dest)) for all start reachable from source

O(n^n) time - base is n because if arr[i] = 5 then we can take upto 5 step . So if arr[i] = n , hence the answer
*/

#include<iostream>

using namespace std;

int calcJump(int arr[] , int start , int n)
{
    if(start == n-1)
        return 0;
    if(arr[start] == 0 || start >=n)
        return INT_MAX;
    int minjump = INT_MAX;
    for(int i=start+1 ; i<=start+arr[start] ;i++)
    {
        int jump = calcJump(arr,i,n);
        if(jump != INT_MAX)
            minjump = min(minjump , jump+1);
    }
    return minjump; //if value of minjump is not changed then INT_MAX will return depicting that we cant reach
        //at end
}

int minJumps(int arr[] , int n)
{
    if(arr[0] == 0)
        return -1;
    int val = calcJump(arr , 0 , n );
    if(val == INT_MAX) //i.e. not possible
        return -1;
    else
        return val;
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
