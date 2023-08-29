/**
->Cycle detection using bfs : since toposort work on Directed Acyclic Graph . So if cycle is
present then toposort can't be founded
    if(answer.size() != number of nodes)
        toposort was not found because of cycle.

    int indegree[100001];
	void indeg(int &n , vector<int> adj[])
	{
	    for(int i=0;i<n;i++)
	    {
	        for(auto j:adj[i])
	            indegree[j]++;
	    }
	}
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        for(int i=0;i<V;i++)
            indegree[i] = 0;
        indeg(V,adj);
	    queue<int> q;
	    for(int i=0;i<V;i++)
	        if(indegree[i] == 0)
                q.push(i);
        vector<int> sol;
        while(!q.empty())
        {
            int par = q.front();
            q.pop();
            sol.push_back(par);
            for(auto i:adj[par])
            {
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }
        if(sol.size() != V)
            return true;
        return false;
    }
*/

#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You" << endl;
    return 0;
}

