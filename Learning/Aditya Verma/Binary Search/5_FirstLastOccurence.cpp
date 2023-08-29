///given sorted array with repeated elements. Find position of first and last occurence of x
///LS will take O(n)

#include<iostream>

using namespace std;

int first(int arr[] , int x , int n)
{
    int start = 0;
    int ends = n-1;
    int res = -1;
    while(start<=ends)
    {
        int mid = start + (ends-start)/2;
        if(arr[mid] ==x ){
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

int last(int arr[] , int start , int ends , int x , int res)
{
    if(start<=ends)
    {
        int mid = start+(ends - start)/2;
        if(arr[mid] == x)
        {
            return last(arr , mid+1 , ends , x , mid);
        }
        else if(arr[mid] >x)
            return last(arr , start , mid-1 , x , res);
        else
            return last(arr , mid+1 , ends , x , res);
    }
    return res;
}

int main()
{
    int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
    int n = sizeof(arr) / sizeof(int);

    int x = 2;
    printf("First Occurrence = %d\t",
           first(arr,  x, n));
    printf("\nLast Occurrence = %d\n",
           last(arr, 0, n - 1, x , -1));
    return 0;
}
