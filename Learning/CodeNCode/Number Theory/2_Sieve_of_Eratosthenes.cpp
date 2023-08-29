/**Do gfg practice - seive of eratosthenes*/
#include<iostream>

using namespace std;

int PrimeArr[1001];

void SieveOfEratosthenes(int n)
{
    //0 for composite
    PrimeArr[0] = PrimeArr[1] = 0;
    for(int i=2; i<=n ;i++)
        PrimeArr[i] = -1;

    for(int i=2;i*i<=n ;i++)
    {
        if(PrimeArr[i] == -1)
        {
            for(int j=i*i ;j<=n; j+=i)
                PrimeArr[j] =0;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(PrimeArr[i] == -1)
            cout << i << " ";
    }
}

int main()
{
    int n ;
    cin >> n;
    cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << endl;
    SieveOfEratosthenes(n);
    return 0;
}
