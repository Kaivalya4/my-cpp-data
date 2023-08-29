/*
gfg mine recursive solution -
	public:
	    string solve(vector<int> &v)
	    {
	        if(v.size() == 0)
	        {
	            return "Yes";
	        }
	        if(v[v.size() - 1] == v[0])
	        {
	            v.erase(v.begin() + v.size() - 1);
	            if(v.size() !=0)
	            {
	                v.erase(v.begin());
	                return solve(v);
	            }
	            else
	                return solve(v);
	        }
	        else
	            return "No";
	    }
		string is_palindrome(int n)
		{
		    // Code here.
		    vector<int> v;
		    while(n!=0)
		    {
		        v.push_back(n%10);
		        n = n/10;
		    }
		    return solve(v);
		    
		}
*/

/*
simple loop method - 

string is_palindrome(int n)
{
		    // Code here.
		    vector<int> v;
		    while(n!=0)
		    {
		        v.push_back(n%10);
		        n = n/10;
		    }
            for (int i = 0; i < str.length() / 2; i++) {
       
        // Comparing i th character
        // from starting and len-i
        // th character from end
        if (str[i] != str[len - i - 1])
            return false;
    }
   
    // If the above loop doesn't return then it is
    // palindrome
    return true;
}
*/