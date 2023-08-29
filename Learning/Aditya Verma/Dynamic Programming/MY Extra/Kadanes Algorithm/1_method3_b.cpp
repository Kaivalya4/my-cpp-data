//maximum subarray sum and  also find indexes
//Kadanes algo - O(n) time
#include<iostream>

using namespace std;
int l , r;

int maxSubArraySum(int arr[] , int n)
{
    int sum= 0 , maxi = arr[0];
    l = 0 , r=0 ;
    int min_pos =0;
    for(int i=0 ;i<n ; i++)
    {
        sum += arr[i];
        if(sum > maxi)
        {
            maxi = sum;
            r= i;
            l = min_pos + 1;
        }
        if(sum < 0)
        {
            sum = 0;
            min_pos = i;
        }
    }
    return maxi;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum << endl;
    for(int i=l ;i<=r ;i++)
    {
        cout << a[i] <<  " ";
    }
    return 0;
}
