///Program to check wether a graph is 2 colorable or not

//Important Points -
///if graph contains cycle of odd length then graph in not bipartite
///graph with no edges(i.e. all nodes are disconnected ) are bipartite

#include<iostream>
#include<vector>

using namespace std;

vector<int> adj[100];
int vis[100];
int color[100];

bool dfs(int n , int col)
{
    vis[n] = 1;
    color[n]  = col;
    for(int i=0;i<adj[n].size();i++)
    {
        int child = adj[n][i];
        if(vis[child] == 0)
        {
            if(dfs(child ,col^1 ) == false)
                return false;
        }
        else
        {
            if(col == color[child])
                return false;
        }
    }
    return true;
}

int main()
{
    int n ,m;
    cin >> n >> m;
    while(m--)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1 , 1) ? cout << "Possible" : cout << "Not Possible";  //assuming that only one connected component is given
    return 0;
}
