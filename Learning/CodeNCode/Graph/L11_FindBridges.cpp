#include<iostream>
#include<vector>

using namespace std;

vector<int> adj[101];
int vis[101];
int in[101];
int low[101];
int timer =0;

void dfs(int node , int par)
{
    vis[node] = 1;
    in[node] = low[node] =++timer;
    for(int i=0;i<adj[node].size();i++)
    {
        int child = adj[node][i];
        if(child == par)
            continue;
        if(vis[child])
        {
            low[node] = min(low[node],in[child]);
        }
        else
        {
            dfs(child ,node);
            if(in[node]<low[child])
                cout << node << " " << child << endl;
            low[node] = min(low[node] , low[child]);
        }
    }
}

int main()
{
    int n ,m;
    cin >> n >> m;
    while(m--)
    {
        ///examples taken from gfg
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "cut edges are : " << endl;
    dfs(1,-1);
    return 0;
}
