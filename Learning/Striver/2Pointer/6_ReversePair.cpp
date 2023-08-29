///Reverse pair - leetcode
///7 is of greedy algorithm
/**
method1 - check each and every pair . O(n^2) time
method2 - using BST(self Balancing) - I dont know
striver:
    method3 - merge sort. O(nlogn)
    class Solution {
public:
    int counts = 0;
    void merges(vector<int>&nums , int start , int mid  , int ends)
    {
        int temp[ends - start+1];
        int i=start ,j=mid+1 , k=0;
        while(i<=mid && j<=ends) ///to count required pairs
        {
            long y = (long)nums[j] + (long)nums[j];
            long x = (long)nums[i];
            if(x<=y)
            {
                i++;
            }
            else{
                counts += (mid-i+1);
                j++;
            }
        }
        i = start , j=mid+1;
        while(i<=mid && j<=ends)
        {
            if(nums[i]<=nums[j])
                temp[k++] = (nums[i++]);
            else
                temp[k++] = (nums[j++]);
        }
        while(i<=mid)
            temp[k++] = (nums[i++]);
        while(j<=ends)
            temp[k++] = (nums[j++]);
        int nitr = start;
        for(int itr = 0 ;itr<k;itr++)
            nums[nitr++] = temp[itr];
    }
    void mergeSort(vector<int>& nums , int start , int ends)
    {
        if(start < ends)
        {
            int mid = start+ (ends - start)/2;
            mergeSort(nums , start ,mid);
            mergeSort(nums, mid+1, ends);
            merges(nums, start , mid , ends);
        }
    }
    int reversePairs(vector<int>& nums) {
        if(nums.size() <2)
            return 0;
        int n = nums.size() ;
        mergeSort(nums , 0 , n-1);
        return counts;
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
