///Do gfg.practice - String Subsequence

/**
    gfg has very nice explanation

    int t[501][501] ;
    int countWays(string b, string a){
        // code here
        int n = a.length(); ///smaller string for which we have to search
        int m = b.length(); ///larger string in which we have to search
        for(int i=0;i<=n ;i++)
            t[i][0] = 0;
        for(int j=0;j<=m;j++)
            t[0][j] = 1;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1] == b[j-1]) ///if match = either consider both + or search for same character of a in b
                    t[i][j] = t[i-1][j-1] + t[i][j-1];
                else    ///if not match then simply make b small
                    t[i][j] = t[i][j-1];
            }
        }
        return t[n][m] ;
    }
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You" << endl;
    return 0;
}

