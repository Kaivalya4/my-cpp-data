/**
This Problem can be solved using Kadanes Algorithm in O(n) time.
->Naive : O(n^2) : check sum of every subarray
->Using Divide and conquer
	1.Divide the array into two equal subarrays.
	2.Recrusively calculate the maximum subarray sum for the left subarray.
	3.Recursively calculate the maximum subarray sum for the right subarray.
	4.Find the maximum subarray sum that crosses the middle element.
	5.Return the maximum of the above three sums.
	
	start.....i.....j...a... mid ........k....b.....m.....end   :arr
	suppose we divided the array . From left subarray the maximum sum we got is from i to j : sum1
	From right subarray the maximum sum we got is from k to m : sum2
	But It is possible that for arr a to b gives the maximum sum : sum3
	Hence we find maximum subarray that crosses the middle element.
	We can easily find the crossing sum in linear time. 
	The idea is simple, find the maximum sum starting from mid point and ending at some point on left of mid, 
	then find the maximum sum starting from mid + 1 and ending with some point on right of mid + 1. 
	Finally, combine the two and return the maximum among left, right and combination of both.
	
	This i-j and k-m will be find using recursive call on start-mid array and mid+1 to end array.
	See Ashish kumar video on youtube for this.

	The time complexity of above divide-and-conquer solution is O(nLogn) as 
	for the given array of size n , we make tow recuresive calls on the input size n/2 and
	finding the maximum subarray crosses midpoint takes O(n) time in the worst case.
	Therefore
	T(n) = 2T(n/2) + O(n)  = O(n.logn)
*/

//D&C -
#include<iostream>

using namespace std;

int MaxSubarray(int arr[] , int l  , int r)
{
	///Base Condition
	if(l==r){
		return arr[l];
	}
	
	int mid = l + (r-l)/2;
	///Induction of Our Hyposthesis
	
	
    // Find maximum subarray sum for the left subarray,
    // including the middle element
    // ........<------mid...
	int leftmax = INT_MIN;
	int sum = 0;
	for(int i=mid;i>=l;i--)
	{
		sum += arr[i];
		if(sum > leftmax)
			leftmax = sum;
	}
	
	 // Find maximum subarray sum for the right subarray,
    // excluding the middle element
    // ...(mid+1)---->.....
    int rightmax = INT_MIN;
    sum =0;
    for(int i=mid+1;i<=r;i++)
    {
    	sum += arr[i];
    	if(sum > rightmax)
    		rightmax = sum;
	}
	
	int css = leftmax + rightmax;
	int lss = MaxSubarray(arr,l,mid);
	int rss = MaxSubarray(arr,mid+1,r);
	
	return max(css , max(lss,rss)); 
}
int main()
{
	int arr[100];
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> arr[i];
	cout << MaxSubarray(arr,0,n-1);
	return 0;
}