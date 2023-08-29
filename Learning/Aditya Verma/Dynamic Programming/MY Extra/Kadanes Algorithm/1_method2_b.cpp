//maximum subarray sum with their indices
//O(n) solution

#include<iostream>

using namespace std;
int l , r;

int maxSubArraySum(int arr[] , int n)
{
    int sum =0 , maxi = arr[0] , min_sum = 0;
    int ans_l =0 , ans_r = 0  , min_pos = 0;
    for(int i=0 ;i<n ;i++)
    {
        sum += arr[i];
        int curr = sum - min_sum;
        if(curr > maxi)
        {
            maxi = curr;
            ans_r = i;
            ans_l = min_pos + 1;
        }
        if(min_sum > sum)
        {
            min_sum  = sum;
            min_pos = i;
        }
    }
    l = ans_l;
    r = ans_r;
    return maxi;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum << endl;
    for(int i=l ;i<=r ;i++)
        cout << a[i] << " ";
    return 0;
}
