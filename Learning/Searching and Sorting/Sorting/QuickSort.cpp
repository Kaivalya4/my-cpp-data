/**
Quick Sort is also known as partition exchange sort is D&C just like merge sort.
Instead dividing from median , we choose a partition . put all smaller element than pivot before pivot.
put all greater element than pivot after pivot. Way to choose pivots -
end of array
start of array
mid point of array
random location in array.

once pivot found . Partition array . The process of finding position of partition so that all smaller element lie
in left and all greater lie in right and then breaking the array . Repeating the same on smaller subarrays .
Above process make array sorted . Once the size of array becomes 1 . All elements are already sorted.

Stability : no
Inplace : yes
Comparison : yes

Best tc : O(nlogn)   -when pivot is middle or near th middle
average : O(nlogn)   -when avobe condition not occur
worst : O(n^2)    - pivot is smallest or greatest element . So if pivot is largest then pivot is at
the end of the array . So one array empty and array of size n-1.

quicksort algorithm has better performance for scattered pivots.

*/

///pivot at the end of array
#include<iostream>

using namespace std;

int arr[100];
int counts = 0;
int partitions(int arr[]  ,int low , int high)
{
    int pivot = arr[high];   ///last element as pivot
    int i = low;
    for(int j = low ;j<high;j++)
    {
        if(pivot>=arr[j])  ///once an element smaller than pivot is found . put it at i . for the first time i=0 . So smaller elements go to 0,1,...,pivot
        {
            counts ++ ;
            swap(arr[i],arr[j]);
            i++;
        }
    }
    ///all smaller element and larger element are at its correct position . now just place pivot to its correct position
    swap(arr[i],arr[high]);
    return i;
}

void quickSort(int arr[] , int low , int high)
{
    if(low<high)
    {
        int pi = partitions(arr , low, high);  ///find partition
        quickSort(arr , low , pi-1);  ///left subarray
        quickSort(arr , pi+1 , high);  ///right subarray
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    quickSort(arr , 0 , n-1);
    for(int i=0;i<n;i++)
        cout << arr[i] <<" " ;
    cout << endl << counts;
    return 0;
}
