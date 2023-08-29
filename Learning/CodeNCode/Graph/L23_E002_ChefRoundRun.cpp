///Chef and Round Run codechef problem
#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

vector<long> adj[1000001];
vector<long> tra[1000001];
vector<int> tempans;
vector<int> nodeOut;
long arr[1000001];
int vis[1000001];

void dfs(int node)
{
    vis[node] =1;
    for(long child : adj[node])
    {
        if(vis[child] == 0)
            dfs(child);
    }
    nodeOut.push_back(node);
}

void dfs1(int node)
{
    vis[node] =1;
    for(long child : tra[node])
    {
        if(vis[child] == 0)
            dfs1(child);
    }
    tempans.push_back(node);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i=0;i<n;i++)
       {
            vis[i] =0;
            cin >> arr[i];
            adj[i].clear();
            tra[i].clear();
       }

        for(int i=0;i<n;i++)
        {
            adj[i].push_back((i+1+arr[i])%n);
            tra[(i+1+arr[i])%n].push_back(i);
        }
        /*for(int i=0;i<n;i++)
        {
            cout << i << "->" ;
            for(int j=0;j<adj[i].size();j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }*/
        nodeOut.clear();
        for(int i=0;i<n;i++)
        {
            if(vis[i] == 0)
                dfs(i);
        }
        for(int i=0;i<n;i++)
            vis[i] =0;
        int ans =0;
        for(int i=n-1;i>=0;i--)
        {
            int val = nodeOut[i];
            if(vis[val] == 0)
            {
                tempans.clear();
                dfs1(val);
                if(tempans.size() == 1 && (tempans[0] != adj[tempans[0]][0]))
                    continue;
                ans += tempans.size();
            }
            tempans.clear();
        }
        cout << ans << endl;
    }
}
