/**
matrix expo of hackerrank : fibonnaci finding
*/
#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>
#include<vector>


using namespace std;

long long mod = 1000000007;


void mul(long long A[][2] , long long B[][2])
{
    int res[2][2] ;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            res[i][j] = 0;
            for(int k=0;k<2;k++)
            {
                res[i][j] = (res[i][j]%mod +  (A[i][k] * B[k][j])%mod)%mod;

            }
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            A[i][j] = res[i][j];
        }
    }
}

int main()
{
    int t;
    cin >>t;
    while(t--){
        long long a,b,n;
        cin >> a >> b >>n;
        long long I[2][2] = {{1,0},{0,1}};
        long long mat[2][2] = {{0,1},{1,1}};
        if(n == 1){
            cout << b << endl;
            continue;
        }
        while(n)
        {
            if(n%2)
                mul(I,mat) , n--;
            mul(mat,mat) , n/=2;
        }
        vector<long long> res;
        long long arr[2] = {a,b};
        for(int i=0;i<2;i++)
        {
            res.push_back(0);
            for(int k=0;k<2;k++)
            {
                res[i] = (res[i]%mod + (arr[k] * I[k][i])%mod)%mod;
            }
        }
        cout << res[0] << endl;
    }
}
