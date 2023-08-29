#include<bits/stdc++.h>

using namespace std;

/*
freopen(".txt","r",stdin);
freopen(".txt","w",stdout);
*/

/**
use fixed flag for correct decimal place with setprecision
cout << fixed << setprecision;

sort comparator must return false when arguments are equal.

FAST IO
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

///void LogArray(int );
///void SparseTable(int arr[] , int );
///void PrimeFactorization(int );
///int expo(int  , int  , int );

/***** variable and function area *******/

bool vis[1001][1001];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
char dxy[] = {'U' , 'R' , 'D' , 'L'};
int dp[1001][1001];
int n , m;
string ans ;

int dfs(int x , int y , int &ex , int &ey ,string temp , vector<vector<int>>& maps){
    if(x == ex && y == ey){
        if(ans.length() == 0 || ans.length() > temp.length()){
            ans = temp;
            return 1;
        }
        return ;
    }
    vis[x][y] = true;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y +dy[i];
        if( !(nx<0 || ny<0 || nx>=n || ny>=m || vis[nx][ny] || maps[nx][ny] == 0)){
            temp.push_back(dxy[i]);
            dfs(nx,ny,ex,ey,temp,maps);
            temp.pop_back();
        }
    }
    vis[x][y] = false;
}
int main()
{
    cin >> n >> m;
    vector<vector<int>> maps(n,vector<int>(m,0));
    int sx , sy;
    int ex , ey;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin >> c;
            if(c == '.'){
                maps[i][j] = 1;
            }
            else if(c == 'A'){
                maps[i][j] = 1;
                sx = i , sy = j;
            }
            else if(c == 'B'){
                maps[i][j] = 1;
                ex = i , ey = j;
            }
        }
    }
    dfs(sx,sy,ex,ey,n,m,"",maps);
    if(ans.length())
        cout << "YES" << endl  << ans.length() << endl << ans << endl;
    else
        cout << "NO" << endl;
    return 0;
}

/******************Seive of Eratosthenes***************/
/*
bool PrimeArr[1000001];

void SieveOfEratosthenes(int n)
{
    //1 for composite
    PrimeArr[0] = PrimeArr[1] = 1;

    for(int i=2;i*i<=n ;i++)
    {
        if(PrimeArr[i] == 0)
        {
            for(int j=i*i ;j<=n; j+=i)
                PrimeArr[j] =1;
        }
    }
}

*/
/******************-****************************/

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

/**************DSU*************************/
/*

///initially R[i] = 1 for all i .  parent[a] = - 1 or a itself

int finds ( int a ) {
    if ( par[a] == -1 )
        return a ;
    return par[a] = finds(par[a]) ;
}

void unions(int a , int b) ///find(a) , find(b) are passed from calling function
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
*/
/*********************** - ***************************/
