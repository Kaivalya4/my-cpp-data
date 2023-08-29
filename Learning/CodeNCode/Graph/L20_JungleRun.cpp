#include<iostream>
#include<vector>
#include<queue>

using namespace std;

char jun[30][30];
int n;
int vis[30][30] = {{0} ,{0}};
int dis[30][30] = {{0} , {0}};

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

bool isvalid(int x , int y)
{
    if(x <0 || x>=n || y<0 || y>=n)
        return false;
    if(vis[x][y] == 1 || jun[x][y] == 'T')
        return false;
    return true;
}
void bfs(int startx , int starty)
{
    vis[startx][starty] = 1;
    dis[startx][starty] = 0;
    queue<pair<int , int>> q;
    q.push(make_pair(startx , starty));
    while(!q.empty())
    {
        int parx = q.front().first;
        int pary = q.front().second;
        q.pop();
        for(int i=0 ; i<4 ; i++)
        {
            if(isvalid(parx + dx[i] , pary + dy[i]))
            {
                int childx = parx+dx[i];
                int childy = pary + dy[i];
                q.push(make_pair(childx , childy));
                dis[childx][childy] = dis[parx][pary] + 1;
                vis[childx][childy] = 1;
            }
        }
    }
}
int main()
{
    int startx , starty , endx , endy;
    cin >> n;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ;j++)
        {
            cin >> jun[i][j];
            if(jun[i][j] == 'S')
            {
                startx = i;
                starty = j;
            }
            else if(jun[i][j] == 'E')
            {
                endx = i;
                endy = j;
            }
        }
    }
    bfs(startx , starty);

    cout << dis[endx][endy];
}
