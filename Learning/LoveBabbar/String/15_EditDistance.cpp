/**
gfg.practice - edit distance

I have followed 0 based indexing in the below explanation

We write recursive solution just like lcs.
->if characters matches : (n-1,m-1)    ---(*)
->if characters not matches :

    ->we insert : a= geek ,b = gesek . "ek" matches
        a=ge , b =ges
        n=1  , m=2
        Think like that we inserted 's' in a : ges . 's' of a mathces with 's' of b .
        So we leave it as it is(*) . Hence after m-1 we get
        a=ge , b=ge

        => insert : (n,m-1)

    ->we remove : a=gesek , b=geek . "ek" matches .we leave them as it is(just like *)
        now , a=ges , b=ge
              n=2 ,   m=1
        Think like that we deleted 's' in a . hence after n-1 we get
            a=ge , b=ge

        =>remove : (n-1,m)

    ->we replace : abkde , abcde . "de" matches . we leave them as it is(just like *)
        now , a=abk , b=abc
        We replace 'k' with 'c' in a . "c" mathces in both . Hence from (*) after doing n-1,m-1 we get
            a="ab",b="ab"
        =>replace : (n-1,m-1)

    int t[101][101];

    int solve(string &a , string &b,int n , int m )
    {
        if(n <0)
        {
            return m<0 ? 0 : m+1;
        }
        if(m<0)
            return n<0 ? 0 : n+1;
        if(t[n][m] != -1)
            return t[n][m];
        if(a[n] == b[m])
            return t[n][m] = solve(a , b , n-1 , m-1);
        else{
            int ans1 = solve(a,b,n,m-1) +1; ///insert
            int ans2 = solve(a,b,n-1,m) +1; ///delete
            int ans3 = solve(a ,b ,n-1 , m-1) +1; ///replace
            ans1 =  min(ans1 , ans2);
            return t[n][m] = min(ans1 , ans3);
        }
    }
    int editDistance(string a, string b) {
        // Code here
        memset(t , -1 , sizeof(t));
        int n = a.length();
        int m = b.length();
        return solve(a ,b , n-1,m-1 );
    }
*/

#include<iostream>

using namespace std;

int main()
{
    cout << "Thank you" << endl;
    return 0;
}

