///Question - Find kth smallest element
///if we use quickselect then its average case time complexity is  O(n) but
///worst case time complexity is O(n^2)
///so we will improve this worst case time complexity using Median of Medians Algorithm

/**
->divde the array into bucket of 5 - here # denotes median
[***#*][#****][****#][*#***]..........[*#*$$]  -> last bucket may have 5 or less element

->sort each bucket. Since size is five so we can say sorting of one bucket takes O(1) time and sorting
of each bucket takes O(n/5)time as there are ~ n/5 buckets
[**#**][**#**][**#**]...........

->median holds its correct position in bucket, so we can take out median in O(1) time.Make array of those medians
{#1,#2,#3,.....,#n/5}

->Recursively follow the above method again on this median array.

CLAIM - Medain of Medains give the median of entire array.
We will use this final median as pivot.
*/

///since quickselect find the median very fastly on average time . So median of median calculation has been
///done inside the quickselect function and recursive call has been made to quickselect for the same in gfg
///code.
#include<iostream>
#include<algorithm>

/*
7
2 3 9 100 10 29 4
*/
using namespace std;

int TakeMedian(int arr[] , int n)
{
    sort(arr , arr+n);
    return arr[n/2];   //5/2 = 2.
}

int FindMedian(int arr[]  ,int low , int high)
{
    int n = (high - low + 1);
    int medians[(high-low+1)/5] ;
    int i;

    /// Divide arr[] in groups of size 5, calculate median
    /// of every group and store it in median[] array.
    for(i=0;i<n/5 ; i++)
        medians[i] = TakeMedian(arr+low+i*5 , 5); /// if arr = 1,2,3,4,5,6,7,8,9,..... . if i = 1 then 0th index
        ///of arr in TakeMedian will contain 6.

    ///For last group with less than 5 elements
    if(i*5  < n){
        medians[i] = TakeMedian(arr+low+i*5 , n%5);
        i++;
    }

    ///if there is only one bucket i.e. median has only one element then return that
    if(i == 1)
    {
        return medians[0];
    }
    else{
        return FindMedian(medians , 0,i-1);
    }
}

int partitions(int arr[] , int low, int high, int medians)
{
    int x ;
    for(int i=low;i<=high;i++)
    {
        if(arr[i] == medians)
           {
               x = i;
               break;
           }
    }
    swap(arr[x],arr[high]);
    int pivot = arr[high];
    int i = low;
    for(int j = low; j<high; j++)
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

int KthSmallest(int arr[] , int low , int high , int k)
{
    if(arr[low] == arr[high])
        return arr[low];

    int median = FindMedian(arr , low ,high);
    int pi = partitions(arr , low , high ,median);
    if(k == pi)
        return arr[k];
    else if( k <pi){
        return KthSmallest(arr , low , pi-1 ,k );
    }
    else
        return KthSmallest(arr , pi+1 , high ,k);
}

int main()
{
    int arr[100];
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int k;
    cin >> k;
    cout << KthSmallest(arr , 0 , n-1 , k-1);
    return 0;
}
