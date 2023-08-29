/**
Merge sort is a Divide and Conquer Algo-
Keep on dividing the array in equal parts(subproblems) and then merge the sorted subarrays.

Stability : yes
Comparison : yes
Inplace : no

Best tc : O(nlogn)
Worst : O(nlogn)
Average : O(nlogn)
Space : O(n)

most famous problem : Inversion count
*/

#include<iostream>

/*
7
1 3 -1 4 4 7 2
*/

using namespace std;

int arr[100];
int temp[100];

void merges(int arr[] , int low , int pi , int high)
{
    int i =low , j = pi+1 , k=0;
    while(i<=pi && j<=high){
        if(arr[i]<=arr[j]) {  ///This = provides stability , if one 4 lies in first subarray and other lie in second . Then first one get copied first
            temp[k++] = arr[i];
            i++;
        }
        else
        {
            temp[k++] = arr[j];
            j++;
        }
    }
    while(i<=pi)
    {
        temp[k++] = arr[i];
        i++;
    }
    while(j<=high)
    {
        temp[k++] = arr[j];
        j++;
    }
    int it=0;
    for(int t=low; t<=high;t++)
        arr[t] = temp[it++];
}

void mergeSort(int arr[] , int low , int high)
{
    if(low<high){
        int partitions = low + (high-low)/2;
        mergeSort(arr , low ,partitions);
        mergeSort(arr , partitions+1 , high);
        merges(arr , low , partitions , high);
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    mergeSort(arr , 0 , n-1);
    for(int i=0;i<n;i++)
        cout << arr[i] <<" " ;
    return 0;
}
