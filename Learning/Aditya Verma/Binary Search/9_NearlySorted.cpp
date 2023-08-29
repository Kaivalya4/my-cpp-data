#include<iostream>

using namespace std;

int arr[100];

int solve(int n , int target)
{
    int low = 0 , high = n-1;
    while(low <=high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] == target)
            return mid;
        else if(mid !=0 && arr[mid-1] == target)
            return mid-1;
        else if(mid !=n-1 && arr[mid+1] == target)
            return mid+1;
        else if(target < arr[mid])
            high = mid-1;
        else if(target > arr[mid])
            low = mid+1;
    }
    return -1;
}

int main()
{
    int n , target;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cout << "Enter target : ";
    cin >> target;
    cout << solve(n,target);
    return 0;
}
