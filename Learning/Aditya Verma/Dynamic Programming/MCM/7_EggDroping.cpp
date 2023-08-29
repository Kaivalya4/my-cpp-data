/**
gfg.pracitce - egg dropping problem => normal for k loop

int t[201][201];

    int solve(int n , int f)
    {
         if(f == 0)
            return 0;
        if(f == 1)
            return 1;
        if(n == 1)
            return f;
        if(t[n][f] != -1)
            return t[n][f];
        int temp = INT_MAX;
        for(int k=1;k<=f;k++)
        {
            temp = min(temp , max(solve(n-1,k-1) , solve(n,f-k)) +1);
        }
        //cout << n << " " << f << " " << temp << endl;
        return t[n][f] = temp;
    }
    int eggDrop(int n, int f)
    {
        memset(t , -1 , sizeof(t));
        return solve(n,f);
        // your code here

    }

leetcode - super egg drop
-> used binary search

int t[101][10001];

    int solve(int n , int f)
    {
         if(f == 0)
            return 0;
        if(f == 1)
            return 1;
        if(n == 1)
            return f;
        if(t[n][f] != -1)
            return t[n][f];
        int temp = INT_MAX;
        int l = 1 , r = f;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int breaks = solve(n-1,mid-1);
            int notbreaks = solve(n , f-mid);

            temp = min(temp , max(breaks,notbreaks)+1);

            if(breaks <notbreaks){
                l = mid+1 ;
            }

            else{
                r = mid-1;
            }
        }
        //cout << n << " " << f << " " << temp << endl;
        return t[n][f] = temp;
    }

    int superEggDrop(int n, int f) {
        memset(t , -1 , sizeof(t));
        return solve(n,f);
    }
*/

#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You" << endl;
    return 0;
}
