/**
gfg.practice - Dijkstras implementation

    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        bool vis[V] = {false};
        vector<int> dist(V,INT_MAX-1);
        dist[S] = 0;

        PARENT[S] = -1 ; ///NOT PART OF GFG CODE . jUST FOR REFERENCE FOR PRINTING PATH

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,S});
        while(!pq.empty())
        {
            int par = pq.top().second;
            int par_d = pq.top().first;
            pq.pop();
            vis[par] = true;
            for(auto i:adj[par])
            {
                int neigh = i[0];
                int neigh_w = i[1];
                if(vis[neigh] == false && par_d + neigh_w < dist[neigh] )
                {
                    pq.push({par_d + neigh_w , neigh});
                    dist[neigh] = par_d + neigh_w;
                    PARENT[NEIGH] = PAR;
                }
            }
        }
        return dist;
    }


    //PATH PRINTING ALGORITHM
    printpath(int parent[] ,int node)
    {
        if(parent[node] == -1)
            return ;
        printpath(parent, parent[node])
        cout << node << " ";
    }

*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You" << endl;
    return 0;
}
