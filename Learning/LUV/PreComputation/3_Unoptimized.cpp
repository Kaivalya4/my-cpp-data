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

int main()
{
    int n , q ;
    cin >> n;
    for(int i=1 ;i<=n ; i++)  //since l, r starting from 1 so we do  one based indexing
        cin >> a[i];
    cin >> q;
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        long long sum = 0; // since array element is of size 10 power 9 so sum might exceed 10 power 9
        for(int i=l ; i<=r ; i++)
            sum = sum + a[i];
        cout << sum;
    }
    return 0;
}
