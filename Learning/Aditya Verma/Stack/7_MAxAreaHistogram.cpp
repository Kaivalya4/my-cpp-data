/**
Maximum rectangular area in histogram - gfg.practice
->Brute is obvious way using two loop
->Using Stack :
	class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<long long> s;
        vector<int> nsl;
        for(int i=0;i<n;i++)
        {
            if(s.empty())
                nsl.push_back(-1);
            else if(arr[s.top()] >= arr[i]){
                while(!s.empty() && arr[i] <= arr[s.top()]){
                    s.pop();
                }
                if(s.empty())
                    nsl.push_back(-1);
                else
                    nsl.push_back(s.top());
            }
            else
                nsl.push_back(s.top());
            s.push(i);
        }
        stack<long long> stk;
        vector<int> nsr;
        for(int i=n-1;i>=0;i--)
        {
            if(stk.empty())
                nsr.push_back(n);
            else if(arr[stk.top()] >= arr[i])
            {
                while(!stk.empty() && arr[i] <= arr[stk.top()]){
                    stk.pop();
                }
                if(stk.empty())
                    nsr.push_back(n);
                else
                    nsr.push_back(stk.top());
            }
            else
                nsr.push_back(stk.top());
            stk.push(i);
        }
        reverse(nsr.begin(),nsr.end());
        long long maxarea = LONG_MIN;
        for(int i=0;i<n;i++)
        {
            long long height = arr[i];
            long long width = (i - nsl[i] ) + (nsr[i]  - i - 1);
            long long area = height * width;
            maxarea = max(area , maxarea);
        }
        return maxarea;
    }
}
->Third solution is segment tree in O(nlogn) which I dont know
*/
#include<iostream>

using namespace std;

int main()
{
	cout << "Thank YOU";
	return 0;
}