///Also do gfg.practice - shortes common supresequence
#include<iostream>
#include<string.h>

using namespace std;

int superSeq(string x ,string y , int n ,int m)
{
    int t[n+1][m+1];
    for(int i=0 ;i<n+1 ;i++)
    {
        for(int j=0 ;j<m+1 ;j++)
        {
            if(i==0 || j==0)
                t[i][j] =0;
        }
    }
    for(int i=1 ;i<n+1 ;i++)
    {
        for(int j=1 ;j<m+1 ; j++)
        {
            if(x[i-1] == y[j-1])
                t[i][j] = 1+t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
        }
    }
    int val  = t[n][m];
    int sub_from_x = n-val; //subtracted lcs form x
    int sub_from_y = m-val; //subtracted lcs from y
    return sub_from_x + sub_from_y + val;
}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    cout << "Length of the shortest supersequence is "
         << superSeq(X, Y, strlen(X), strlen(Y));
    return 0;
}
