///We detect cycle in real time

#include<iostream>

using namespace std;

int par[100];
int R[100];

void makePar(int n)
{
    for(int i=0;i<n;i++)
        par[i] = i;
}

int ctr =0;

int finds(int a)
{
    if(par[a] == a)
        return a;
    return par[a] = finds(par[a]);
}

void unions(int a  ,int b)
{
    a = finds(a);
    b = finds(b);

    if(a == b){
        cout << "Cycle " << ++ctr << " found " << endl;
    }
    else
    {
        if(R[a] > R[b]){
            R[a] += R[b];
            par[b] = a;
        }
        else
        {
            R[b] += R[a];
            par[a] = b;
        }
    }
}

int main()
{
    int n , m;
    cin >> n >> m;
    makePar(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        unions(u,v);
    }
    return 0;
}
