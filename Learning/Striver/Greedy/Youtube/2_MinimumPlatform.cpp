/**
Minimum number of platform :  gfg.practise
Naive approach -
Approach: The idea is to take every interval one by one and find the number of intervals
    that overlap with it. Keep track of the maximum number of intervals that overlap with an interval.
    Finally, return the maximum value.
    Time Complexity: O(n^2).
    Two nested loops traverse the array, so the time complexity is O(n^2).
    Space Complexity: O(1).
    As no extra space is required.

Greedy -
O(nlogn) time and O(1) space.
*/

/**
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr , arr+n);
    	sort(dep , dep+n);
    	int i=1 , j = 0;
    	int plat = 1 , maxi = 1;
    	while(i<n && j<n)
    	{
    	    if(arr[i] <=dep[j])
    	    {
    	        plat++;
    	        maxi  = max(plat , maxi);
    	        i++;
    	    }
    	    else
    	    {
    	        plat--;
    	        j++;
    	    }
    	}
    	return maxi;
    }
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "thank you";
    return 0;
}
