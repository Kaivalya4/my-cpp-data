/**
Rebuild - hackerearth
only one test case with runtime error
*/
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

struct edges{
    long long a;
    long long b;
    long  long c;
};

edges arr[100001];
long long par[100001];
long long R[100001];

bool comp(edges x , edges y)
{
    if(x.c > y.c)
        return false;
    if(x.c == y.c)
    {
        if(x.a < y.a)
            return false;
        if(x.a == y.a)
        {
            if(x.b <y.b)
                return false;
        }
    }
    return true;
}

int finds(int a)
{
    if(par[a] == a)
        return a;
    return par[a] = finds(par[a]);
}

void unions(int a, int b)
{
    if(R[a] > R[b])
    {
        par[b] = a;
        R[a] += R[b];
    }
    else{
        par[a] = b;
        R[b] += R[a];
    }
}


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n , m;
        cin >> n >> m;
        long long degree[m] = {0};

        for(int i=0;i<m;i++)
        {
            par[i] = i;
            R[i] = 1;
            cin >> arr[i].a >> arr[i].b >> arr[i].c;
            if(arr[i].a > arr[i].b)
                swap(arr[i].a ,arr[i].b);
        }
        par[m] =m , R[m] = 1;
        sort(arr , arr+m,comp );
        /*for(int i=0;i<m;i++)
        {
            cout << arr[i].a << " " << arr[i].b << endl;
        }*/
        long long ans =0;
        for(int i=0;i<m;i++)
        {
            long long x = arr[i].a;
            long long y = arr[i].b;
            x = finds(x);
            y = finds(y);
            if(x != y)
            {
                unions(x,y);
                ans += arr[i].c;
                degree[arr[i].a]++;
                degree[arr[i].b]++;
            }
        }
        cout << ans << endl;
        for(int i=1;i<=n;i++)
            cout << degree[i] << " ";
        cout << endl;
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
            st[i][j] = min(st[i-1][j] , st[i-1][j+(1<<(i -1))]);
        }
    }
}

//answering query
while(q--){
        int l,r;
        cin >> l >> r;   ///0-based indexing
        int i = logs[r-l+1];
        int ans = min(st[i][l] , st[i][r - (1<<i) +1]);
        cout << ans << endl;
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
