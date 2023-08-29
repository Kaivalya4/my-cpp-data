///Also do leetcode - Shortest Common Supersequence
#include<iostream>
#include<algorithm>

using namespace std;

string printShortestSuperSeq(string x ,string y , int n , int m)
{
    int t[n+1][m+1];
    for(int i=0 ;i<n+1 ;i++)
    {
        for(int j=0 ;j<m+1 ;j++)
            if(i==0 || j==0)
                t[i][j] =0;
    }
    for(int i=1; i<n+1 ;i++)
    {
        for(int j=1 ;j<m+1 ;j++)
        {
            if(x[i-1] == y[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i][j-1] , t[i-1][j]);
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
            if(t[i][j-1] > t[i-1][j])
            {
                ans.push_back(y[j-1]);
                j--;
            }
            else
            {
                ans.push_back(x[i-1]);
                i--;
            }
        }
    }
    while(i>0)
    {
        ans.push_back(x[i-1]);
        i--;
    }
    while(j>0)
    {
        ans.push_back(y[j-1]);
        j--;
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

int main()
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    int n = 6;
    int m = 7;
    cout << printShortestSuperSeq(X, Y , n, m);

    return 0;
}
