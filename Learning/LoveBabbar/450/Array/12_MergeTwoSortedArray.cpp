/**
Merge Two sorted arrays -
->use of extra space - (n+m)log(n+m) time and (n+m) space
->use of merge sort and extra space - n+m time and space

What if extra space use is not allowed
->Use of insertion sort - Run a loop on first array and compare it with first element of second array . If array2
    has greater element than swap . After swaping run insertion sort on second array
    O(n*m) time - n for traversing first array and m for one-go insertion sort at a time.
->Use of shell sort - O( (n+m)log(n+m) ) average and O( (n+m)*(n+m) ) worst . Chance of Worst case is almost zero
    Because array is partially sorted. (first n element is sorted , first m element is sorted)
    The AC code -
    void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    int size = (n+m+1)/2;
	    for(int gap = size; gap >=1; gap /=2)
	    {
	        for(int i=gap ; i<n+m ; i++)
	        {
	            int temp = (i >=n) ? arr2[i-n] : arr1[i] ;
	            int j = i;
	            int val = (i-gap >=n) ? arr2[i-gap-n] : arr1[i-gap];
	            while(j>=gap && val>temp)
	            {
	                if(j>=n)
	                    arr2[j-n] = (j-gap>=n) ? arr2[j-gap-n] : arr1[j-gap];
	                else
	                    arr1[j] = arr1[j-gap];
	                j -=gap;
	                val = (j-gap >=n) ? arr2[j-gap-n] : arr1[j-gap] ;
	            }
	            if(j>=n)
	                arr2[j-n] = temp;
	            else
	                arr1[j] = temp;
	        }
	    }
	}
->A trick of two pointers - Try to make all smaller element to one side.
    i = 0 , j = 0 , k = n-1
    if(arr1[i] <= arr2[j])
        arr1[i] will remain in arr1
    else /// arr2[j] is smaller . So  elements after arr1[i] deserves less to be in arr1 and arr2[j] deserves
        /// more . So why not swap arr2[j] with last element of arr1[i] which deserves less
        swap them.

    void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    int i=0 , j = 0 , k = n-1;
	    while(i<=k && j<m)
	    {
	        if(arr1[i] < arr2[j])
	            i++;
	        else
	            swap(arr1[k--] , arr2[j++]);
	    }
	    sort(arr1 , arr1+n);
	    sort(arr2 , arr2 +m);
	}
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You" ;
    return 0;
}
