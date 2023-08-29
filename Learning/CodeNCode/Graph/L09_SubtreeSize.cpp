/**
Given a tree , construct an array subSize[] ,where
subSize[v] stores the size of subtree rooted at node v.
while calculating the number of nodes in the subtree of
a particular node that node will also be added as a node
in subtree hence the number of nodes in subtree of leaves is 1.

->Method1 - DFS and Recursive approach
->Method2 - subSize[v] = (Out[v] - In[v])/2 +1
*/

///Method1
#include<iostream>
#include<vector>

using namespace std;

vector<int> adj[100];
int vis[100];
int subSize[100];

int dfs(int n )
{
    vis[n] = 1;
    int curr_size = 1;
    for(int i=0;i<adj[n].size();i++)
    {
        int child = adj[n][i];
        if(vis[child] == 0)  //this will handle base condition . so in case of leaf node curr_size remain 1 which is returned.
        {
            curr_size +=  dfs(child);
        }
    }
    subSize[n] = curr_size;
    return curr_size;
}

int main()
{
    int n;
    cin >> n;
    int m = n-1;
    while(m--)  //edges are one less than nodes
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(int i=1;i<=n ;i++)
        cout << "subtree size of " << i << "th node is : " << subSize[i] << endl;
    return 0;
}
