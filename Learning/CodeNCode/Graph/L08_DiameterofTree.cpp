/**
-> Diameter of tree is also called width of the tree. Following are the method for undirected tree
    -> given n nodes. Take one node as root at a time and then do dfs . O(n^2) time
    -> do the dfs only 2 times

7 6
1 2
2 3
3 7
2 4
4 5
4 6

L08_1 - couldnt find problem of spoj on other platform . solution of that problem is same to this.
*/

#include<iostream>
#include<vector>

using namespace std;

int maxdist  , oneEndPnt;
vector<int> adj[100];
int vis[100];

void dfs(int n , int dist)
{
    vis[n] = 1;
    if(maxdist < dist)
    {
        maxdist = dist;
        oneEndPnt = n;
    }
    for(int i=0 ;i<adj[n].size() ;i++)
    {
        int child = adj[n][i];
        if(vis[child] == 0)
        {
            dfs(child , dist+1);
        }
    }
}
int main()
{
    int n , m;
    cin >> n >> m;
    while(m--)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    maxdist = -1;
    dfs(1,0) ; //(root , distance from root)

    for(int i=1 ; i<=n ;i++)
        vis[i] = 0;
    dfs(oneEndPnt , 0);

    cout << maxdist ;
    return 0;
}
