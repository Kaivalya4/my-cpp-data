/**
In Lamuto I have verified two way - pivot at first and pivot at second
Here we implement Hoare(pivot at first).

->note that in this scheme , the pivots final location is not necessarily at the index
  that was returned.
->Haores scheme ismore efficient than Lomutos partition scheme because it does
  three times fewer swaps on average, and it creates efficient partitions even when all
  values are equal.But like Lomutos partition scheme, Hoare partitioning also causes
  quicksort to degrade to O(n^2) when the input array is already sorted: it also
  doesnt produce a stable sort.
*/

#include<iostream>

using namespace std;

int Tripathipartitions(int arr[] , int low ,int high)
{
    int pi = arr[low];
    int i=low-1;
    int j = high+1;
    while(true)
    {
        do{
            i++;
        }while(arr[i]<pi);
        do{
            j--;
        }while(arr[j]>pi);
        if(i>=j)
            return j;
        swap(arr[i],arr[j]);
    }
}

void HoareSort(int arr[] , int low , int high)
{
    if(low < high)
    {
        int pi = Tripathipartitions(arr , low, high);
        HoareSort(arr, low , pi);
        HoareSort(arr,pi+1,high);
    }
}
int main()
{
    int arr[100];
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    HoareSort(arr , 0 , n-1);
    for(int i=0;i<n;i++)
        cout << arr[i] <<" " ;
    return 0;
}
