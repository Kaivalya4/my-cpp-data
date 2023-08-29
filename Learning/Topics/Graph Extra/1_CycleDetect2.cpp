/**
Directed graph cycle detection - using dfs
->Use a stack or vector to maintain the recursed element uptil now.
    0->1 , 1->2 , 0->3 , 3->2 .
    First recursion 0->1->2 then  backtrack
    In second recursion vector we will store 0,3 . Now 3->2
    But 2 is not present in recursion vector or stack because it was present in
    different recursion call . So despit 2 was visited earlier it is not a part of cycle.

->Using two colors : 1,2 . 1->recurrence of a particular element is still not completed , its
                                child are in processing state.
                            2->recurrence is completed , all child processed . Backtrack has been
                             done

    int col[100001];
    bool vis[100001];
    bool ans = false; ///cycle not  exist
    void dfs(int node ,vector<int> adj[] )
    {
        col[node] = 1;
        vis[node] = true;
        for(auto i:adj[node])
        {
            if(!vis[i])
            {
                dfs(i,adj);
            }
            else{
                if(col[i] == 1){
                    ans = true;
                    return ;
                }
            }
        }
        col[node] = 2;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        ans = false;
        for(int i=0;i<V;i++)
            vis[i] = false;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj);
                if(ans)
                    return true;
            }
        }

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
