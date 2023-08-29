///L12 is theory
#include<iostream>
#include<vector>
#include<set>

using namespace std;
vector<int> adj[101];
int vis[101];
int in[101];
int low[101];
int timer ;
set<int> sets;

void dfs(int node , int par)
{
    vis[node] =1;
    in[node] = low[node] = ++timer;
    int children = 0;
    for(int i=0;i<adj[node].size();i++)
    {
        int child = adj[node][i];
        if(child == par)
            continue;
        if(vis[child])
        {
            low[node] = min(low[node],in[child]);
        }
        else{
            dfs(child ,node);
            if(low[child] >= in[node] && par != -1)
                sets.insert(node);
            low[node] = min(low[node],low[child]);
            children++;
        }
    }
    if(par == -1 && children >1)
        sets.insert(node);
}
int main()
{
    int n,m;
    cin >> n >> m;
    while(m--)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1);
    for(auto i:sets)
        cout << i <<" ";
    return 0;
}
