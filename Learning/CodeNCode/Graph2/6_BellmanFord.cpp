/**
gfg.practice :

vector <int> bellman_ford(int V, vector<vector<int>> edges, int S) {
        // Code here
        int parent[V] = {-1};
        int infinity = 100000000;
        vector<int> dist(V , 100000000 );
        dist[S] = 0;
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<edges.size();j++)
            {
                if(dist[edges[j][0]] < infinity)
                {
                    if(dist[edges[j][0]] + edges[j][2] < dist[edges[j][1]])
                    {
                        dist[edges[j][1]] = dist[edges[j][0]] + edges[j][2];
                        parent[edges[j][1]] = edges[j][0];
                    }
                }
            }
        }
        return dist;

    }

To print path we can use parent array . We can print path in both iterative or recursive way. Heres
the iterative way.

        if(dist[dest] == infinity){
            cout << "not rechable" << endl;
            return emtpy_vector;
        }
        vector<int> path;
        for(int i=dest ; i != -1; i = parent[i])
        {
            path.push_back(i);
        }
        reverse(path.begin(),path.end());
        return path;
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You" << endl;
    return 0;
}
