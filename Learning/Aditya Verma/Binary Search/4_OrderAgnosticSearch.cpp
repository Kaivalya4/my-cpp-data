///Given a sorted array (order of sorting not known) . find position of x.

#include<iostream>

using namespace std;

int BinarySearch1(int arr[] , int n ,int x)
{
    int start =0;
    int ends = n-1;
    while(start <=ends)
    {
        int mid = (start+ends)/2;
        if(arr[mid] == x)
            return mid;
        else if(arr[mid] > x)
            ends = mid-1;
        else
            start = mid+1;
    }
    return -1;
}

int BinarySearch2(int arr[] , int start , int ends , int x)
{
    while(start<=ends)
    {
        int mid = start + (ends - start)/2;
        if(arr[mid] == x)
            return mid;
        else if(arr[mid] > x)
            BinarySearch2(arr , mid+1 , ends , x);
        else
            BinarySearch2(arr , start , mid-1 , x);
    }
    return -1;
}

int BS(int arr[] , int n , int x)
{
    if(arr[0] < arr[1])
        return BinarySearch1(arr , n, x);
    else
        return BinarySearch2(arr , 0,n-1 , x);
}

int main()
{
    int arr[100];
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int x;
    cin >> x;
    cout << BS(arr , n , x);
    return 0;
}
