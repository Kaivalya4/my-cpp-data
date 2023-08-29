#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

vector<string>grid;

int vis[100][100] = {{0} , {0}};
int dist[100][100] = {{0} , {0}};
int goalx , goaly;
int n;

int dx[] = {-1 , 1 , 0 , 0};
int dy[] = {0,0,-1,1};
bool isValid(int x , int y)
{
    if(x <0 || x >=n || y <0 || y>=n)
        return false;
    if(vis[x][y] ==1 || grid[x][y] == 'X'){
        return false;}
    return true;
}


void bfs(int startx , int starty)
{
    vis[startx][starty] = 1;
    dist[startx][starty] = 0;
    queue<pair<int , int>> q;
    q.push(make_pair(startx , starty));
    while(!q.empty())
    {
        int parx = q.front().first;
        int pary = q.front().second;
        q.pop();
        for(int i=0 ; i<4 ; i++)
        {
            if(isValid(parx + dx[i] , pary+dy[i]))
            {
                int childx = parx+dx[i];
                int childy = pary + dy[i];
                q.push(make_pair(childx , childy));
                dist[childx][childy] = dist[parx][pary] + 1;
                vis[childx][childy] = 1;
            }
        }
    }
}

int main()
{
    cin >> n;
    string str;
    for(int i=0 ; i<n ; i++)
    {
        cin>> str;
        grid.push_back(str);
    }
    int startx , starty;
    cin>> startx >> starty >> goalx >> goaly ;
    bfs(startx , starty);
    cout << dist[goalx][goaly] ;
    return 0;

}
