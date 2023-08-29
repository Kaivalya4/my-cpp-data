/**
Shell sort is an optimization over insertion sort. Her first we take giant jump then keep
reducing it . Finally gap = 1 i.e. insertion sort. But by the time we reach last step, the
elements are almost sorted.

Gap are generally decided on basis of these sequences generally -
->Shell's original sequence: N/2 , N/4 , …, 1
->Knuth's increments: 1, 4, 13, …, (3k – 1) / 2
->Sedgewick's increments: 1, 8, 23, 77, 281, 1073, 4193, 16577...
->Hibbard's increments: 1, 3, 7, 15, 31, 63, 127, 255, 511…     (next = 2*curr+1)
->Papernov & Stasevich increment: 1, 3, 5, 9, 17, 33, 65,...     (given = 1,3. next = 2*curr-1)
->Pratt: 1, 2, 3, 4, 6, 9, 8, 12, 18, 27, 16, 24, 36, 54, 81....

We will use first sequence-
Suppose size of array is n=16 then we do this for all n/2 = 8 gap size -
comparing 0th with 8th index , 9th to 1st , 10th to 2nd ........
Now n/4 = 4. so 0-4,1-5,2-6,3-7,.....
when finally reach 1 of Shells sequence then gap = 1 => insertion sort.But atmost time by then array is
already sorted.


Stability : no (Shell sort is an unstable sorting algorithm because this algorithm does not
                examine the elements lying in between the intervals. Go to w3resource shell sort visualizer
                and put array : 1 5 4 6 4 9 2 1)
Inplace : yes
Comparison : yes
Best : O(nlogn)   -> when the array is already sorted then total number of comparison in each iteration.
worst : O(n^2)
average : O(nlogn)
space : O(1)


*/

///Shell's original sequence

#include<iostream>

using namespace std;

int arr[100];

void shellSort(int n)
{
    for(int gap = n/2 ; gap>=1; gap/=2)
    {
        ///insertion sort of jump = gap
        for(int i=gap ; i<n;i++)
        {
            int temp = arr[i];
            int j = i;
            while(j>=gap && arr[j-gap]>temp)
            {
                arr[j] = arr[j-gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    shellSort(n);
    for(int i=0;i<n;i++)
        cout << arr[i] <<" " ;
    return 0;
}
