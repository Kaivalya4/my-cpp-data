///L16 - spoj problem and 17  a theory
#include<iostream>
#include<string.h>

using namespace std;

int n , m; // row , column

int grid[10][10];
int vis[10][10];

int dx[] = {-1,1,0,0,};
int dy[] = {0,0,1,-1};

bool isValid(int x , int y)
{
    if(x<0 || x >=n || y <0 || y >=m)
        return false;
    if(vis[x][y] == true || grid[x][y] == -1)
        return false;
    return true;

}

void dfs(int x , int y)
{
    vis[x][y] = 1;
    cout << grid[x][y] << " ";
    for(int i=0;i<4;i++)
    {
        if(isValid(x+dx[i],y+dy[i]))
            dfs(x+dx[i] , y+dy[i]);
    }
}

int main()
{
    cin >> n >> m;
    memset(grid,-1,sizeof(int)*100);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin >> grid[i][j];
    }
    dfs(0,0); ///assuming only one connected component
    return 0;
}
