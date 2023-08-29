/**
This problem can easily be solved using the implementation of A1practise. 
*/

#include<bits/stdc++.h>

using namespace std;
const int mod = 1000000007;

int main()
{	
	freopen("weak_typing_chapter_2_input_Practise.txt", "r", stdin);
    freopen("A2_Practise2.txt", "w", stdout);
	int t;
	cin >> t;
	int itr=0;
	while(t--){
		long long n;
		cin >> n;
		string s;
		cin >> s;
		long long index = n;
		long  long lastchar = 0;
		for(long  i=0;i<n;i++)
		{
			if(s[i]!='F')
			{
				lastchar = i;
				index = i;
				break;
			}
		}
		long long sum =0;
		for(long long i=index;i<n;i++)
		{
			if(s[i] == 'F')
				continue;
			if(s[i] !=s[lastchar]){
				sum =sum +  (lastchar+1)*(n-i);  ///This formula can easily be made using pen and paper
				sum =sum%mod;
			}
			lastchar = i;
		}
		cout <<"Case #" << ++itr << ": " << sum << endl;
	}
	return 0;
}

    