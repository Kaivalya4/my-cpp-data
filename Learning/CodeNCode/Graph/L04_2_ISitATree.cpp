///Is it a tree - codechef problem
#include<bits/stdc++.h>

using namespace std;

vector<int> adj[10001];
int vis[10001];

void dfs(int n)
{
    vis[n] = 1;
    for(int i=0 ;i<adj[n].size() ;i++)
    {
        int child = adj[n][i];
        if(vis[child] ==0)
            dfs(child);
    }
}
int main()
{
    int n , m;
    cin >> n >> m;
    int k = m;
    while(k--)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt = 0;
    for(int i=1 ;i<=n ;i++)
    {
        if(vis[i] == 0)
        {
            dfs(i);
            cnt++;
        }
    }
    if(cnt == 1 && n == m+1)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
