//side note - In a connected component of without any loop and cycle i.e. a tree has one edge less than number
// of nodes
#include<iostream>
#include<vector>

using namespace std;

void dfs(int n , vector<int>&vis , vector<int> adj[])
{
    vis[n] = 1;
    cout << n << " ";
    for(int i=0 ; i<adj[n].size() ; i++)
    {
        int next = adj[n][i];
        if(vis[next] == 0)
        {
            dfs(next , vis , adj);
        }
    }
}

int main()
{
    int n , m;
    cout << "Enter number of nodes : " ;
    cin >> n;
    cout << "Enter number of edges : ";
    cin >> m;
    vector<int> adj[n+1] ;
    cout << "Enter one connection in pairs at a time : ";
    int a , b;
    while(m--)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
   //creating a visited array
    vector<int> vis;
    for(int i = 0 ; i<=n ; i++)
    {
        vis.push_back(0);
    }
    int count = 0;
    for(int i=1 ; i<=n ; i++)
    {
        if(vis[i] == 0)
        {
            dfs(i , vis , adj);
            count++;
        }
    }
    cout<< endl << "Total number of connected components in graph are : " << count;
}
