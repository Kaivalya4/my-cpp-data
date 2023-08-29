//Maximum Subarray sum
//Brute force - O(n^2)
#include<iostream>

using namespace std;

int maxSubArraySum(int arr[] , int n)
{
    int sum = 0 , maxi = INT_MIN;
    for(int i=0 ;i<n ;i++)
    {
        sum = 0;
        for(int j=i ;j<n ; j++)
        {
            sum += arr[j];
            maxi = max(sum , maxi); //we can easily modigy this solution to also store indexes
        }
    }
    return maxi;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}
