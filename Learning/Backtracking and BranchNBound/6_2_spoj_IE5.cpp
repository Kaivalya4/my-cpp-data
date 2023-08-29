///Not easy -<:) couldn't able to solve it using backtracking algorithm. I think some mathematics is here
#include<bits/stdc++.h>

using namespace std;

/*
freopen(".txt","r",stdin);
freopen(".txt","w",stdout);
*/

///void LogArray(int );
///void SparseTable(int arr[] , int );
///void PrimeFactorization(int );
///int expo(int  , int  , int );

/***** variable and function area *******/

int graph[301][301];
int ans = 0;

void solve(int n , vector<int> path , unordered_map<int,bool> umap)
{
    if(path.size() == n)
    {
        if(graph[path.back()][1])
            ans++;
        return ;
    }
    int src = path.back();
    for(int i=2;i<=n;i++)
    {
        if(umap[i] == false && graph[src][i] == 1)
        {
            path.push_back(i);
            umap[i] = true;
            solve(n,path,umap);
            path.pop_back();
            umap[i] = false;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    int itr = 0;
    while(t--)
    {
        ans = 0;
        int n , k;
        cin >> n >> k;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                graph[i][j] = 1;
                graph[j][i] =1;
                if(i == j)
                    graph[i][j] = 0;
            }
        }
        for(int i=1;i<=k;i++)
        {
            int a,b;
            cin >> a >> b;
            graph[a][b] = 0;
            graph[b][a] = 0;
        }
        unordered_map<int, bool> umap;
        vector<int> path;
        path.push_back(1);
        umap[1] =true;
        solve(n , path , umap);
        cout << "Case #" << ++itr << ": " <<  (ans/2)%9901 << endl;
    }
    return 0;
}



/****************   SPARSE TABLE    *******/
/*
void LogArray(int n )
{
    logs[1] = 0;
    for(int i=2;i<=n;i++)    ///log[i] = largest power of 2 which is less than i.
        logs[i] = logs[i/2] +1;
}

void SparseTable(int arr[] , int n)
{
    ///first row i.e. length of pow(2,0) = 1 starting form index j.
    for(int j=0;j<n;j++)
        st[0][j] = arr[j];

    for(int i=1;i<=logs[n];i++)
    {
        for(int j=0;(j+(1<<i))<=n;j++)
        {
            st[i][j] = min(st[i-1][j] , st[i-1][j+(1<<i -1)]);
        }
    }
}
*/
/********************** - **********/

/******************PRIME FACTORIZATION*****/
/*
void PrimeFactorization(int n)
{
    for(int i=2 ; i*i<=n ;i++)
    {
        if(n%i == 0)
        {
            int cnt =0;
            while(n %i == 0)
            {
                cnt++;
                n= n/i;
            }
            cout << i << "^" << cnt << " ";
        }
    }
}
*/
/************** - ************************/

/************* Binary Exponentiation ************************/
/*
int expo(int x ,int y , int mod)
{
    int res = 1;
    while(y !=0)
    {
        if(y%2)
        {
            y--;
            res = (res * x) %mod;
        }
        y /= 2;
        x = (x * x) %mod;
    }
    return res;
}
*/
/******************* - *******************************/

