/**
do gfg.practice - matrix chain multiplication

-> Recursive + memoisation

    int t[101][101];
    int solve(int arr[] , int i , int j)
    {
        if(i>=j)
        {
            return 0;
        }

        if(t[i][j] != -1)
            return t[i][j];

        int tempans = INT_MAX ;
        for(int k=i;k<=j-1;k++)
        {
            int l = solve(arr , i , k);
            int r = solve(arr , k+1,j);

            tempans = min(tempans , (arr[i-1]*arr[j]*arr[k]) +l +r);
        }
        return t[i][j] = tempans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(t , -1 , sizeof(t));
        return  solve(arr , 1 , N-1);
    }

-> Tabulation

int t[101][101];
    int matrixMultiplication(int n, int arr[])
    {
        // code here

        ///(1,1) , (2,2) .... i.e. single matrix
        for(int i=0;i<=n;i++)
            t[i][i] = 0;

        ///suppose index =0 then index +1 = 1 i.e. 0 1
        ///0 1 means two matrix . So 1 => 1 matrix
        ///so length =1 means we considered one matrix
        /// n -1 => n-1 matrix
        for(int len=1; len<=n-1 ;len++)
        {
            ///starting index
            for(int i=1;i<=n-len-1;i++)
            {
                ///ending index
                int j = min(i+len , n-1);  /// if by chance j crosses boundary
                t[i][j] = INT_MAX;

                ///This is simple
                for(int k=i; k<=j-1 ; k++)
                {
                    t[i][j] = min(t[i][j] , t[i][k] + t[k+1][j] + (arr[i-1] * arr[j] * arr[k]) );
                }
            }
        }

        return t[1][n-1];
    }
*/

#include<iostream>

using namespace std;

int main()
{
    cout << "Thank you" ;
    return 0;
}

