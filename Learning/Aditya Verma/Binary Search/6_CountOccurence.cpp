///Given a sorted array arr[] and a number x, write a function that counts the occurrences of x in arr[]
///LS - O(n) time

#include<iostream>

using namespace std;

int firsts(int arr[] , int n , int x)
{
    int start = 0;
    int ends = n-1;
    int res = -1;
    while(start <=ends)
    {
        int mid = start + (ends - start)/2;
        if(arr[mid] == x)
        {
            res = mid;
            ends = mid-1;
        }
        else if(arr[mid] > x)
        {
            ends = mid-1;
        }
        else
            start = mid+1;
    }
    return res;
}

int lasts(int arr[] , int start ,  int ends , int x , int res)
{
    if(start <=ends)
    {
        int mid = start +(ends - start)/2;
        if(arr[mid] == x)
            return lasts(arr ,mid+1 , ends , x , mid);
        else if(arr[mid] > x)
            return lasts(arr ,start , mid-1,x , res);
        else
            return lasts(arr , mid+1 , ends , x , res);
    }
    return res;
}
int countOccurences(int arr[] , int n , int x)
{
    int first = firsts(arr, n,x);
    int last = lasts(arr,0,n,x,-1);
    if(first == -1 || last == -1)
        return -1;
    return last - first + 1;
}

int main()
{
    int arr[] = {1, 1, 2, 2, 2, 2, 3};
    //int x = 3;
    //int x = 2;
    //int x = 1;
    int x = 4;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << countOccurences(arr, n, x);
    return 0;
}
