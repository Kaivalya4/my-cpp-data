/*
6 8
1 2
1 3
2 4
2 5
4 5
4 6
5 6
3 5

*/


#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> adj[100];
int vis[100];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for(int i=0;i<adj[curr].size();i++)
        {
            int child = adj[curr][i];
            if(vis[child] == 0)
            {
                vis[child] = 1;
                q.push(child);
            }
        }
    }
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
    bfs(1) ; ///assuming that there is only one connected components
    return 0;
}
