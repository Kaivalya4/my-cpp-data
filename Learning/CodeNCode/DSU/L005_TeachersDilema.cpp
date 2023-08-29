///Teacher's Dilemma - Hackerearth
///Solved myself - connected component

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int par[100001];
int mod = 1000000007;

void makePar(int n)
{
    for(int i=1;i<=n;i++)
        par[i] = -1;
}

int finds(int a)
{
    vector<int> vec;
    while(par[a] > 0)
    {
        vec.push_back(a);
        a = par[a];
    }
    for(int i=0;i<vec.size();i++)
    {
        par[vec[i]] = a;
    }
    return a;
}

void unions(int u, int v)
{
    u = finds(u);
    v = finds(v);
    if(u == v)
        return ;
    else
        par[u] = v;
}

int main()
{
    int n , m;
    cin >> n;
    makePar(n);
    cin >>m;
    while(m--)
    {
        int u,v;
        cin >> u >> v;
        unions(u,v);
    }
    unordered_map<int , int> umap;
    for(int i=1;i<=n;i++)
    {
        umap[finds(i)] ++;
    }
    long ans = 1;
    for(auto i:umap)
    {
        ans = (ans * (i.second))%mod;
    }
    cout << ans;
    return 0;
}
