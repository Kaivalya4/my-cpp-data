///clockwise rotation - right rotation . pick element from last and shift starting element to right
///Also do leetcode - find minimum in rotated sorted array
#include<iostream>

/*
6
15 18 2 3 6 12
*/
using namespace std;

int arr[100];

int solve(int n)
{
    int high = n-1;  //this is going to remain fixed
    int start = 0;
    int ends = n-1;
    while(start<=ends)
    {
        if(start == ends)
            return start;
        int mid = start +(ends-start)/2;
        if(mid>start && arr[mid] < arr[mid-1])
            return mid;
        else if(mid < ends && arr[mid] > arr[mid+1])
            return mid+1;
        else if(arr[mid] < arr[high])
            ends = mid -1;
        else if(arr[mid] > arr[high])
            start = mid+1;
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cout << solve(n);
    return 0;
}
