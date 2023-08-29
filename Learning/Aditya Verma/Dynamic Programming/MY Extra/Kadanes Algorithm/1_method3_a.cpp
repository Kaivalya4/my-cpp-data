//Maximum Subarray sum
//Kadanes Algorithm - O(n)

#include<iostream>

using namespace std;

int maxSubArraySum(int arr[] , int n)
{
    int maxi =arr[0] , sum =0;
    for(int i=0 ;i<n ;i++)
    {
        sum += arr[i];
        maxi = max(maxi , sum);
        if(sum < 0)
            sum =0;
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
