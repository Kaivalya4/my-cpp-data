/**
Given a and m - find a inverse modulo m
    -> one condition : modulo multiplicative inverse iff
        m != 1 and gcd(a,m) = 1.
method 1 -> O(m) : from 1 to m check for x such that ax congruent 1 (mod m) .
    int gcd(int a, int b)
    {
        if(b ==0)
            return a;
        return gcd(b,a%b);
    }
    int modInverse(int a, int m)
    {

        //Your code here
        if(m == 1)
            return -1;
        if(gcd(a,m) != 1)
            return -1;
        int ans ;
        for(int i=1;i<m;i++){
            if( (a*i) %m == 1){
                ans = i;

                break;
            }
        }
        return ans;
    }

method2 (femat's little theorem) : O(logm) but m must be prime.

method3 (Extended Euclidean Algorithm)
*/

#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You" << endl;
    return 0;
}
