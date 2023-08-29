///Two methods we will discuss -
/**

Method1 - Brute Force - O(n^2)
simple observation if i<j and a[i] > a[j] => inversion exsists

int findInversionCount(int arr[], int n)
{
    int inversionCount = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j]) {
                inversionCount++;
            }
        }
    }
    return inversionCount;
}

Method2 - Merge Sort - O(nlogn)
  long long counts = 0;
    long long temp[500001];

void merges(long long arr[] , long  long  low , long long pi , long long high)
{
    long long  i =low , j = pi+1 , k=0;
    while(i<=pi && j<=high){
        if(arr[i]<=arr[j]) {  ///This = provides stability , if one 4 lies in first subarray and other lie in second . Then first one get copied first
            temp[k++] = arr[i];
            i++;
        }
        else
        {
            counts += (pi-i+1);  ///This is the counts - see techiedelight for formula explanation
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
    long long it=0;
    for(long t=low; t<=high;t++)
        arr[t] = temp[it++];
}

void mergeSort(long long arr[] , long long low , long long high)
{
    if(low<high){
        long long  partitions = low + (high-low)/2;
        mergeSort(arr , low ,partitions);
        mergeSort(arr , partitions+1 , high);
        merges(arr , low , partitions , high);
    }
}

    long long int inversionCount(long long arr[], long long N)
    {
        mergeSort(arr, 0, N-1);
        return counts;
    }

*/

#include<iostream>

using namespace std;

int main()
{
    cout << "Thank YOu";
    return 0;
}
