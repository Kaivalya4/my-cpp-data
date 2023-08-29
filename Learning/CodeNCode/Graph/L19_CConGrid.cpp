///Counting connected components on grid . Grid contains 0and 1 only.
///here edges - up , right , down , left and daigonal

/*
5 5
1 1 0 0 0
0 1 0 0 1
1 0 0 1 1
0 0 0 0 0
1 0 1 0 1
*/
#include<iostream>

using namespace std;

int n ,m;

int grid[10][10];
int vis[10][10];

int dx[] = {-1,1,0,0,-1,-1,1,1};
int dy[] = {0,0,-1,1,-1,1,1,-1};

bool isValid(int x, int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return false;
    if(vis[x][y] == true || grid[x][y] == 0)
        return false;
    return true;
}

void dfs(int x, int y)
{
    vis[x][y] =1;
    for(int i=0;i<9 ;i++)
    {
        if(isValid(x+dx[i] , y+dy[i]))
            dfs(x+dx[i] , y+dy[i]);
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> grid[i][j];
        }
    }
    int counts =0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(isValid(i,j)){
                cout << 1;
                dfs(i,j) ;
                counts++;
            }
        }
    }
    cout << "Number of connected components : " << counts << endl;
    return 0;
}
