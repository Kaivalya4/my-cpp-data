/*
Refer techiedelight article and kc Ang video to understand the code of article better

In iterative code we have seen that - all element left to pivot are smaller and to right are greater
In recursive code we have to do one step which is called Partitioning

Recursive idea -
->PIVOT SELECTION - pick an elment , called a pivot ,from the array
->PARTITIONING(most important : how we achieve it?) - Reorder the array such that all elements with values less than the pivot come
before the pivot and all elements with values greater than the pivot come after it.Equal
values can go either way. After this partitioning , the pivot is in its final position.
->Recur - recusively apply the above steps to the subarray of elements with smaller values than pivot
i.e. recur on left of the pivot and seperately to the subarray of elements with greater values
than that of the pivot i.e. recur on right of pivot

Base Case - 1 as array of size 1 is already sorted

So left of pivot = all elements smaller than pivots(these elements may not be sorted in themselves so we recur quicksort on them)
right of pivot = all elements greater than pivots(thes elements may not be sorted in themselves so we recur quicksort on them)

There are many different versions of quickSort that pick pivot in different ways.

1. Always pick first element as pivot.
2. Always pick last element as pivot (implemented below)
3. Pick a random element as pivot.
4. Pick median as pivot.

*/

//O(nlogn) - average time
//O(n^2) - worst time
//O(1) - Space
#include<iostream>

using namespace std;

int partitions(int arr[] , int start , int ends )
{
    //we will store index where pivot will be stored
    //intially at start
    int pindex = start;

    int pivot = arr[ends];

    // each time we find an element less than or equal to the pivot, `pIndex`
    // is incremented, and that element would be placed before the pivot.
    // keep in mind that pivot is still at last we are just collecting all the elements less than pivot before
    // pindex and as all the array will be searched we will swap pivot with element with pindex

    for(int i=start ; i<ends ; i++)  //ends not included because arr[ends] is pivot
    {
        //whenever an element is less than pivot we swap elements of arr[i] and pindex
        if(arr[i] <= pivot){
            swap(arr[i] , arr[pindex]);
            pindex++;
        }
    }
    //now all elements before pindex are smaller thant pivot . So we place pivot at pindex-
    swap(arr[ends] , arr[pindex]);
    return pindex;

}

void quickSort(int arr[] , int start , int ends)
{
    if(start < ends)  //incase of 1 element this is not satisfied i.e. base condition reached
    {
        int pindex = partitions(arr , start , ends); //pindex - partition index => index of pivot

        //pivot -1 and pivot +1 because pivot is already in its correct position
        quickSort(arr , start , pindex-1); //now let us sort left side of pivot
        quickSort(arr , pindex+1 , ends) ; //right side of pivot
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    for(int i=0 ; i<n ; i++)
        cout << arr[i] << " ";
    return 0;
}
