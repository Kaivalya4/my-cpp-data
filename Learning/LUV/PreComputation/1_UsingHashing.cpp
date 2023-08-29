/*
Given T test cases and in each test case a number N.
Print its factorial for each test case %M
where M=10^9+7.

Constraints-
1<=N<=10^5
1<=T<=10^5

A Test Case : ip - 5 2 2 4 6 7  op -  2
                                      24
                                      720
                                      5040
                                      40320
*/
#include<iostream>

using namespace std;
const int N = 100001;
int hsh[N];

int main()
{
    int t , n;
    hsh[0] = hsh[1] = 1;
    for(int i=2 ; i<=N ; i++)
        hsh[i] = hsh[i-1] * i;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << hsh[n] << " ";
    }
    return 0;
}
