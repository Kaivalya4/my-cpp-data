#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("runway_sample_input.txt", "r", stdin);
    freopen("outputA_1.txt", "w", stdout);
    int t;
    cin >>t;
    long long itr = 0;
    while(t--){
    	int n,m;
    	cin >> n >> m;
    	vector<long long> arrived;
    	for(int i=0; i<m;i++)
    	{
    		int val;
    		cin >> val;
    		arrived.push_back(val);
		}
    	vector<vector<long long>> vec;
		for(int i=0;i<n;i++)
		{
			vector<long long>sub;
			for(int j=0;j<m;j++)
			{
				long long val;
				cin >> val;
				sub.push_back(val);
			}
			vec.push_back(sub);
		 }
		 long long counts = 0;
		 vector<bool> exhauster;
		 for(int i=0;i<m;i++)
		 	exhauster.push_back(false);
		 for(int i=0;i<n;i++)
		 {
    		
		 }
		 cout << "Case #" << ++itr << ": " << counts << endl;
	}
	return 0;
}

    