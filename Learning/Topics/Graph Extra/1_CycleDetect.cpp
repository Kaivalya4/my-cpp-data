/**
cylce detection using BFS - 1) for undirected graph(we use parent array)

    bool vis[100001];
    int parent[100001];
    bool ans = false;
    void bfs(int node , vector<int> adj[])
    {
        queue<int> q;
        vis[node] = true;
        q.push(node);
        parent[node] = -1;
        while(!q.empty())
        {
            int par = q.front();
            q.pop();
            for(auto i:adj[par])
            {
                if(vis[i] && i != parent[par])
                    {
                        ans = true;
                        return ;
                    }
                else if(!vis[i])
                {
                    parent[i] = par;
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        ans = false;
        for(int i=0;i<V;i++)
            vis[i] = false , parent[i] = -1;
        for(int i=0;i<V;i++)
        {
            if(vis[i] == false)
            {
                bfs(i,adj);
                if(ans == true)
                    return ans;
            }
        }
        return ans;
    }
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank you" ;
    return 0;
}
