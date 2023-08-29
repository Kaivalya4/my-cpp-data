//sort arrays of 0s,1s,2s without any sorting algorithm.

/*
count number of 0s , 1s , 2s . fill that 0,1,2 in sequence in array with respective count 
*/


#include<iostream>

using namespace std;

void sorting(int arr[] , int n)
{
    int one = 0 , two = 0 , zero =0;
    for(int i=0 ; i<n ; i++)
    {
        if(arr[i] == 0)
        zero++;
        else if(arr[i]==1)
        one++;
        else if(arr[i]==2)
        two++;
    }
    int k;
    for(k = 0; k<zero ; k++)
    {
       arr[k] = 0;
    }
    for(k; k<(one+zero) ; k++)
    {
       arr[k] = 1;
    }
    for(k ; k<n ; k++)
    {
        arr[k] = 2;
    }
}
int main()
{
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    sorting(arr , 12);
    for(int i=0 ; i<12 ; i++)
        cout<< arr[i] << " ";
    return 0;
}