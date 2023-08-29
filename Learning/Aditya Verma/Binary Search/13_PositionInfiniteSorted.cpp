///Find element in infinite sorted array -

/**

int arr[infinity]
int solve(int n , int num)
{
    int low = 0 , high = 1;
    while(arr[high] < num)
    {
        low = high ;
        high *=2;
    }
    while(low<=high)
    {
        int mid = low+(high - low)/2;
        if(arr[mid]==num)
            return mid;
        else if(num < arr[mid])
        {
            high = mid-1;
        }
        else if(num > arr[mid])
            start = mid+1;
    }
    return -1;
}
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank you";
    return 0;
}
