/**
k most frequent elements - leetcode
my heap solution -
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]++;
        }
        priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>>> pq;
        for(auto i:umap){
            vector<int> vec;
            vec.push_back(i.second );
            vec.push_back(i.first);
            pq.push(vec);
            if(pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while(!pq.empty())
        {
            vector<int> v = pq.top();
            ans.push_back(v[1]);
            pq.pop();
        }
        return ans;
    }
};

-> using bucket sort - Used matrix as bucket - like of rema thareja
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int num : nums)
            ++m[num];

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto p : m)
            buckets[p.second].push_back(p.first);

        vector<int> ans;
        for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; --i) {
            for (int num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k)
                    break;
            }
        }
        return ans;
    }
};
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank you" ;
    return 0;
}
