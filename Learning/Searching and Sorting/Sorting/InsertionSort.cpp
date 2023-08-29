///Stable , in-place sorting algorithm
///it is also a well known online algorithm since it can sort a list as it receives it.
///Insertion sort takes maximum time to sort if elements are sorted in reverse order => O(n^2)
///And it takes minimum time (Order of n) when elements are already sorted.
///Average - nearly quadratic = O(n^2)
///Better than other quadratic sorting algorithm .
///Refer rema for more

/**
pick an element from unsorted part . finds it right position . shift all value to right and put the correct
value there -
the idea is to divide the array into two subsets - sorted subset and unsored
subset. Initially, a sorted subset consists of only one first element at index 0. Then
for each iteration, insetion sort removes the next element from the unsorted
subset, finds the location it belongs within teh sorted subset and inserts it there.
It repeats until no elements to be processed in unsorted part remains.
*/

#include<iostream>

using namespace std;

int arr[100];

void InsertionSort(int n)
{
    for(int i=1;i<n;i++)  ///starting with second element
    {
        int value = arr[i];
        int j=i;
        while(j >0 && arr[j-1]>value )  /// arr[j-1] < value ---> for descending order
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = value;
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cout << "Before sorting : " ;
    for(int i=0;i<n;i++)
        cout << arr[i] <<  " " ;
    cout << endl;
    InsertionSort(n);
    for( int i=0;i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
