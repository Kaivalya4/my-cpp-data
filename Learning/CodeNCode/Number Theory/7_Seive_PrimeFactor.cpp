/**
Task is to use seive for prime factorization . I have taken the problem : Unique Prime Product From gfg and
used seive to solve it. I have optimized the code that I have written in notes.

long long int primeProduct(int n){

///main stuff start
        vector<int> vec(n+1);
        for(int i=1;i<=n;i++)
            vec[i] = i; //Instead of using -1 we can use i. ----This first optimization

            //In video loop was till n .Now due to first optimization we can use till root n only.
        for(int i=2;i*i<=n;i++)
        {
            if(vec[i] == i){
                ///It is guaranteed that below i*i an already smaller prime has occupied the place ---This is second optimaization
                for(int j=i*i;j<=n;j+=i)
                {
                    vec[j] = min(i,vec[j]);
                }
            }
        }
///main stuff end

        int prev = -1;
        long long ans = 1;

        //calculating product of unique prime
        while(true)
        {
            if(vec[n] == n){
                if(prev != vec[n])
                    ans *= n;
                break;
            }
            if(prev != vec[n]){
                ans *= vec[n];
            }
            prev = vec[n] ;
            n /= vec[n];
        }
        return ans;
    }
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank you" << endl;
    return 0;
}

