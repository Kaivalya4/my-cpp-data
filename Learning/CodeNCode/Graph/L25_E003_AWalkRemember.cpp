///A walk to remember - hackerearth
/*
5 5
1 2
2 3
3 4
4 5
4 2

*/
#include<bits/stdc++.h>

using namespace std;

vector<int> adj[100001];
vector<int> tra[100001];
vector<int> tempans;
unordered_map<int , int> umap;
vector<int> Outnode;
int vis[100001];

void dfs(int node)
{
    vis[node] =1;

    for(int child : adj[node])
    {
        if(vis[child] == 0)
            dfs(child);
    }
    Outnode.push_back(node);
}

void dfs1(int node)
{
    vis[node] =1;

    for(int child : tra[node])
    {
        if(vis[child] == 0)
            dfs1(child);
    }
    tempans.push_back(node);
}

int main()
{
    int n,m;
    cin >> n >>m;
    while(m--)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        tra[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        umap[i] =1;
        if(vis[i] == 0)
            dfs(i);
    }
    for(int i=1;i<=n;i++)
        vis[i] =0;
    /*for(auto i:Outnode)
        cout << i << " ";
    cout << endl;*/
    for(int i=n-1;i>=0;i--)
    {
        int val = Outnode[i];
        if(vis[val] == 0)
        {
            tempans.clear();
            dfs1(val);
            if((tempans.size() )<2)
            {
                umap[val] = 0;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout << umap[i] << " ";
    }
    return 0;
}
