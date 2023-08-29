//Single Source Shortest Path. DFS to find SsSp work only on tree
#include<iostream>
#include<vector>

using namespace std;

int vis[10] = {0};
int dis[10] = {0};
vector<int> adjlist[11];

void sssp(int src , int dist)
{
    vis[src] = 1;
    dis[src] = dist;
    for(int i=0 ; i<adjlist[src].size() ; i++)
    {
        int next = adjlist[src][i];
        if(vis[next] == 0)
        {
            sssp(next , dis[src] + 1);
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
    int src;
    cout<<endl <<  "Enter source : " ;
    cin>> src;
    sssp(src , 0);
    for(int i=1 ; i<=n ; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }
    return 0;
}