/*
method1 - sort the array :
int findmiss(vector<int>&arr , int n)
{
    sort(arr.begin() , arr.end());
    for(int i=0 ; i<n ; i++)
    {
        if(arr[i] !=i+1)
            return i+1;
    }
}

method2 - find the sum and subtract
int findmiss(vector<int>&arr, int n)
{
    total = (n+1)*(n)/2;
    for(int i=0 ; i<n ; i++)
        total = total - arr[i];
    return total;
}
*/
#include <iostream>

using namespace std;

int main()
{
    cout<< "thank you";
    return 0;
}