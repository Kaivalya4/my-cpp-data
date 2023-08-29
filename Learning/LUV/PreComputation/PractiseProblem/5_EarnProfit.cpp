#include<iostream>
#include<vector>
#include<cmath>
#include<limits.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n , a;
        vector<pair<int ,int>> vec;
        cin >> n >> a;
        for(int i=0 ;i<n ;i++)
        {
            int x , y;
            cin >> x >> y;
            vec.push_back(make_pair(x,y));
        }
        int profit = 0;
        for(int i=0 ;i<n ;i++)
        {
            int val = 0;
            int minD = INT_MAX;
            int maxD = INT_MIN;
            for(int j=i ; j<n ;j++)
            {
                minD = min(minD , vec[j].second);
                maxD = max(maxD , vec[j].second);
                val = val + a - vec[j].first - pow(maxD - minD , 2);
                profit = max(profit , val);
                val += pow(maxD - minD , 2);
            }
        }
        cout << profit << endl;
    }
    return 0;
}
