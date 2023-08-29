///array with elements which first monotically increasing then monotonically decreasing .find max element
///in bitonic array - repetitions not come
#include<iostream>

using namespace std;

int arr[100];

int solve(int n)
{
    int low = 0 , high = n-1;
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        if(mid != 0 && mid != n-1 && arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
            return arr[mid];
        else if(mid == 0 && arr[mid] > arr[mid+1])
            return arr[mid];
        else if(mid == n-1 && arr[mid] > arr[mid-1])
            return arr[ mid];
        else if(arr[mid] > arr[mid-1])
            low = mid+1;
        else if(arr[mid] < arr[mid-1])
            high = mid -1;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cout << solve(n);
    return 0;
}
