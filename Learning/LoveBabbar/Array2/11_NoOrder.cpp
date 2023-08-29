//The two pointer method - order is not maitained
#include<iostream>

using namespace std;

void rearrange(int arr[] , int n)
{
    int i=0 , j=n-1;
    while(i<j)
    {
        while(i<j && arr[i]>0)
            i++;
        while(i<j && arr[j]<0)
            j--;
        swap(arr[i] , arr[j]);
    }
    //(i=0 means all elements are negative) (i=n means all elements are positive)
    if(i==0 || i==n)
        return;
    int k=0;
    while(k<n && i<n)
    {
        if(k%2 == 0)  //even i.e. negative number should be there
         {
             swap(arr[k] , arr[i]);
             i++;
         }
        k++;

    }
}

int main()
{
    int arr[] = {2, 3, -4, -1, 6, -9};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Given array is \n";
    for(int i=0 ;i<n ;i++)
        cout << arr[i] << " ";
    cout << endl;

    rearrange(arr, n);

    cout << "Rearranged array is \n";
    for(int i=0 ;i<n; i++)
        cout << arr[i] <<  " ";
    cout << endl;
    return 0;
}
