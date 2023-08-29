/**
Sorting Elements of an Array by Frequency - gfg pracitse .
-> Bucket Sort
-> sorting on map.
-> heap
*/
///heap
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct compare{
    bool operator()(pair<int,int> a, pair<int,int>b)
    {
        if(a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    }
};
int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> vec;
	    unordered_map<int,int> umap;
	    for(int i=0;i<n;i++)
	        {
	            int val;
	            cin >> val;
                umap[val]++;
	            vec.push_back(val);
	        }
	   priority_queue<pair<int,int> , vector<pair<int,int>>,compare> pq;
	   for(auto i:umap)
	   {
	       pq.push({i.second,i.first});
	   }
	   int itr = 0;
	   while(!pq.empty())
	   {
	       int val = pq.top().first;
	       while(val--)
	       {
	           vec[itr++] = pq.top().second;
	       }
	       pq.pop();
	   }
        for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
	}
	return 0;
}
