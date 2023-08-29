///minimum cost of ropes - gfg practise
/**
More Clear concept behind gready -
If we observe the above problem closely, we can notice that the lengths of the ropes which
are picked first are included more than once in total cost.
Therefore, the idea is to connect the smallest two ropes first and recur for remaining ropes.
This approach is similar to Huffman Coding.
consider - 2,3,4,5,6
 .......
 2+3+4
 2+3

 class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long , vector<long long> , greater<long long>> pq;
        for(int i=0;i<n;i++)
        {
            pq.push(arr[i]);
        }
        long long cost = 0;
        while(pq.size() != 1){
            long long val1 = pq.top();
            pq.pop();
            long long val2  = pq.top();
            pq.pop();
            cost += val1+val2;
            pq.push(val1+val2);
        }
        return cost;
    }
};
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "thank you";
    return 0;
}
