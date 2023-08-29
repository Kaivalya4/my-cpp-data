/**
The concept remains same - 'ignare F' but implementation is different -  keep track of last charcter that is not
F. 
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{	
	freopen("weak_typing_chapter_1_input_Practise.txt", "r", stdin);
    freopen("A1_Practise2.txt", "w", stdout);
	int t;
	cin >> t;
	int itr=0;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int counts =0;
		int index = n;
		char lastchar;
		for(int i=0;i<n;i++)
		{
			if(s[i]!='F')
			{
				lastchar = s[i];
				index = i;
				break;
			}
		}
		for(int i=index;i<n;i++)
		{
			if(s[i] !='F' && s[i] !=lastchar){
				counts++;
				lastchar=s[i];
				
			}
		}
		cout <<"Case #" << ++itr << ": " << counts << endl;
	}
	return 0;
}

    