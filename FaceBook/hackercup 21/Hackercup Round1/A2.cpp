#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
char str[4000001];
long arr[4000001];
long mod = 1000000007;

int main()
{
	freopen("weak_typing_chapter_2_sample_input.txt", "r", stdin);
 	freopen("OutputA2_1.txt", "w", stdout);
    int t;
    cin >> t;
    int itr =0;
    while(t--)
    {
    	int n ,counts=0;
    	cin >> n;
    	string s1 ;
    	vector<pair<char,int>> vec;
    	cin >> s1;
		for(int i=0;i<n;i++)
    	{
    		if(s1[i] != 'F'){
    			vec.push_back({s1[i] , i});
			}
		}
		vector<int> store;
		for(int i=1;i<vec.size() ;i++)
		{
			if(vec[i].first != vec[i-1].first)
			{
				store.push_back(vec[i].second);
				counts++;
			}
		}
		long sum =0;
		for(int i=1;i<store.size();i++)
		{
			sum += ((1 )* (store[i-1]+1) * (n-store[i-1]));
			sum -= ((n-store[i-1])*1);
		}
		
    	cout << "Case #" << ++itr << ": " << sum << endl;
	}
	return 0;
}

    

