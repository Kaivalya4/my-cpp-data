/**
normal gfg - Minimum and Maximum values of an expression with * and +
*/

#include<iostream>
#include<string>
#include<cstring>

using namespace std;
///finding maximum value

int t[51][51];

int solve(string str , int i , int j)
{
    if(i==j)
    {
        return (int)(str[j]-'0');
    }
    if(i>j)
        return 0;
    if(t[i][j] != -1)
        return t[i][j];

    int temp = INT_MIN;
    for(int k =i+1; k<=j-1;k+=2)
    {
        int l = solve(str , i , k-1);
        int r = solve(str , k+1 , j);
        cout << l << " " << r << endl;
        if(str[k] == '+')
            temp = max(temp,l+r);
        else
            temp = max(temp , l*r);
    }
    return t[i][j] = temp;
}

int callers(string str)
{
    memset(t,-1,sizeof(t));
    int n = str.length();
    return solve(str , 0 , n-1);
}

int main()
{
    string str = "1+2*3+4*5";
    //string str = "1+2";
    cout << callers(str) << endl ;
    for(int i=0;i<str.length();i++)
    {
        for(int j=0;j<str.length();j++)
        {
            cout << t[i][j] << " " ;
        }
        cout << endl;
    }
    return 0;
}
