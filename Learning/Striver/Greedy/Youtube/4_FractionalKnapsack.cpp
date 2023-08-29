/**
Fractional Knapsack - gfg.practise

brute - try all possible combination
optimize - using greedy - O(nlogn) time
struct Item{
    int value;
    int weight;
};



class Solution
{
    public:
    static bool comp(Item a, Item b)
    {
        double a1 = (double)a.value / (double)a.weight;
        double b1 = (double)b.value / (double)b.weight;
        return a1>b1;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr , arr+n , comp);
        double ans = 0;
        for(int i=0;i<n;i++)
        {
            if(W - arr[i].weight >=0)
            {
                W -= arr[i].weight;
                ans += arr[i].value;
            }
            else
            {
                double brokevalue = (double)arr[i].value/(double)arr[i].weight * W;
                W -= W;
                ans += brokevalue;
            }
        }
        return ans;
    }

*/
#include<iostream>

using namespace std;

int main()
{
    cout << "thank you";
    return 0;
}
