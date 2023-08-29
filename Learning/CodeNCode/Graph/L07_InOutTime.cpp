/**Given a tree . Given 2 nodes in each query , find wether one node lies in the subtree of other node.
-> We will use concept of In & Out time of node.

7 6
1 2
2 3
3 5
2 4
4 6
4 7

*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> adj[100];
int vis[100];
int In[100];
int Out[100];
int timer = 1;

void dfs(int n)
{
    vis[n] = 1;
    In[n] = timer++;
    for(int i=0;i<adj[n].size() ; i++)
    {
        int child = adj[n][i];
        if(vis[child] == 0)
        {
            dfs(child);
        }
    }
    Out[n] = timer++;
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
    int x , y;
    cin >> x >> y;
    dfs(1);
    cout << In[x] << " " << Out[x] << endl ;
    cout << In[y] << " " << Out[y] << endl;
    if( ((In[x] < In[y])&& (Out[y] < Out[x]))  || ((In[y] < In[x])&& (Out[x] < Out[y])) )
        cout << "Yes one lie in subtree of other";
    else
        cout << "No one  lie in subtree of other";
    return 0;
}
