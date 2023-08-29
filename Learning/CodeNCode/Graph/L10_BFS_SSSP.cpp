#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int vis[10] = {0};
int dis[10] = {0};
vector<int> adjlist[11];
queue<int> q;

void sssp(int src , int dist)
{
    vis[src] = 1;
    dis[src] = dist;
    q.push(src);
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        for(int i=0 ; i<adjlist[front].size() ; i++)
        {
            int adj = adjlist[front][i];
            if(vis[adj] == 0)
            {
                q.push(adj);
                vis[adj] = 1;
                dis[adj] = dis[front] + 1;
            }
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
    cout << "Enter one connection in pairs at a time : ";
    int a , b;
    while(m--)
    {
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    cout << "Enter source : " ;
    int src;
    cin>> src;
    sssp(src , 0);
    for(int i=1 ; i<=n ; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }
}