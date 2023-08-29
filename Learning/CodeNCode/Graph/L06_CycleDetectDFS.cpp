///Program to detect cycle . (mine - This can also be used to detect cycle for directed graph)

#include<iostream>
#include<vector>

using namespace std;

vector<int> adj[100];
int vis[100];

bool dfs(int n , int parent)
{
    vis[n] = 1;
    for(int i=0; i<adj[n].size() ;i++)
    {
        int child = adj[n][i];
        if(vis[child] == 0)
        {
            if(dfs(child , n) == true)
                return true;
        }
        else
        {
            if(child != parent)
                return true;
        }
    }
    return false;
}

int main()
{
    int n , m;
    cin >> n >> m;
    while(m--)
    {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,1) ? cout << "Cycle is there . " : cout << "cycle is not there.";
    return 0;
}
