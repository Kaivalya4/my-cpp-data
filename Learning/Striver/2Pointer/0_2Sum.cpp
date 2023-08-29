/*
Given a sorted array A (sorted in ascending order), having N integers,
find if there exists any pair of elements (A[i], A[j]) such that their sum is equal to X.

-Brute force = check each pair . O(n^2) time
-Mappint = O(n) time and O(n) space
-Efficient = sort it and use 2 pointer. O(n) time(if sorted array is given otherwise nlogn )and O(1) space
*/
#include<iostream>
#include<algorithm>

using namespace std;

bool isPairSum(int arr[] , int n , int val)
{
    int i=0  , j =n-1;
    while(i<j)
    {
        if(arr[i] + arr[j] == val)
            return true;
        else if(arr[i] + arr[j] > val)
            j--;
        else
            i++;
    }
    return false;
}

int main()
{
    int arr[] = { 3, 5, 9, 2, 8, 10, 11 };
    int val = 17;
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr + arrSize); // Sort the array
    // Function call
    cout << isPairSum(arr, arrSize, val);
    return 0;
}
