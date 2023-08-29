/**
gfg.practice

 long long ETF(long long N){
        // code here
        long long ans = N;
        for(long long i=2;i*i<=N;i++)
        {
            if(N%i == 0){
                while(N%i == 0)
                {
                    N/=i;
                }
                ans *= (i-1);
                ans /= i;
            }
        }
        if(N>1){
            ans *= (N-1);
            ans /= N;
        }
        return ans;
    }
*/

#include<iostream>

using namespace std;
int main()
{
    cout << "Thank You" << endl;
    return 0;
}
