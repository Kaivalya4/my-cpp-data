///Fire Escape Routes - Codechef Problem
#include<iostream>
#include<vector>

using namespace std;

vector<int> adj[100001];
int mod = 1000000007;
int vis[100001];
int compsize = 0;

void dfs(int n)
{
    compsize ++;
    vis[n] = 1;
    for(int i=0 ;i<adj[n].size() ;i++)
    {
        int child = adj[n][i];
        if(vis[child] == 0)
        {
            dfs(child);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n , m;
        cin >> n >>m;
        for(int i=0 ;i<=n ;i++)
        {
            adj[i].clear();
            vis[i] = 0;
        }
        while(m--)
        {
            int u , v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int concomp = 0;
        long long res = 1;
        for(int i=1;i<=n ;i++)
        {
            compsize = 0;
            if(vis[i] == 0)
            {
                concomp++;
                dfs(i);
                res = (res *compsize) %mod;
            }
        }
        cout << concomp << " " << res << endl;
    }

    return 0;
}
