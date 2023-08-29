///Berttown Road - Codeforces Problem
#include<iostream>
#include<vector>

using namespace std;

vector<int> adj[100001];
int vis[100001];
int in[100001];
int low[100001];
int timer;
bool hasBridge;
vector<pair<int,int>> ans;

void dfs(int node, int par)
{
    vis[node] = 1;
    in[node] = low[node] = ++timer;
    for(int i=0;i<adj[node].size();i++)
    {
        int child = adj[node][i];
        if(child == par)
            continue;
        if(vis[child])
        {
            low[node] = min(low[node] , in[child]);
            if(in[node] > in[child])
                ans.push_back(make_pair(node,child));
        }
        else
        {
            dfs(child,node);
            if(in[node] < low[child])
                {
                    hasBridge = true;
                    return ;
                }
            low[node] = min(low[node] , low[child]);
            ans.push_back(make_pair(node,child));
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
    dfs(1,-1);
    if(hasBridge == true)
        cout << 0 << endl;
    else{
    for(auto i:ans)
    {
        cout << i.first << " " << i.second << endl;
    } }
    return 0;
}
