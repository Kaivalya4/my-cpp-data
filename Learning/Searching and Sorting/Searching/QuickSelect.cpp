/**
QuickSort is a selection algorithm to find the kth smallest element in an
unsorted list. it is closely related to QuickSort algorithm. Just
Like Quicksort - good in average case but poor in worst case.

Approach -
->choosing one element as pivot and partitioning the data in two based on the pivot.
->Instead of recursing both sides , quickselect only recurs into one side with its searching element.
  Since we know elements preceding pivot are smaller than pivot and elements following pivot are greater
  than pivot.

Average - O(n)
Worst - O(n^2) where n = input size

Also see - PREREQUISITE quickselect improved one using median of medians
*/

#include<iostream>

using namespace std;

///Lomutos partition scheme -
int partitions(int arr[] ,int low ,int high)
{
    int pivot = arr[high];  ///taking last element as pivot. We may use random generator
    int i = low;
    for(int j =low ; j<high;j++)
    {
        if(arr[j]<=pivot)
        {
            swap(arr[j],arr[i]);
            i++;
        }
    }
    swap(arr[i],arr[high]);
    return i;
}


int quickSelect(int arr[] , int low, int high , int k)
{
    //if array contains only one element , return that
    if(low == high)
        return arr[low];

        int pi = partitions(arr, low, high);

         // The pivot is in its final sorted position
        if(k == pi)
            return arr[pi];

        // if `k` is less than the pivot index
        else if(k<pi)
            return quickSelect(arr , low , pi-1,k);

        // if `k` is more than the pivot index
        else
            return quickSelect(arr, pi+1 , high , k);

}
int main()
{
    int n ,arr[100];
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int k;
    cin >> k;  /// k is index => k = 2 means 0,1,2 i.e. 3rd smallest element
    cout << quickSelect(arr,0,n-1,k);
    return 0;
}

