///A. Arpa�s hard exam and Mehrdad�s naive cheat -> codeforces

#include<bits/stdc++.h>

using namespace std;

/*
freopen(".txt","r",stdin);
freopen(".txt","w",stdout);
*/

/**
use fixed flag for correct decimal place with setprecision
cout << fixed << setprecision;
*/

///void LogArray(int );
///void SparseTable(int arr[] , int );
///void PrimeFactorization(int );
///int expo(int  , int  , int );

/***** variable and function area *******/



int main()
{
    long long n;
    cin >>n;
    if(n == 0)
        cout <<1 << endl;
    else if(n%4 == 1)
        cout << 8 << endl;
    else if(n%4 == 2)
        cout << 4 << endl;
    else if(n%4 == 3)
        cout << 2 << endl;
    else if(n%4 == 0)
        cout << 6 << endl;
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

