/**
Counting sort is a sorting technique based on keys between a specific range.To know range we first find max elem
ent in the array.

->Count the number of elements x and store it at the index = x in counts(kind a hashing) . So all
elements left to x are smaller(if they exsist in array) and right to it are bigger
-> do prefix sum . By doing this we will know how many element smaller than x are present in array.
-> While filling output array . we traverse array  from right to left so that stability is maintained.

Worst Case Complexity: O(n+k)
Best Case Complexity: O(n+k)
Average Case Complexity: O(n+k)
n = size of array , k = range of input

Stability : YES
INplace : NO
Comparison Based Algo : NO
Space Complexity : O(max) where max is the maximum element

We can modify count sort for -ve algo.
It is used as a sub routinge in algos like Radix Sort.
*/
#include<iostream>

using namespace std;

int arr[100];
int counts[100];   ///to store count of each element and then to do prefix sum . so if index 4 has 2 value that means 4
///is comming 2 times in array . Then after doing prefix sum - if value at i=4 is 5 then that means 5-2 =3 elements
///smaller than 4 are present
int out[100];

void countsort(int n)
{
    int maxs = 0;
    for(int i=0;i<n;i++){
        counts[arr[i]] ++;
        maxs = max(maxs , arr[i]);
    }
    for(int i=1;i<=maxs;i++)
        counts[i] = counts[i] + counts[i-1];

    for(int i=n-1;i>=0;i--)
    {
        int val = arr[i];
        out[counts[val]-1] = val;
        counts[val]--;
    }
    for(int i=0;i<n;i++)
    {
        arr[i] = out[i];
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    countsort(n);
    for(int i=0;i<n;i++)
        cout <<  arr[i] << " ";
    return 0;
}
