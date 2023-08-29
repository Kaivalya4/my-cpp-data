#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>

using namespace std;

int findMinInsertions(string str1 , int n)
{
    string str2 = str1;
    reverse(str2.begin() , str2.end());
    int t[n+1][n+1];
    for(int i=0 ;i<n+1 ;i++)
    {
        for(int j=0 ;j<n+1 ;j++)
        {
            if(i==0 || j==0)
                t[i][j] =0;
        }
    }
    for(int i=1 ;i<n+1 ;i++)
    {
        for(int j=1 ;j<n+1 ;j++)
        {
            if(str1[i-1] == str2[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
        }
    }
    return n - t[n][n];
}

int main()
{
    char str[] = "geeks";
    cout << findMinInsertions(str, strlen(str));
    return 0;
}
