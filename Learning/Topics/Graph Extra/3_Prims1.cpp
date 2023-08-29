/**
// min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        // push the distance and source node in the queue
        q.push({0,0});

        // to calculate the cost of Mst
        int ans=0;

    // Prim Algo
        while(!q.empty()){

            auto best=q.top();
            q.pop();

            int src=best.second;/// source node
            int weight=best.first;// distance of the source node
            // check for visited nodes
            if(visited[src])continue;
            ans+=weight;
            visited[src]=1;

            for(int i=0;i<n;i++){
                if(visited[i]==0){
                    q.push(make_pair(graph[src][i],i));
                }
            }
        }

        return ans;

*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You" << endl;
    return 0;
}
