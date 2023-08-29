/**

This solution is for greedy solvable problem -
int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	    int ans = 0;
	    sort(nums.begin(),nums.end());
	    int n = nums.size();
	    for(int i=n-1;i>=0;i--)
	    {
	        while(amount - nums[i] >=0)
	        {
	            ans++;
	            amount -= nums[i];
	        }
	    }
	    if(amount !=0)
	        return -1;
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
