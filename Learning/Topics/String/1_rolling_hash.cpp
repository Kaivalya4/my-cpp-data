/**
hash(s) = (s[0]p^(n-1) + .... + s[n-1]p^0 ) % m
*/

#include<bits/stdc++.h>

using namespace std;


int main(){
    string s;
    cin >> s;
    int n = s.length();
    int p = 31;
    int mod = 1000000007;
    vector<int> hs(s.length() , 0);
    for(int i=0;i<n;i++){
        if(i == 0)
            hs[i] = (s[i] - 'a' + 1) % mod;
        else
            hs[i] = (hs[i-1]*p%mod + (s[i] - 'a' + 1)%mod ) %mod;
    }

    cout << "Enter substring index : " ;
    int l ,r;
    cin >> l >> r;
    int val1 = 0;
    ///brute
    for(int i=l;i<=r;i++){
        if(i == 0)
            val1 = (s[i] - 'a' + 1 )%mod;
        else
            val1 = (val1*p%mod + (s[i]-'a'+1)%mod ) %mod;
    }

    ///using precomputed value
    int val2 = (hs[r] - (l == 0 ? 0 : hs[l-1] )*(int)pow(p,r-l+1) %mod ) %mod;

    cout << val1 << " " << val2 << endl;
}
