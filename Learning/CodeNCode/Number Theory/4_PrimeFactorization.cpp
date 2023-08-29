/**
Product of Primes - gfg.practice
Prime Factorization and geek number - gfg.practice
Unique Prime Factors - gfg.practice
*/
#include<iostream>

using namespace std;

//method 1 - brute froce in O(n) time(worst)
void bruteforce(int n)
{
    for(int i=2 ;i<=n ; i++)
    {
        if(n%i == 0)
        {
            int counts =0;
            while(n%i == 0)
            {
                counts++;
                n = n/i;
            }
            cout<< i<<"^" << counts << " ";
        }
    }
}

void Optimized(int n)
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
    if(n>1) ///whatever left is a prime
        cout << n << "^" << 1 << endl;
}
int main()
{
    int n;
    cin >> n;
    bruteforce(n);
    cout << endl;
    Optimized(n);
    return 0;
}
