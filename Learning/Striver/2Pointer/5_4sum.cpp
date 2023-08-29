/**
Leetcode - 4sum
Mine -
method1 - Using 4 pointers and hash set to remove duplicates . Then finally place element in vector of vector.
    set takes O(logn) time to insert(as it uses Binary search) . So time complexity = O(n^4* logn) . gives TLE
method2 - using 3 pointers , unordered_map and hash set to remove duplicates. O(n^3 * logn) . gives TLE

striver -
method3 - sort + (3 pointer + Binary Search) - O(n^3 logn)  . gives TLE

method4 - O(n^3) solution .
sort +(2 pointer + 2pointer) : sort the array . fix i , j just like before. now fix k after j and r at the end.
Now use k and r just like we do in 2sum.

*/

/**
method2 -
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> res;
        set<vector<int>> sets;
        unordered_map<int ,int> umap;
        for(int i=0;i<nums.size();i++)
            umap[nums[i]] ++ ;
        for(int i=0;i<nums.size();i++)
        {
            long val = (long) target;
            val -= nums[i];
            umap[nums[i]]--;
            for(int j=i+1;j<nums.size();j++)
            {
                val -= nums[j];
                umap[nums[j]] -- ;
                for(int k =j+1;k<nums.size();k++)
                {
                    val -= nums[k];
                    umap[nums[k]] -- ;
                    if(umap[val])
                    {
                        vector<int>vec;
                        vec.push_back(nums[i]);
                        vec.push_back(nums[j]);
                        vec.push_back(nums[k]);
                        vec.push_back(val);
                        sort(vec.begin(),vec.end());
                        sets.insert(vec);
                    }
                    val += nums[k];
                    umap[nums[k]]++;
                }
                val += nums[j];
                umap[nums[j]]++;
            }
            val += nums[i];
            umap[nums[i]]++;
        }
        for(auto i:sets)
            res.push_back(i);
        return res;
    }
};

method 4 -
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> res;
        if(nums.size() <4)
            return res;

        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int sums = target - nums[i] - nums[j];
                int k = j+1;
                int r = n-1;
                while(k<r)
                {
                    if(nums[k] + nums[r] == sums)
                    {
                        vector<int> vec;
                        vec.push_back(nums[i]);
                        vec.push_back(nums[j]);
                        vec.push_back(nums[k]);
                        vec.push_back(nums[r]);
                        res.push_back(vec);
                        //if sums = 6
                        //3 + 3 =6
                        //4 + 2 = 6 i.e. a,b same . c change d change
                        //we can get more than one pair of c,d for                              //fixed a,b.
                        while(k<r && nums[r] == nums[r-1] )
                            r--;
                        while(k<r && nums[k] == nums[k+1] )
                            k++;
                        k++;
                        r--;
                    }
                    else if(nums[k] + nums[r] > sums)
                        r--;
                    else if(nums[k] + nums[r] < sums)
                        k++;
                }
                //to handle duplicates pointed by j
                //2,2,2 - like this
                while(j<n-2 && nums[j] == nums[j+1]  )
                    j++;
                //last j++ will be handled by for loop
            }
            // to handle duplicates pointed by i
            //1,1,1,2,2,2 - like this
            while(i<n-3 && nums[i] == nums[i+1] )
                i++;
        }
        return res;
    }
};
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    cout << "Thank you";
    return 0;
}
