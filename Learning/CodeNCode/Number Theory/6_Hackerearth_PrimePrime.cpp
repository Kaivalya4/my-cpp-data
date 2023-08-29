#include<iostream>

using namespace std;

int arr[1000001];
int primecheck[1000001];
void sieve()
{
    int n = 1000000;
    arr[0] = arr[1] =0;
    for(int i=2;i<=n;i++)
        arr[i] =1;
    for(int i=2;i*i<=n;i++)
    {
        if(arr[i] ==1)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                arr[j] = 0;
            }
        }
    }
    primecheck[0] = primecheck[1] =0;
    int ctr =0;  //counter to store prime numbers upto a given number i starting from 1.
    for(int i=2;i<=n;i++)
    {
        if(arr[i] == 1)  //whenever we find a prime we increment counter . ctr store number of prime upto i
            ctr++;
        if(arr[ctr] == 1)  //if count of prime is prime upto that i then we mark that number as prime prime
            primecheck[i] = 1;
        else
            primecheck[i] = 0;
    }
    for(int i=2;i<=n ;i++)
    {
        primecheck[i] = primecheck[i] + primecheck[i-1];  //finally we find prefix sum .
    }
}
int main()
{
    sieve();
    int t;
    cin >> t;
    while(t--)
    {
        int l,r;
        cin >> l >> r;
        cout << primecheck[r]- primecheck[l-1] << endl;
    }
    return 0;
}
