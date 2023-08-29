///Connected component in a graph poblem - hackerearth
#include<bits/stdc++.h>

using namespace std;

vector<int> adj[1000001];
int vis[1000001];  //global int array by default 0 , bool array false .

void dfs(int n)
{
    vis[n] = 1;
    for(int i=0 ;i<adj[n].size() ; i++)
    {
        int child = adj[n][i];
        if(vis[child] == 0)
            dfs(child);
    }
}
int main()
{
    int n , e;
    cin >> n >> e;
    while(e--)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt =0;
    for(int i=1;i<=n; i++)
    {
        if(vis[i] == 0)
        {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt ;
    return 0;
}
