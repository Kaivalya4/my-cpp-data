#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int par[1001];
int R[1001];

vector<pair<int  ,int >> cycle;

void makePar(int n)
{
    for(int i=1;i<=n;i++)
    {
        par[i] = i;
        R[i] = 1;
    }
}

int finds(int a)
{
    if(par[a] == a)
        return a;
    return par[a] = finds(par[a]);
}

void unions(int a ,int b)
{
    int x = a , y =b;
    a = finds(a);
    b = finds(b);

    if(a == b)
        cycle.push_back(make_pair(x,y));
    else
    {
        if(R[a] > R[b])
        {
            R[a] += R[b];
            par[b] = a;
        }
        else{
            R[b] += R[a];
            par[a] = b;
        }
    }
}

int main()
{
    vector<pair<int ,int>> ans;
    int n;
    cin >> n;
    int m = n-1;
    makePar(n);
    while(m--)
    {
        int u,v;
        cin >> u >> v;
        unions(u,v);
    }
    for(int i=2;i<=n;i++)
    {
        int baap = finds(1);
        int x = finds(i);
        if(x != baap){
            ans.push_back(make_pair(baap,x));
            unions(baap , x);
        }
    }
    int counts =ans.size();
    cout << counts << endl;
    for(int i=0;i<ans.size() ;i++)
    {
        cout <<  cycle[i].first << " " << cycle[i].second << " " << ans[i].first  << " ";
        cout << ans[i].second << endl;
    }
    return 0;
}
