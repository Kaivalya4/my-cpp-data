/*
Given array a of N integers , given Q queries and in each
query given L and R. Print sum of array elements from index L to R(L,Rincluded)

Constraints :
1<=N<=10^5
1<=a[i]<=10^9
1<=Q<=10^5
1<=L,R<=N

Test Case : ip -
6
3 6 2 8 9 2
4
2 3
4 6
1 5
3 6
            op - 8
                 19
                 28
                 21
*/
#include<iostream>

using namespace std;
const int N = 100001;
int a[N];
long long prefix[N];  //since array element is of power 9 so sum might exceed power 9

int main()
{
    int n, q ;
    cin >>n;
    for(int i=1 ;i<=n ; i++)
    {
        cin >> a[i];
        prefix[i] = prefix[i-1] + a[i];
    }
    cin >> q;
    while(q--)
    {
        int l , r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l-1];
    }
    return 0;
}
