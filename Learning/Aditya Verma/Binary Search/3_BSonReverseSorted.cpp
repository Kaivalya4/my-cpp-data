///Given reverse sorted array or descending sorted array . search an element in it -
///LS - O(n)
///BS - O(logn)

#include<iostream>

using namespace std;

int binarySearch(int arr[] , int n ,int x)
{
    int start = 0;
    int ends = n-1;
    while(start<=ends)
    {
        int mid = start + (ends - start)/2;
        if(arr[mid] == x)
            return mid;
        else if(arr[mid] > x)
            start = mid+1;
        else
            ends = mid-1;
    }
    return -1;
}

int main()
{
    int arr[] = { 5, 4, 3, 2, 1 };
    int N = sizeof(arr) / sizeof(arr[0]);
    int X = 4;

    int res =  binarySearch(arr, N, X);
    printf(" %d " , res);
    return 0;
}
