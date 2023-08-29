/**
Find largest subarrray with gcd =1 . This problem itself is not about queries, but Sparse Table is still
useful here.

Let’s start with some observations:
1. Let g = gcd(x, y), f = gcd(x, y, z). Then f ≤ g, because f = gcd(g, z),
    and greatest common divisor of two integers can not be greater than any of them;
2. If we fix L and compute values xL = gcd(ArrL), xL + 1 = gcd(ArrL, ArrL + 1), …, xN - 1 = gcd(ArrL, ArrL + 1, …, ArrN - 1),
    then we have xL ≥ xL + 1 ≥ … ≥ xN - 1 (it follows from the above point).

  Steps -
-> Firstly, we set R = L;

-> Then for i=k..0 we decide whether we need to move R further by 2i units;

-> Why would we need to move it at all? Since we are ultimately looking for R to
   satisfy gcd(ArrL, ArrL + 1, …, ArrR) = 1, we are not interested if that gcd is greater than 1

-> And if the latter is the case, i.e. we found out that
    gcd(ArrL, ArrL + 1, …, ArrR, ArrR + 1, …, ArrR + 2i - 1) > 1, then we need to increase R by 2i,
    because gcd(ArrL, ArrL + 1, …, ArrR) > 1 for sure (remember, we have monotonous function).
     After that addition we continue to loop further. In the end we will obtain the desired R;
            This will work in O(log(N)) for fixed L, getting us to O(N * log(N)) solution in total.

*/
#include<iostream>
#include<algorithm>

using namespace std;

int arr[100001];
int logs[100001];
int dp[32][100001];

void LogArray(int n)
{
    logs[1] = 0;
    for(int i=2;i<=n;i++)
    {
        logs[i] = logs[i/2] + 1;
    }
}

void SparseTable(int arr[] , int n)
{
    for(int i=0;i<n;i++)
        dp[0][i] = arr[i];

    for(int i=1;i<=logs[n] ;i++)
    {
        for(int j=0;j<=n -(1<<i) ; j++)
        {
            dp[i][j] = __gcd(dp[i-1][j] , dp[i-1][j+1<<(i-1)]);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];

    LogArray(n);
    SparseTable(arr , n);
    int answer = 0;

    /**
    cout << logs[n] << endl;
    for(int i=0;i<=logs[n];i++){
        for(int j=0;j<n;j++)
            cout << dp[i][j] << " ";
        cout<< endl;
    }
*/

    for(int j=0;j<n;j++)
    {
        int r = j;

        int g =0;

        for(int i=logs[n] ; i>=0; i--)
        {
            if(r + (1<<i) -1 >=n)
                continue;

            if(__gcd(g , dp[i][r]) >1)
            {
                g = __gcd(g , dp[i][r]);
                r += 1<<i;
            }
        }

        answer += n - r;
    }
    cout << "number of subarrays with gcd equal 1 is : " << answer ;
    return 0;
}
