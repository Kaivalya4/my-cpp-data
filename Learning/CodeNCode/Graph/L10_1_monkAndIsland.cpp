#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> adjlist[10001];
int dist[10001];
int vis[100001];

void dfs(int curr)
{
    vis[curr]= 1;
    dist[curr] = 0;
    queue<int> q;
    while(!q.empty())
    {
        int base = q.front();
        q.pop();
        for(int i=0 ; i<adjlist[base].size() ; i++)
        {
            int child = adjlist[base][i];
            if(vis[child] == 0 )
            {
                q.push(child);
                dist[child] = dist[base] + 1;
                vis[child] = 1;
            }
        }
    }
}

int main()
{
    int n , m , t , a, b;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i=0 ; i<n ; i++)
        {
            adjlist[i].empty();
            vis[i] = 0;
            dist[i] = 0;
        }
        for(int i=0 ; i<m ;i++)
        {
            cin >> a >> b;
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }
        for(int i=1 ; i<=n ; i++)
        {
            if(vis[i] == 0)
            {
                dfs(i);
            }
        }
        cout << dist[n] << endl;
    }
}
