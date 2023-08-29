/**
If elements are in range 1 to n^2 then counting sort is inefficient as it will take O(n^2)
So we use Radix sort  -

This is also known as Bucket sort.Bucket sort takes a lot of space when
programmed for real scenario . 9 size bucket to sort integer , 26 for alphabet
40 for alphanumeric .......etc. This sort is inefficient. Even in sorting integers.
If numbers are large => digits are more => count sort will be called more => more space.

Here we have used counting sort as subroutine. Since digit vary 0-9
count sort will work very fast for such small range.

stability : yes (since count sort is stable)
inplace : NO
Comparison : NO   (advantage over comparative algo)
best time : O(n+k)
average : O(n+k)
worst : O(n+k)
space : depends on largest elements digit count
*/

#include<iostream>

using namespace std;

int arr[100];

void countSort(int n , int place)
{
    int counts[10] = {0};
    int output[n];
    for(int i=0;i<n;i++)
    {
        counts[(arr[i]/place)%10] ++;
    }
    for(int i=0;i<9;i++)
    {
        counts[i] += counts[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        int val = arr[i];
        output[counts[(val/place)%10]-1] = val;
        counts[(val/place)%10] --;
    }
    for(int i=0;i<n;i++)
        arr[i] = output[i];
}

void radixSort(int n)
{
    int maxs =0;
    for(int i=0;i<n;i++)
        maxs = max(maxs ,arr[i]);

    for(int place = 1; maxs/place>1 ; place*=10)
        countSort(n,place);
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    radixSort(n);
    for(int i=0;i<n;i++)
        cout << arr[i] <<" " ;
    return 0;
}
