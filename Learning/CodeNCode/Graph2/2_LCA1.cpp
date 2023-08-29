/**
Naive Approach - O(n) per query

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
int parent[100];

void dfs(int root , int lev , int par)
{
    //cout << root << " " << lev << " " << par << endl;
    parent[root] = par;
    level[root] = lev;
    for(auto i:adj[root])
    {
        if(i != par){
           // cout << i << endl;
            dfs(i , lev+1,root);
        }
    }
}

int LCA(int a, int b)
{
    if(level[a] > level[b])
        swap(a,b);
    int d = level[b] - level[a];
    while(d >0)
    {
        b = parent[b];
        d--;
    }
    if(a == b)
        return a;
    while(parent[a] != parent[b])
    {
        //cout  << parent[a] <<  " " << parent[b] << endl;
        a =parent[a];
        b= parent[b];
    }
    return parent[a];
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
    /*for(int i=1;i<=n;i++)
    {
        for(auto j:adj[i])
            cout << j << " ";
        cout << endl;
    }*/
    dfs(root,0,-1);
    /*for(int i=1;i<=n;i++)
    {
        cout << i << " " << level[i] << " " << parent[i] << endl;
    }**/
    int q;
    cin >> q;
    while(q--)
    {
        int u,v;
        cin>> u >> v;
        cout << LCA(u,v) << endl;
    }
}
