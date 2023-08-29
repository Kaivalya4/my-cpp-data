/**
Stock Span - practise.gfg
->Brute force can easily be done using two loops.
->stack solution -
class Solution
{
    public:
    //Function to calculate the span of stock’s price for all n days.
    vector <int> calculateSpan(int arr[], int n)
    {
       // Your code here
       stack<int> stk;
       vector<int> ans;
       for(int i=0;i<n;i++)
       {
            if(stk.empty())
                ans.push_back(i - 0 +1);
            else if(arr[stk.top()] > arr[i])
                {
                    int index = stk.top();
                    ans.push_back(i - index);
                }
            else{
                while(!stk.empty() && arr[stk.top()] <= arr[i])
                {
                    stk.pop();
                }
                if(stk.empty())
                    ans.push_back(i - 0 + 1);
                else
                {
                    int index = stk.top();
                    ans.push_back(i - index);
                }
            }
            stk.push(i);
       }
       return ans;
    }
    
-> Another approach - O(n) time and O(1) space using prefix sum approach .
Consider
price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6 
suppose i = 6 i.e. price[i] = 85  . let count = 1(since 85 itself is also counted).
 so price[i] >= price[i-count] . So 85 is greater than price[i-1] =75
so count += arr[i-count] } count = 1+4 i.e. is 75 is greater than equal to 4 consequtive back elements then 85
will be greater than 1+4 consequtive back elements and  so on....................
class Solution
{
    public:
    //Function to calculate the span of stock’s price for all n days.
    vector <int> calculateSpan(int arr[], int n)
    {
       // Your code here
        vector<int> ans;
        for(int i=0;i<n;i++)
            ans.push_back(0);
        ans[0] = 1;
        for(int i=1;i<n;i++)
        {
            int count = 1;
            while(i - count >= 0 && arr[i] >= arr[i-count] )
                count += ans[i-count];
            ans[i] = count;
        }
        return ans;
    }
};

};
*/
#include<iostream>

using namespace std;

int main()
{
	cout << "Thank you";
	return 0;
}