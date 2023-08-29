///L22 is theory . This is Tarjans Algo to find SCC
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> adj[100];
int vis[100] , in[100] , low[100];
bool instk[100];
stack<int> stk;
int timer;
int SCC_count;

void dfs(int node)
{
    vis[node] =1;
    in[node] = low[node] = ++timer;
    stk.push(node);
    instk[node] = true;

    for(int i=0;i<adj[node].size();i++)
    {
        int child = adj[node][i];
        if(vis[child] && instk[child])
        {
            low[node] = min(low[node] , in[child]);
        }
        else if(vis[child] == 0)
        {
            dfs(child);
            if(instk[child])
                low[node] = min(low[node] , low[child]);
        }
    }
    if(low[node] == in[node])
    {
        SCC_count ++;
        cout << "nodes in SCC " << SCC_count << " : " ;
        while(1)
        {
            int tops = stk.top();
            stk.pop();
            instk[tops] = false;
            cout << tops << " ";

            if(tops == node)
                break;
        }
        cout << endl;
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
    }
    for(int i=0;i<n;i++)
    {
        if(vis[i] == 0)
            dfs(i);
    }
}
