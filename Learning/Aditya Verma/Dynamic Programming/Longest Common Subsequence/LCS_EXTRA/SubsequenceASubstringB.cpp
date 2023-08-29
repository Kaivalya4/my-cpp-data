///Length of longest subsequence of A which is a substring in B
///gfg.practice - Find length of longest subsequence
/**
int t[1001][1001];
int maxSubsequenceSubstring(string a, string b, int n, int m){
    for(int i=0; i<=n;i++)
        t[i][0] =0 ;
    for(int j=0;j<=m;j++)
        t[0][j] =0;

    int ans =0 ;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1] == b[j-1]){
                t[i][j] = 1 +t[i-1][j-1] ;
                ans = max(ans , t[i][j]) ;
            }
            else{
                t[i][j] = t[i-1][j] ;/// dont skip a character in y as we need substring in y .
                                    /// instead skip current character of x as we need subsequence of x
                                    /// see image given in gfg.
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            cout << t[i][j] << " ";
        cout << endl;
    }
    return ans;
}
*/

#include<iostream>

using namespace std;

int main()
{
    cout << "Thank YOU";
    return 0;
}
