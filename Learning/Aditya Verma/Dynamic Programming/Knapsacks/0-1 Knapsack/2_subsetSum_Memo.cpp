///also do gfg.practice
/*
I have write this code from basic recursion then to memoisation
In next I have turn memoized code to tabulation code
After this problem I will derive solution from previous solution

For Recursive solution -
Complexity Analysis: The above solution may try all subsets of given set in worst case.
Therefore time complexity of the above solution is exponential.
The problem is in-fact NP-Complete (There is no known polynomial time solution for this problem).

For Memosize code -
Time Complexity: O(sum*n), where sum is the ‘target sum’ and ‘n’ is the size of array.
Auxiliary Space: O(sum*n), as the size of 2-D array is sum*n.
*/


#include<iostream>

using namespace std;

int t[7][10];

bool solve(int arr[] , int sum , int n)
{
    if(n==0 && sum != 0)
        return false;
    if(sum == 0)
        return true;
    if(t[n][sum] != -1)
        return t[n][sum];
    if(arr[n-1] <=sum)
        return t[n][sum] = solve(arr , sum-arr[n-1] , n-1) || solve(arr, sum , n-1);
    else
        return t[n][sum] = solve(arr , sum , n-1);
}

int main()
{
    int sets[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    for(int i=0 ; i<7 ; i++)
    {
        for(int j=0 ; j<10 ; j++)
        {
            t[i][j] = -1;
        }
    }
    cout <<  solve(sets , sum , 6);
    return 0;
}
