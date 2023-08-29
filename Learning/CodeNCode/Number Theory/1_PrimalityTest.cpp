//-> naive approach of Primality test : O(n) time
//-> Optimized approach : O(root(n)) time
///Also try primality test - codechef
#include<iostream>

using namespace std;

bool Naive(int n)
{
    if(n == 1)
        return false;

    for(int i=2;i<n;i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

bool Optimized(int n)
{
    if(n == 1)
        return false;

    for(int i=2;i*i<=n;i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    Naive(n) ? cout << "Prime" << endl : cout << "Not Prime" << endl;
    Optimized(n) ? cout << "Prime" << endl : cout << "Not Prime" << endl;
    return 0;
}
