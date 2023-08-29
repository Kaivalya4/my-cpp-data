/*
GFG practise sol -
vector<string> ans;
	    void solve(string s , string last )
	    {
	        if(s.length() == 0)
	        {
	            ans.push_back(last);
	            return ;
	        }
	        for(int j=0; j < s.length() ; j++)
	        {
	            last.push_back(s[j]);
	            char c = s[j];
	            s.erase(s.begin() + j);
	            solve(s , last);
	            s.insert(j , 1 , c);
	            last.pop_back();
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    string last;
		    for(int i=0 ; i<S.length() ;i++)
		    {
		        last.push_back(S[i]);
		        char val = S[i];
		        S.erase(S.begin() + i);
		        solve(S , last );
		        last.pop_back();
		        S.insert(i , 1 , val );
		    }
		    sort(ans.begin() , ans.end());
		    return ans;
		}
*/
