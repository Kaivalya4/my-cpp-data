/**
Given n, q ---> q<=10^5 and n<=10^6 . q is number of queries . In each query we will be given a number x belonging to (1,n).
We have to output phi(x)
Method 1 -> O(q * sqrt(n)) = 10^5  *  10^3 = 10^8 => may lead to tle
Method2 -> Using seive
*/

#include<iostream>

using namespace std;

int seive[1000001];

int main()
{
    for(int i=1;i<=1000000;i++)
    {
        seive[i] = i;
    }
    for(int i=2;i<=1000000;i++)
    {
        ///means i is prime => it will take part in calculation of phi in numbers which are multiples of i.
        if(seive[i] == i)
        {
            for(int j=i;j<=1000000;j+=i)
            {
                seive[j] *= (i-1);
                seive[j] /= i;
            }
        }
    }
    int q;
    cin >>q;
    while(q--)
    {
        int x;
        cin >> x;
        cout << seive[x] << endl;
    }
    return 0;
}

