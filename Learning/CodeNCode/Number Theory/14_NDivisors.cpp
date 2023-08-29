/**
Alternate question for total number of divsors of n -
Find total number of n divisors between A and B (both included) . N-DIVISORS: whose total number of divisors are n

int calc(int num , int &n )
    {
        if(num == 1){
            if(n == 1)
                return 1;
            return 0;
        }
        int sum = 1;
        for(int i=2;i*i<=num;i++){
            if(num%i == 0){
                int ctr =0;
                while(num%i==0){
                    ctr++;
                    num /=i ;
                }
                sum = sum * (ctr+1);
            }
        }
        if(num>1)
            sum *= 2;
        if(sum == n)
            return 1;
        return 0;
    }
    int count(int a,int b,int n){
        // code here
        int ans =0;
        for(int i=a;i<=b;i++){
            ans +=calc(i,n);
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
