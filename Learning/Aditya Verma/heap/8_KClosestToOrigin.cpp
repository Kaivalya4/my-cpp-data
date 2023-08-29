/**
k-Colsest points to origin - Leetcode.
note instead of sqrt((x1-x2)^2 + (y1-y2)^2) we can only do (x1-x2)^2 + (y1-y2)^2
-> find distance and sort on basis of distance . O(nlogn)
-> Use max heap
-> Using QuickSelect ( more easy - use stl quickselect -> Read PREREQUISITE)
*/

/**
maxheap solution -
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> pq;
        for(auto i:points)
        {
            vector<int> vec;
            int ans = 0;
            for(auto j:i)
            {
                ans += j*j;
                vec.push_back(j);
            }

            vec.insert( vec.begin()+0 , ans );
            pq.push(vec);
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while(!pq.empty())
        {
            vector<int> topush = pq.top();
            topush.erase(topush.begin()+0);
            res.push_back(topush);
            pq.pop();
        }
        return res;
    }
};

quickselect algorithm -
->if we implement quickselect algorithm (with Lomutos last element as pivot) then also it will accept.
->if we optimize it using worst case linear time selection algorithm , then also it accepts.
->I have used stl's nth_element -
class Solution {
public:
    static bool comp(vector<int> a, vector<int>b)
    {
        return a[0]*a[0] + a[1]*a[1] < b[0] * b[0] + b[1]*b[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(points.begin() , points.begin()+k-1 , points.end(),comp);
        vector<vector<int>> res;
        for(int i=0;i<=k-1;i++)
            res.push_back(points[i]);
        return res;
    }
};
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You" << endl;
    return 0;
}
