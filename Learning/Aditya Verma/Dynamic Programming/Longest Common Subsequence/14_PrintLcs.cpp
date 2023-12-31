///Also try : print all lcs subsequences - gfg.practice -> I did backtracking on table (in all possible
///way) . Worked fine for small input but gives tle for large i/p .Then I used mapping as memoisation
///and finally it worked

#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

void lcs(string x , string y , int n , int m)
{
    int t[n+1][m+1];
    for(int i=0 ;i<n+1 ;i++)
    {
        for(int j=0 ;j<m+1 ; j++)
        {
            if(i==0 || j==0){
                t[i][j]= 0 ;
            }
        }
    }
    for(int i=1; i<n+1 ;i++)
    {
        for(int j=1 ;j<m+1 ; j++)
        {
            if(x[i-1] == y[j-1])
                t[i][j] = 1+t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
        }
    }
    int i=n;
    int j=m;
    string ans;
    while(i>0 && j>0)
    {
        if(x[i-1] == y[j-1])
        {
            ans.push_back(x[i-1]);
            i--;
            j--;
        }
        else
        {
            if(t[i-1][j] > t[i][j-1])
                i--;
            else
                j--;
        }
    }
    reverse(ans.begin() , ans.end());
    cout << ans ;
}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int n = strlen(X);
    int m = strlen(Y);
    lcs(X, Y, n, m);
    return 0;
}
