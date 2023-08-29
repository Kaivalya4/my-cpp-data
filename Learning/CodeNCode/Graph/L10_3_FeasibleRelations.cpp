///Hackerearth
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<int> adj[1000001];
int vis[1000001];
int ConnectedComp[1000001];
int counts = 0;

void dfs(int n )
{
    vis[n] = 1;
    ConnectedComp[n] = counts; ///storing that nodes lie in which connected components
    for(int i=0;i<adj[n].size();i++)
    {
        int child = adj[n][i];
        if(vis[child] == 0)
            dfs(child);
    }
}

int main()
{
    ///below two lines for fast io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n , k , a ,b;
        vector<pair<int,int>> noReln;
        string oper;
        cin >> n >> k;
        for(int i=0;i<=n;i++)
        {
            vis[i] =0;
            ConnectedComp[i] = 0;
            adj[i].clear();
        }
        for(int i=0;i<k;i++)
        {
            cin >> a >> oper >> b;
            if(oper == "=")
            {
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
            else
                noReln.push_back(make_pair(a,b));
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i] == 0)
            {
                counts++;
                dfs(i);
            }
        }
        int flag = 0;
        for(auto i:noReln)
        {
            int x,y;
            x= i.first;
            y = i.second;
            if(ConnectedComp[x] == ConnectedComp[y])
            {
                cout << "NO" << endl;
                flag =1;
                break;
            }
        }
        if(flag == 0)
            cout << "YES" << endl;
    }
    return 0;
}
