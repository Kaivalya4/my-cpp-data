/**
Job Sequencing - gfg.pracitse
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};


class Solution
{
    public:
    static bool comp(Job a , Job b)
    {
        return a.profit > b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        sort(arr , arr+n , comp);
        int maxi = arr[0].dead;
        for(int i=0;i<n;i++)
        {
            maxi  = max(maxi , arr[i].dead);
        }
        int jobcount = 0;
        int profit = 0;
        int ans[n+1];
        for(int i=0;i<=n;i++)
            ans[i] = -1;
        for(int i=0;i<n;i++)
        {
            int val = arr[i].dead;
            while(ans[val]!=-1 && val>0)
            {
                val --;
            }
           if(val >0)
            {
                profit += arr[i].profit;
                jobcount ++ ;
                ans[val] = arr[i].id;
            }
        }
        vector<int> res;
        res.push_back(jobcount);
        res.push_back(profit);
        return res;

    }
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "thank you";

    return 0;
}
