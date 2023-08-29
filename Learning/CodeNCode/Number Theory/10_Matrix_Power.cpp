///spoj - mpow -> matrix exponentiation

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
long long mat[50][50];
long long I[50][50];

void mul(long long A[][50] , long long B[][50] , long long &m)
{
    int res[m][m] ;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            res[i][j] = 0;
            for(int k=0;k<m;k++)
            {
                res[i][j] = (res[i][j]%mod +  (A[i][k] * B[k][j])%mod)%mod;

            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
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
        long long m,n;
        cin >> m>>n;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin >> mat[i][j];
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                I[i][j] = 0;
                if(i == j)
                    I[i][j] = 1;
            }
        }
        while(n)
        {
            if(n%2)
                mul(I,mat,m) , n--;
            mul(mat,mat,m) , n/=2;
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout << I[i][j] << " ";
            }
            cout << endl;
        }
    }
}
