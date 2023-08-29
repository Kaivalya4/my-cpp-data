#include<iostream>

using namespace std;

int arr[100];

int findPivot(int low ,int high)
{
    int loc = low  ,left = low, right = high;
    bool flag = false;
    while(!flag)
    {
        while(arr[loc] <= arr[right] && loc != right)
            right --;
        if(loc == right)
            flag = true;
        else if(arr[loc] > arr[right])
        {
            int temp = arr[loc];
            arr[loc] = arr[right];
            arr[right] = temp;
            loc = right;
        }
        if(flag)
        {
            while(arr[left] <= arr[loc] && loc != left)
            {
                left ++;
            }
            if(loc == left)
                flag = true;
            else if(arr[loc] < arr[left])
            {
                int temp = arr[loc];
                arr[loc] = arr[left];
                arr[left] = temp;
                loc = left;
            }
        }
    }
    return loc;
}

void quicksort(int low , int high)
{
    if(low < high)
    {
        int pi = findPivot(low,high);
        quicksort(low,pi-1);
        quicksort(pi+1,high);
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    quicksort(0,n-1);
    for(int i=0;i<n;i++)
        cout << arr[i] <<" " ;
    return 0;
}
