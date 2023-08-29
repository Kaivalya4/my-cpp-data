///Also do gfg.pracitce
#include<iostream>
#include<string.h>

using namespace std;
//we can create table by looking at constraints
int t[7][8];  //here [n+1][m+1]

int lcs(string x ,string y , int n ,int m)
{
    if(n==0 || m==0)
        return 0;
    if(t[n][m] != -1)
        return t[n][m];
    if(x[n-1] == y[m-1])
        return t[n][m] = 1+ lcs(x,y,n-1,m-1);
    else
        return t[n][m] = max(lcs(x,y,n-1,m) , lcs(x,y,n,m-1));
}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int n = strlen(X);
    int m = strlen(Y);

    for(int i=0 ;i<=n ; i++)
    {
        for(int j=0 ;j<=m ; j++)
        {
            t[i][j] = -1;
        }
    }

    cout<<"Length of LCS is "<< lcs( X, Y, n, m ) ;
    return 0;
}
