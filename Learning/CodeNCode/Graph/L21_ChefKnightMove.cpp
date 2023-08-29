///two lecture explanation - Codechef poblem => chef knight move

#include<bits/stdc++.h>

using namespace std;

int vis[10][10];
int dis[10][10];

int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};

int xprime , yprime;

bool isValid(int x, int y)
{
    if(x<1 || x>8 || y<1 || y>8)
        return false;
    if(vis[x][y] == true)
        return false;
    return true;
}

int bfs(int x , int y)
{
    vis[x][y] = 1;
    dis[x][y] = 0;
    queue<pair<int , int>> q;
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();

        if(currx == xprime && curry == yprime)
            return dis[currx][curry];

        for(int i=0;i<8;i++)
        {
            if(isValid(currx+dx[i] , curry+dy[i]))
            {
                int nextx = currx+dx[i];
                int nexty = curry+dy[i];

                dis[nextx][nexty] = dis[currx][curry] +1;
                if(nextx == xprime && nexty == yprime)
                    return dis[nextx][nexty];

                q.push(make_pair(nextx,nexty));
            }
        }
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        char a;
        int y;
        cin >> a >> y;
        int x = a - 'a' +1;

        cin >> a >>yprime;
        xprime = a - 'a' +1;

        cout << bfs(x,y) << endl;
    }

    return 0;
}
