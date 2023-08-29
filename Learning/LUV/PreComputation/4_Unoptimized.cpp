/*
Given 2d array ar of N*N integer . Given Q queries and
in each query given a,b,c and d . print sum of square
represented by (a,b) as top left point and (c,d) as
top bottom right point.

Constraints:
1<=N<=10^3
1^<=a[i][j]<=109
1<=Q<=10^5
1<=a,b,c,d<=N

Test Case : ip -
3
3 6 2
8 9 2
3 4 1
2
1 1 2 2
1 2 3 3

op - 9
*/
#include<iostream>

using namespace std;

const int N = 1001;
int ar[N][N];

int main()
{
    int n,q;
    cin >> n;
    for(int i=1 ;i<=n ; i++)  //since ab,cd are given on basis of 1 based indexing
    {
        for(int j=1 ; j<=n ; j++)
        {
            cin >> ar[i][j];
        }
    }
    cin >> q;
    while(q--)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        long long sum  =0 ;  //since elements of array are of power 9 so sum may exceed power of 9
        for(int i=a ; i<=c ; i++)
        {
            for(int j=b ; j<=d ; j++)
            {
                sum += ar[i][j];
            }
        }
        cout << sum << endl;
    }
    return 0;
}
