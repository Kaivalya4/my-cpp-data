/*
Given T test cases and in each test case a number N.
Print its factorial for each test case %M
where M=10^9+7.

Constraints-
1<=N<=10^5
1<=T<=10^5
*/

#include<iostream>

using namespace std;

const int M = 1e9+7;

int main()
{
    int t , n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        long long fact = 1;
        for(int i=2 ; i<n ; i++)
            fact = (fact*i) %M;
        cout << fact;
    }
    return 0;
}
//O(N^2) worst time
