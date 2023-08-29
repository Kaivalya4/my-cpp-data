///This is O(n*m) solution , we use 2pointer for O(n) solution
///Try gfg.practice - Check for Subsequence
#include<iostream>
#include<string.h>

using namespace std;

bool isSubSequence(string str1 ,string str2  , int n , int m)
{
    int t[n+1][m+1];
    for(int i=0 ; i<n+1 ;i++)
    {
        for(int j=0 ;j<m+1 ;j++)
        {
            if(i==0 || j==0)
                t[i][j] = 0;
        }
    }
    for(int i=1 ;i<n+1;i++)
    {
        for(int j=1 ;j<m+1 ;j++)
        {
            if(str1[i-1] == str2[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
    if(t[n][m] == n)
        return true;
    return false;
}

int main()
{
    char str1[] = "gksrek";
    char str2[] = "geeksforgeeks";
    int n = strlen(str1);
    int m = strlen(str2);
    isSubSequence(str1, str2, n, m) ? cout << "Yes "
                                    : cout << "No";
    return 0;
}
