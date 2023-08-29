#include<iostream>

using namespace std;

int arr[100];

int solve(int n ,int num)
{
    int low = 0 , high = n-1;
    int res = -1;
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        if(arr[mid] == num)
            return res = num;
        else if(num < arr[mid])
        {
            res = arr[mid];
            high = mid-1;
        }
        else if(num > arr[mid])
            low = mid+1;
    }
    return res;
}

int main()
{
    int n , num;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cout << "Enter number : ";
    cin >> num;
    cout << solve(n,num);
    return 0;
}
