/**
gfg.practice -
class Solution{
    public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    char arr[4] = {'U' , 'D','L','R'};
    bool isPossible(int x , int y , int n,vector<vector<int>> m)
    {
        if(x<0 || y<0 || x>=n || y>=n)
            return false;
        if(m[x][y] == -1 || m[x][y] == 0)
            return false;
        return true;
    }
    void solve(vector<vector<int>> m, int n , int x , int y , string sol , vector<string> &ans)
    {
        if(x == n-1  && y == n-1)
        {
            ans.push_back(sol);
            return;
        }
        for(int i=0;i<4;i++)
        {
            if(isPossible(x+dx[i],y+dy[i],n,m))
            {
                m[x][y] = -m[x][y];
                sol.push_back(arr[i]);
                solve(m,n,x+dx[i],y+dy[i],sol,ans);
                sol.pop_back();
                m[x][y] = -m[x][y];
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0] != 0)
            solve(m , n , 0,0, "", ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You";
    return 0;
}
