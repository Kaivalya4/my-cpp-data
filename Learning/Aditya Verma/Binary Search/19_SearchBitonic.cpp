///Search in a bitonic array

///Best way(that i have not done in this code) is to find bitonic point then
///search in left to bitonic using BS and righ to bitonic using BS(including bitonic point)
#include<iostream>

using namespace std;

int arr[100];

int solve(int n , int ele)
{
    int low = 0 , high = n-1;
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] == ele)
            return mid;
        else if(arr[mid] > ele)
        {
            if(mid !=0 && arr[mid] > arr[mid-1])
                high = mid-1;
            else if(mid != 0 && arr[mid] < arr[mid-1])
                low = mid+1;

        }
        else if(arr[mid] < ele)
        {
            if(mid !=0 && arr[mid] > arr[mid-1])
                low = mid+1;
            else if(mid != 0 && arr[mid] < arr[mid-1])
                high = mid-1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int ele;
    cout << "Enter the element to be searched : ";
    cin >>ele;
    cout << solve(n,ele);

    return 0;
}
