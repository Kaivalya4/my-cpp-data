//leetcode problem
/*
int findTargetSumWays(vector<int>& nums, int target) {
        int sum =0 , zeros = 0;
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            sum += nums[i];
            if(nums[i] == 0)   //we maintain count of zeros
                zeros++;
            }
        if(target>sum)
            return 0;
        sum = sum+target;
        if(sum %2 != 0)
            return 0;
        sum = sum/2;
        int t[n + 1][sum+1];
        for(int i=0 ; i<n+1 ; i++)
        {
            for(int j=0 ; j<sum + 1; j++)
            {
                if(i == 0)
                    t[i][j] =0;
                if(j == 0)
                    t[i][j] = 1;
            }
        }
        for(int i=1 ; i<n+1; i++)
        {
            for(int j=1 ; j<sum+1 ; j++)
            {
                if(nums[i-1] > j || nums[i-1] == 0) //we dont include zeros into our consideration
                    t[i][j] = t[i-1][j];
                else
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];

            }
        }
        cout << t[n][sum];
        int val = pow(2,zeros); //from recursive approach one can easily understand that if there are n zeros
        //then there will be 2^n subset possible
        return val*t[n][sum];



    }
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "hello";
    return 0;
}
