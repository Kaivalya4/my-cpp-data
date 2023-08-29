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



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n ;
        vector<int> vec;
        bool pos = false;
        bool neg = false;
        bool mark = true;
        for(int i=0;i<n;i++){
            int val;
            cin >> val;
            if(vec.size() > 0 && val < vec.back())
                mark = false;
            vec.push_back(val);
            if(val<0)
                neg = true;
            if(val>0)
                pos=true;
        }
        if(mark){
            cout << 0 << endl;
            continue;
        }
        vector<pair<int ,int>> sol1;
        vector<pair<int,int>> sol2;
        vector<int> temp = vec;
        if(pos){
            for(int i=0;i<n-1;i++){
                if(temp[i] > temp[i+1]){
                    long long maxi = -21;
                    int idx = -1;
                    for(int j=0;j<n;j++){
                        if(maxi < temp[j]){
                            idx = j;
                            maxi = temp[j];
                        }
                    }
                    while(temp[i+1]<temp[i]){
                        temp[i+1] += maxi;
                        sol1.push_back({i+2 , idx+1});
                    }
                }
            }
        }
        if(sol1.size() <=50){
            cout << sol1.size() << endl;
            /*for(auto i:temp){
                cout << i << " ";
            }
            cout << endl;*/
            for(auto i:sol1){
                cout << i.first << " " << i.second << " " << endl;
            }
            continue;
        }
        temp = vec;
        if(neg){
            for(int i=n-1;i>0;i--){
                if(temp[i] < temp[i-1]){
                    long long mins = 21;
                    int idx = -1;
                    for(int j=0;j<n;j++){
                        if(mins> temp[j]){
                            idx = j;
                            mins = temp[j];
                        }
                    }
                    while(temp[i-1]>temp[i]){
                        temp[i-1] += mins;
                        sol2.push_back({i , idx+1});
                    }
                }
            }
        }

            cout << sol2.size() << endl;
            for(auto i:sol2){
                cout << i.first << " " << i.second << " " << endl ;
            }
            continue;


    }
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
