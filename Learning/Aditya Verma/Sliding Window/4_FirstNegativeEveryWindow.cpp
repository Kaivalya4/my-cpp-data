/**
First Negative in every window of size K - gfgPractise .
Naive solution gives TLE.
Optimized Sliding Window solution -
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
     vector<long long> negatives;
     vector<long long> ans;
     long long  i=0; long long j=0;
     long long k=0;
     while(j<N)
     {
         if(A[j] < 0)
         {
             negatives.push_back(A[j]);
         }
         if(j - i+1 == K)
         {
             ans.push_back(negatives.size() <=k ? 0 : negatives[k]);
             if(A[i] <0)
             {
                 k++;
             }
             i++;
         }
         j++;
     }
     return ans;
 }
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank YOu";

    return 0;
}
