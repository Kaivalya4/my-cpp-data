/*
Given an array arr[] of integers, find out the maximum difference between any two elements such that
larger element appears after the smaller number.

->Brute Force - Using two loops find pairs with maximum difference . Obviously the most positive difference
gives the answer . Difference will be like = later - prev

->If we keep track of minimum element of array so far then we can get the answer(if we get any min element
at i then we need to find large maximum element after i).Basically we track maximum difference and minimum
element so far.if we get a maximum element before a minimum then that will not affect my answer . So track
minimum element and compare the maximum difference so far and difference of min element and element after
min element
This can be done in similar way from right , here we just store maxsofar right so that we can find Diff between
ith index and maxsofar(at jth index) . here i<j.

-> Prefix array and Kadanes Algorithm -
Consider a,b,c,d,e,f,g,h,i . Suppose h - d = maximum differnce(positive as large element comes after smaller)
We build array like :  b-a,c-b,d-c,e-d,f-e,g-f,h-g,i-h
Then Maximum sum subarray will give : h-g+g-f+f-e+e-d = h -d  = maximum difference = max sum subarray of new array

*/

#include<iostream>

using namespace std;

//Brute Force
//O(n^2) time and O(1) space
int maxDiff1(int arr[] , int n)
{
    int maxDiff = 0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            maxDiff = max(maxDiff , arr[j] - arr[i]);
        }
    }
    return maxDiff;
}

//2nd Method - O(n) time and O(1) space
int maxDiff2(int arr[] , int n)
{
    //assuming input will contain atleast 2 element
    int maxdiff = arr[1] - arr[0];
    int mins = arr[0];
    for(int i=1;i<n;i++)
    {
        maxdiff = max(maxdiff , arr[i] - mins);
        mins = min(mins ,arr[i]);
    }
    return maxdiff;
}

//method3 - O(n) time and O(n) space
int maxDiff3(int arr[] , int n)
{
    int arr1[n];
    for(int i=1;i<n;i++)
        arr1[i-1] = arr[i] - arr[i-1];
    int maxi =arr1[0] , sum =0;
    for(int i=0;i<n-1;i++)
    {
        sum += arr1[i];
        maxi = max(maxi ,sum);
        if(sum <0)
            sum =0;
    }
    return maxi;
}

int main()
{
    int arr[] = {1, 2, 90, 10, 110};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function calling
    cout << "Maximum difference is " << maxDiff1(arr, n) << endl;
    cout << "Maximum difference is " << maxDiff2(arr, n) << endl;
    cout << "Maximum difference is " << maxDiff3(arr, n);
    return 0;
}
