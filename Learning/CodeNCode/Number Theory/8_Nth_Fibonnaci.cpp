/**
See matrix expo code in notes only.

(f0 , f1) * magic = (f1,f2) ==> magic matrix remains same as notes.

gfg.practice --

    long long mod = 1000000007;
    int mat[2][2] = {{0,1},{1,1}};
    void mul(int A[][2] , int B[][2])
    {
        int res[2][2] ;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                res[i][j] = 0;
                for(int k=0;k<2;k++)
                {
                    res[i][j] = (res[i][j]%mod +  (A[i][k]%mod * B[k][j]%mod)%mod)%mod;

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

    int FindNthTerm(long long int n) {
        // Code here
        int I[2][2] = {{1,0},{0,1}};
        if(n==1)
            return 1;
        while(n)
        {
            if(n%2)
                mul(I,mat) , n--;
            mul(mat,mat) , n/=2;
        }
        vector<int> res;
        int arr[2] = {1,1};
        for(int i=0;i<2;i++)
        {
            res.push_back(0);
            for(int k=0;k<2;k++)
            {
                res[i] = (res[i]%mod + (arr[k]%mod * I[k][i]%mod)%mod)%mod;
            }
        }
        return res[0];
    }
*/

#include<iostream>

using namespace std;

int main()
{
    cout << "Thank you";
    return 0;
}
