/**
Sum of elements between k1'th and k2'th smallest elements - practise gfg
This question of gfg is rubbish question , where question is not clearly stated.
->if there is no restriction on repeated elements -
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long k1, long long k2)
    {
        // Your code goes here
        priority_queue<long long> pq;
        for(long long i=0;i<N;i++)
        {
            pq.push(A[i]);
            if((long long)pq.size() == k2)
                pq.pop();
        }
        long long sum = 0;
        while((long long)pq.size()>k1)
        {
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};



*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank yOU";
    return 0;
}
