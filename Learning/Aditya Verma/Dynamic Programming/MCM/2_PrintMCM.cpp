/**
gfg.practice - brackets in matrix chain multiplication

int bracketPoint[27][27];
    int t[27][27];
    int solve(int arr[] , int i , int j)
    {
        if(i>=j)
        {
            return  0;
        }


        if(t[i][j] != -1)
        {
            return t[i][j] ;
        }

        int tempans = INT_MAX;

        for(int k=i;k<=j-1;k++)
        {
            int l = solve(arr ,i , k);
            int r = solve(arr , k+1 , j);

            int val = l + r+ arr[i-1]* arr[k] * arr[j];

            if(val < tempans){
                tempans = val;
                bracketPoint[i][j] = k;
            }
        }

        return t[i][j] = tempans;
    }


        string ans = "";
    void BracketPrint(int i , int j ,char& c)
    {
        if(i>=j)
        {
            ans.push_back(c++);
            return ;
        }
        else{
            ans.push_back('(');
        }
        BracketPrint( i , bracketPoint[i][j] , c);
        BracketPrint( bracketPoint[i][j]+1 , j , c);
        ans.push_back(')');
    }
    string matrixChainOrder(int p[], int n){
        // code here
        memset(t, -1 , sizeof(t));
        solve(p , 1 , n-1);
        char c = 'A' ;
        BracketPrint(1,n-1,c);

        return ans;
    }
*/
#include<iostream>

using namespace std;

int main()
{
    cout << endl;
    return 0;
}
