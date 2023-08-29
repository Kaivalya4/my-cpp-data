/**
O(logn) per query using sparse table
*/
/**
8
1
1 2
1 3
2 4
2 5
2 6
3 7
3 8
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> adj[100];
int level[100];
int st[101][101];
int logs[100];


void LogArray(int n )
{
    logs[1] = 0;
    for(int i=2;i<=n;i++)    ///log[i] = largest power of 2 which is less than i.
        logs[i] = logs[i/2] +1;
}

void dfs(int root , int lev , int par)
{
    st[0][root] = par;
    level[root] = lev;
    for(auto i:adj[root])
    {
        if(i != par){

            dfs(i , lev+1,root);
        }
    }
}

void precompute(int n )
{
    for(int i=1;i<=logs[n];i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(st[i-1][j] != -1)
            {
                int par = st[i-1][j];
                st[i][j] = st[i-1][par];
            }
        }
    }
}

int LCA(int u , int v)
{
    if(level[u] > level[v])
        swap(u,v);
    int d = level[v] - level[u];
    while(d>0)
    {
        v = st[logs[d]][v];
        d  = level[v] - level[u];
    }
    if(u == v)
        return u;
    for(int i=logs[v];i>=0;i--)
    {
        if(st[i][u] != -1 && st[i][u] != st[i][v])
            u = st[i][u] , v= st[i][v];
    }
    return st[0][u];
}

int main()
{
    int n , root;
    cin >> n  >> root;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    LogArray(n);
    dfs(root,0,-1);

    precompute(n);

    int q;
    cin >> q;
    while(q--)
    {
        int u,v;
        cin>> u >> v;
        cout << LCA(u,v) << endl;
    }
}


