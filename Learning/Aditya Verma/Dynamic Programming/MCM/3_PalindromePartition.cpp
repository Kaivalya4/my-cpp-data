/**
Palindrome Partitioning - gfg.practice
->use call by reference to save yourself for tle
*/

/**
int t[501][501];
    bool isPalin(string &str , int i , int j)
    {
        while(i<j)
        {
            if(str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(string &str , int i, int j)
    {
        if(i>=j)
        {
            return 0;
        }
        if(t[i][j] != -1)
            return t[i][j];
        if(isPalin(str ,i,j))
            return 0;
        int temp = INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            int l =solve(str , i , k);
            int r = solve(str ,k+1 , j);

            temp = min(temp , l+r+1);
        }
        return t[i][j] =  temp;
    }
    int palindromicPartition(string str)
    {
        // code here
        memset(t , -1 , sizeof(t));
        return solve(str , 0,(str.length())-1);
    }
*/

/**
Leetcode - Palindrome Partitioning 2

-> Instead of writing below standard line
    We will recurse for only right part
    Only when left part turns out to be palindrome

int t[2000][2000];
    string s ;
    bool isPalin(int i , int  j)
    {
        while(i<j)
        {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(int i , int j)
    {
        if(i>=j)
        {
            return 0;
        }
        if(t[i][j] != -1)
            return t[i][j];
        if(isPalin(i,j))
            return 0;
        int temp = INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            int l , r;
            if(isPalin(i,k)){
                r = solve(k+1,j);
            temp = min(temp , 1+r);
            }

        }
        return t[i][j] = temp;
    }
    int minCut(string str) {
        s = str;
        memset(t , -1 , sizeof(t));
        return solve(0 , s.length() - 1);
    }
*/

#include<iostream>

using namespace std;

int main()
{
    cout << "Thank YOu" << endl;
    return 0;
}
