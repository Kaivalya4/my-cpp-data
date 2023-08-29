///Reunion of 1's - Hackerearth
#include<iostream>

using namespace std;

int par[100001];
int R[100001];
int mx;

int finds(int a )
{
    if(par[a] < 0)
        return a;
    return par[a] = finds(par[a]);
}

void unions(int a , int b)
{
    a = finds(a);
    b = finds(b);
    if(a != b)
    {
        if(R[a] > R[b])
        {
            R[a] += R[b];
            par[b] = a;
            mx = max(R[a] , mx);
        }
        else{
            R[b] += R[a];
            par[a] = b;
            mx = max(R[b] , mx);
        }
    }
}

int main()
{
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        char ch;
        cin >> ch;
        if(ch == '1')
        {
            par[i] = -1;
            R[i] = 1;
            if(i!=1 && par[i-1] !=0)
            {
                unions(i-1,i);
            }
        }
    }
    while(k--)
    {
        int inp;
        cin >> inp;
        if(inp == 1)
        {
            cout << mx << endl;
        }
        else{
            int x;
            cin >> x;
            if(par[x] == 0)
            {
                par[x] = -1;
                R[x] = 1;
                if(x!=1 && par[x-1] != 0)
                    unions(x,x-1);
                if(x!=n && par[x+1] !=0)
                    unions(x,x+1);
            }
            int p = finds(x);
            mx = max(R[p] , mx);
        }
    }
    return 0;
}
