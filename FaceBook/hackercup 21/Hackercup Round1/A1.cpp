#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
char str[4000001];

int main()
{
	freopen("weak_typing_chapter_1_input.txt", "r", stdin);
    freopen("OutputA1_3.txt", "w", stdout);
    int t;
    cin >> t;
    int itr =0;
    while(t--)
    {
    	int n ,counts=0;
    	cin >> n;
    	string s1 , s2;
    	cin >> s1;
    	for(int i=0;i<n;i++)
    	{
    		if(s1[i] != 'F')
    			s2.push_back(s1[i]);
		}
		for(int i=1;i<s2.length();i++)
		{
			if(s2[i] != s2[i-1])
				counts++;
		}
    	cout << "Case #" << ++itr << ": " << counts << endl;
	}
	return 0;
}

    
