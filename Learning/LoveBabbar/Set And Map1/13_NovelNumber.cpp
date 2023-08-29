/*
method1 - Brute Force : for each element check how many larger elements are present than it.
If we got an element which is greater than size of array we will simply ignore it

method2 - Sort the array . Now all the elements which are greater than a number will lie right to that number.
We need just extra precaution for the repeated element as they will be adjacent to each other and may be right
 to the number under consideration
*/

//method2
#include<iostream>
#include<algorithm>

using namespace std;

int solve(int arr[] , int n)
{
    sort(arr , arr+n);
    int ind =0;
    for(int i=0 ; i<n-1 ; i++)
    {
        ind = i;
        while(arr[i] != arr[i+1])
        {
            ind++;
        }
        if(arr[ind] == n-ind-1)
        {
            return arr[ind];
        }
    }
    if(arr[n-1] == 0)
        return 0;
    return -1;
}

int main()
{
    int arr[] = {10, 3, 20, 40, 2};
    cout << solve(arr , 5);
    return 0;
}
