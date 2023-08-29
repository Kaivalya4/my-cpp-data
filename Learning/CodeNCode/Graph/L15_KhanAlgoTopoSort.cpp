///L14-theory
///do gfg.practice
///assumning that topsort can be evaluated i.e. input is DAG


/**
int indegree[100001];
	void indeg(int &n , vector<int> adj[])
	{
	    for(int i=0;i<n;i++)
	    {
	        for(auto j:adj[i])
	            indegree[j]++;
	    }
	}
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
	    // code here
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
        return sol;
	}
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> adj[100];
int indeg[100];
vector<int> res;

void khan(int n)
{
    queue<int> q;
    for(int i=0;i<n;i++)
        if(indeg[i] == 0)
            q.push(i);
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        for(int i=0;i<adj[curr].size();i++)
        {
            int next = adj[curr][i];
            indeg[next]--;
            if(indeg[next] == 0)
                q.push(next);
        }
    }
}

int main()
{
    //0 based numbering on gfg
    int n,m;
    cin >> n >> m;
    while(m--)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    khan(n);
    for(int i=0;i<n;i++)
        cout<< res[i] << endl;
    return 0;
}
