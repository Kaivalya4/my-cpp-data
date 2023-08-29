/**
use large value to cut earlier . So that less number of pieces will have to be cutted .
and use less cost later to cut large number of pieces.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve(int x[] , int y[] , int n , int m )
{
    int i =0 , j =0 ;
    int cost = 0;
    sort(x  ,x+n , greater<int>());
    sort(y , y+m , greater<int>());

    int horcount = 1 , vercount = 1;

    ///just like merge sort routine
    while(i<n && j<m)
    {
        if(x[i]>=y[j])
        {
            cost += (x[i++] * vercount) ;
            horcount ++;
        }
        else{
            cost += (y[j++] * horcount);
            vercount++;
        }
    }

    while(i<n)
    {
        cost += x[i++] * vercount ;
        horcount ++;
    }
    while(j<m)
    {
        cost += y[j++] * horcount;
        vercount ++;
    }
    cout << cost << endl;
}

int main()
{
    int m = 6 , n = 4; /// - |
    int Y[m-1] = {2, 1, 3, 1, 4};
    int X[n-1] = {4, 1, 2};
    solve(X , Y , n  , m) ;
    return 0;
}

