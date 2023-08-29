/*
Brute force - find product of each subarray
Optimized - Kadanes Algorithm type - O(n) time and O(1) space
*/
#include<iostream>

using namespace std;

long long maxProduct(int *arr, int n) {
	    // code here
	    long long minval = arr[0];
	    long long maxval = arr[0];
	    long long maxprod = arr[0];
	    for(int i=1 ;i<n ;i++)
	    {
	        if(arr[i] <0)
	            swap(maxval , minval);
	        maxval = max((long long)arr[i] ,maxval*(arr[i]) );
	        minval = min((long long)arr[i] , minval*arr[i]);

	        maxprod = max(maxprod , maxval);

	    }
	    return maxprod;
}

int main()
{
    int arr[] = { 1, -2, -3, 0, 7, -8, -2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Sub array product is "
         << maxProduct(arr, n);
    return 0;
}
