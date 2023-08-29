///Given an array - sort it in ascending order.
///we convert array to maxheap . Finally from maxheap we convert array to sorted array
#include<iostream>
#include<cmath>

using namespace std;

int arr[100];

void MaxHeapify(int i , int n)
{
    int largest = i;
    int leftChild = 2*i+1;
    int RightChild = 2*i+2;
    if(leftChild<n && arr[leftChild] > arr[largest] )
        largest = leftChild;
    if(RightChild<n && arr[RightChild] > arr[largest])
        largest = RightChild;
    if(largest != i)
    {
        swap(arr[i] , arr[largest]);
        MaxHeapify(largest , n);
    }
}

void BuildHeap(int n)
{
    for(int i=(floor((double)n/(double)2) - 1) ; i>=0 ;i--)
            MaxHeapify(i,n);
}

void heapSort(int n)
{
    int sizes = n;
    BuildHeap(n);
    for(int i=n-1 ; i>=1; i--)
    {
        swap(arr[i] ,arr[0]);
        MaxHeapify(0,--sizes);
    }
}

int main()
{
    int n;
    cout << "enter the size of array : ";
    cin>> n;
    cout << "ENter the element of the array : ";
    for(int i=0;i<n;i++)
        cin >> arr[i];
    heapSort(n);
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    return 0;
}
