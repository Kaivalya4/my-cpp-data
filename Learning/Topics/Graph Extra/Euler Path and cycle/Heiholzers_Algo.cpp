/**
The code is for undirected graph . for directed graph we need to make seperate in and out degree array.
See valid arrangement of pairs problem on leetcode where I have implemented for directed graphs. Since the constraints are
high I have not used vector in many places.

Considering only the single component system.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>

using namespace std;

///using unordered map to speed up the deletion of edges.
vector<unordered_map<int,int>> adj(15);

/*
6 7
1 2
1 6
2 3
2 5
2 4
3 6
4 5
*/


int main()
{
    int n,m;
    cin >>n >>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u][v] = 1; ///adj[u] = map => map[v] = 1 i.e. u has v as adjacent node.
        adj[v][u]= 1;
    }

    ///to store degree of each node.
    vector<int> deg(n+1,0);
    for(int i=0;i<n;i++){
        deg[i] += adj[i].size();  ///basically size of map
    }

    ///algorithm to check wether all degrees are even or not.
    ///or only 2 vertices can have odd degree
    int v1 = -1 , v2 = -1;
    bool noneuler = false;
    for(int i=0;i<n;i++){
        if(deg[i] & 1){  ///if odd
            if(v1 == -1){
                v1 = i;
            }
            else if(v2 == -1){
                v2 = i;
            }
            else{ ///this conditions excute when v1 , v2 != - 1 => more than 2 odd nodes.
                noneuler = true;
            }
        }
    }

    /**
    ///total number of odd vertices in a graph is even.
    if(v1 != -1){
        ///making an edge between them - to complete a circuit. Later we will remove it.
        adj[v1][v2] = 1;
        adj[v2][v1] = 1;
    }
        */

    ///vector will also work instead of stack to store final solution
    stack<int> cpath; ///temporary solution
    vector<int> epath; ///final euler circuit

    if(v1 != -1)
        cpath.push(v1);
    else{
        cpath.push(1);
    }

    while(!cpath.empty()){
        int u = cpath.top();

        ///no edge remain to be visited.
        if(adj[u].size() == 0){
            epath.push_back(u);
            cpath.pop();
        }
        else{
            int x;
            ///chose any random unvisited edge
            for(auto i:adj[u])
                if(i.second)
                {
                    x = i.first;
                    break;
                }
            adj[u].erase(x);
            adj[x].erase(u);
            cpath.push(x);
        }
    }

    ///if any edge still remain unvisited.
    for(int i=0;i<n;i++)
        if(adj[i].size())
            noneuler = true;

    if(noneuler){
        cout << -1 << endl;
    }
    else{
        for(auto i:epath)
            cout <<i << " ";
        cout << endl;
    }

    return 0;
}
