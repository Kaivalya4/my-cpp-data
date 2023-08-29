//hackerearths
#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> adj[1001];
int vis[1001] = {0};
int src[1001] = {0};
int dis[1001] = {0};
int id[1001];

void dfs(int src)
{
    vis[src] = 1;
    for(int i=0 ; i<adj[src].size() ; i++)
    {
        int child = adj[src][i];
        if(vis[child] == 0)
        {
            vis[child] = 1;
            dis[child] = dis[src] + 1;
            dfs(child);
        }
    }
}
int main()
{
    int a , b , q;
    cin >> n;
    for(int i=1 ; i<=n-1 ; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >>q;
    for(int i=2 ; i<=n ; i++)
    {
        cin >> id[i];
    }
    dfs(1);
    int mindis = dis[2];
    int minid = id[2];
    for(int i=3 ; i<=n ; i++)
    {
        if(mindis > dis[i])
        {
            mindis = dis[i];
            minid = id[i];
        }
        if(mindis == dis[i])
        {
            if(minid > id[i])
            {
                minid = id[i];
                mindis = dis[i];
            }
        }
    }
    cout << minid;
}
