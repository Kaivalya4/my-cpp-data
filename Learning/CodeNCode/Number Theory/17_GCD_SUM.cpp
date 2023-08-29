/**
Given q queries (<= 10 power 3) . In each query -
Given n: (<= 10 power 5)
find sum of gcd from 1 to n

Method1 : O(q * nlogn) ==> using normal gcd ==> may lead to tle
Methdo2 : O(q * sqrt(n) * (<=sqrt(n)) )  ==> TC <= O(q*sqrt(n))

long long mod = 1000000007;
    long long euler(long long n)
    {
        long long res= n;
        for(long long i=2;i*i<=n;i++)
        {
            if(n %i == 0)
            {
                while(n%i == 0)
                {
                    n /= i;
                }
                res *= (i-1);
                res /= i;
            }
        }
        if(n>1)
        {
            res *= (n-1);
            res /= n;
        }
        return res;
    }

    long long int sumOfGCDofPairs(int N) {
        //complete the function here
        long long sum = 0;
        for(long long i=1; i*i<=N;i++ )
        {
            if(N%i == 0)
            {
                long long int d1 = i;
                long long int d2 = N/i;
                sum += d1 * euler((long long) N/d1);
                sum = sum%mod;
                if(d1 != d2)
                    sum += d2 * euler((long long ) N/d2);
                sum = sum %mod;

            }
        }
        return sum;
    }
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You" << endl;
    return 0;
}

