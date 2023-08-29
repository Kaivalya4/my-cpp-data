/**
Leetcode - NQueens .
->Method1 - RECURSION
        bool isValid(vector<string> sol , int i , int j , int n )
    {
        for(int k = 0 ; k<n;k++)
        {
            if(sol[i][k] == 'Q')
                return false;
            if(sol[k][j] == 'Q')
                return false;
            if(i - k >=0 && j - k >=0 &&sol[i-k][j-k] == 'Q')
            {
                return false;
            }
            if(i + k <n && j - k >=0 &&sol[i+k][j-k] == 'Q')
            {
                return false;
            }
            if(i - k >=0 && j + k <n &&sol[i-k][j+k] == 'Q')
            {
                return false;
            }
            if(i + k <n && j + k <n &&sol[i+k][j+k] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
    void solve(int j , int n , vector<string> sol , vector<vector<string>> &ans){
        if(j==n)
        {
            ans.push_back(sol);
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(isValid(sol , i , j , n))
            {
                sol[i][j] = 'Q';
                solve(j+1 , n , sol , ans);
                sol[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> sol;
        string s;///(n,'.'); ///(length , character)
        for(int i=0;i<n;i++)
            s.push_back('.');
        for(int i=0;i<n;i++)
            sol.push_back(s);
        vector<vector<string>> ans;
        solve(0,n,sol,ans);
        return ans;
    }
};

->BITMASKING - reduces time complexity to great extent .  I dont know the solution currently.
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank YOu";
    return 0;
}
