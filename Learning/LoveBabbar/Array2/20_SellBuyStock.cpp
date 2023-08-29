//first go through PREREQUISITE
/*
-> We can do like: answer = max(maxDiff in 0 to i  + maxDiff in i+1 to n-1)
if we use second method to find maxDiff then for 1 iteration i.e. 0 to i + i to n-1 will take O(n) time
    and in total it will take O(n^2) time for all iterations and O(1) space.
    It is like D&C approach

We can also consider below 2 solution as dp also -
-> We can optimise above code - Basically we use 2 variation of same approach to find maxDiff -
1.we make a left array and store minsofar and maxDiff so far at any point i in array and store it in left array
it is like finding maxDiff from left to right and storing it in left array .
2.we make a right array and find maxDiff from right to left using maxsofar variable.
So at left[i-1]+right[i] gives sum of maxDiff from 0 to i-1 and i to n-1 just like the above method
So O(n) time and O(2n) space

-> we can further optimise above code to simply use one array profit . we first store from left to right in
profit array and instead of using another array for left to right we add values then and there only

OTHER VARIATION PROBLEM SOLUTION -
=> INFINITE TRANSACTION POSSIBLE -> DP - use of valley-peak approach :
    A kadanes type dp where we track values in single variable
=> ATMOST 1 TRANSACTION POSSIBLE -> This is same problem as maxDiff : See PREREQUISITE
*/

#include<iostream>

using namespace std;

//method1
int maxDiff(int price[] , int start , int n)
{
    if(n<1)
        return 0;
    int maxDiff = 0;
    int minval = price[start] ;
    for(int i=start+1;i<=n;i++)
    {
        maxDiff = max(maxDiff , price[i] - minval);
        minval = min(price[i] , minval);
    }

    return maxDiff;
}

int maxProfit1(int price[] , int n)
{
    int sum = 0;
    for(int i=1;i<n;i++)
    {
        int val1 = maxDiff(price , 0,i-1);
        int val2 = maxDiff(price , i , n-1);
        sum  = max(sum , val1 + val2);
    }
    int val = maxDiff(price ,0,n-1);
    sum = max(sum ,val);
    return sum;
}

//method2
int maxProfit2(int price[] , int n)
{
    //highest profit , second highes profit
    int minsofar = price[0];
    int maxsofar = price[n-1];
    int profit =0;
    int left[n] ;
    int right[n];
    left[0] = right[n-1] = 0; //buy and sell on same day does not give profit
    for(int i=1;i<n;i++)
    {
        left[i] = max(left[i-1] , price[i] - minsofar); //left[i-1] itself storing maxsofar.
        minsofar = min(minsofar , price[i]);
    }
    for(int i=n-2;i>=0;i--)
    {
        right[i] = max(right[i+1] ,maxsofar - price[i]);
        maxsofar = max(maxsofar , price[i]);
    }
    profit = right[0];
    for(int i=1;i<n; i++)
    {
        profit = max(profit , left[i-1]+right[i]); //left[0] means when only we buy i.e. 0 profit
        //right[1] means maxDiff from i to n-1
    }
    return profit;
}

int main()
{
    int price[] = { 2, 30, 15, 10, 8, 25, 80 };
    int n = sizeof(price) / sizeof(price[0]);
    cout << "Maximum Profit = " << maxProfit1(price, n) << endl;
    cout << "Maximum Profit = " << maxProfit2(price, n);
    return 0;
}
