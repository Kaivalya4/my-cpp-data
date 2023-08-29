/**
spoj - TDKPRIME
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

bool isPrime[90000001];
vector<int> primes;

void seive()
{
    int n = 90000000;
    isPrime[0] = isPrime[1] = true;
    for(int i=2;i*i<=n;i++)
    {
        if(!isPrime[i])
        {
            for(int j=i*i;j<=n;j+=i)
                isPrime[j] = true;
        }
    }
    for(int i=2;i<=n;i++)
        if(!isPrime[i])
            primes.push_back(i);
}

int main()
{
    seive();
    int t;
    cin >> t;
    while(t--)
    {
        int k;
        cin >>k;
        cout << primes[k-1] << endl;
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
