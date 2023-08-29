///L22 is theory . Kosarajus Algo for strongly connected component
/*
5 5
0 2
0 3
1 0
2 1
3 4
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> adj[100];
vector<int> tra[100];
vector<int> nodeOut;
int vis[100];
int aisehi;

void dfs(int node)
{
    vis[node] = 1;
    for(int i=0;i<adj[node].size();i++)
    {
        int child = adj[node][i];
        if(vis[child] == 0)
            dfs(child);
    }
    nodeOut.push_back(node);
}

void dfs1(int node)
{
    vis[node] =1;
    for(int i=0;i<tra[node].size();i++)
    {
        int child = tra[node][i];
        if(vis[child] ==0){
            dfs1(child);
        }
    }
    cout << node << " ";
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
        tra[v].push_back(u);
    }
    for(int i=0;i<n;i++)  //0 based node
    {
        if(vis[i] == 0){
            dfs(i);
        }
    }
    for(int i=0;i<n;i++)
        vis[i] =0;
    for(int i=n-1;i>=0;i--)
    {
        int val = nodeOut[i];
        //cout << val << " ";
        if(vis[val] == 0){
            cout << "In this connected component elements are : " ;
            dfs1(val);
            cout << endl;
        }
    }
    return 0;
}
