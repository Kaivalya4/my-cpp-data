#include<iostream>
#include<string.h>

using namespace std;

int lcss(string x , string y , int n , int m )
{
    int t[n+1][m+1];
    for(int i=0 ;i<n+1;i++)
    {
        for(int j=0 ;j<m+1 ; j++)
        {
            if(i==0 || j==0)
                t[i][j] = 0;
        }
    }
    int maxs = 0;
    for(int i=1 ;i<n+1 ;i++)
    {
        for(int j=1 ; j<m+1 ;j++)
        {
            if(x[i-1] == y[j-1])
            {
                t[i][j] = 1+ t[i-1][j-1];
                maxs = max(maxs, t[i][j]);
            }
            else
                t[i][j] = 0;
        }
    }
    return maxs;
}

int main()
{
    char X[] = "abcdexyzefg";
    char Y[] = "xyzabcdefghi";

    int n = strlen(X);
    int m = strlen(Y);

    int counts = 0;

    cout << "Length of Longest Common Substring is "
         << lcss(X, Y, n, m );
    return 0;
}
