/**
Do gfg.practice - Longest Palindromic Substring. Resuources
    ->  errichto (for only concept)
    -> leetcode discuss - (thisisakshat)
        DP: Instead of going through all the previous Palindromes again and again, how about we save them somewhere and calculate the new ones based on them, but how do we d that? Lets see it below

        Concept: To check a Palindrome of length ,say l, we just have to check if
        i.) s[first character]==s[last character]
        ii.) s[first character+1, last charcter -1] is a Palindrome

        For example : say s=" balab"
        Now, to check , if "s" is Palindrome or not, we just have to look at
        i.) s[first character]==s[last character] -> b==b -> True
        ii.)s[first character+1, last charcter -1] is a Palindrome --> "aba" is a Palindrome??
        To check for "aba", a==a--> True , and "b" is a Palindrome(of length 1)
        ==> s is a Plaindrome

    -> gfg table pic

    A more of mcm pattern

     bool t[1001][1001] ;

    string longestPalin (string s) {
        // code here
        int n = s.length();
        memset(t,0,sizeof(t));

        //start and end of substring
        //single char are palindrome
        int start = 0;
        int len = 1;

        for(int i=0;i<n;i++)
            t[i][i] = true;

        //for length 2
        for(int i=0;i<n-1;i++)
        {
            if(s[i] == s[i+1])
            {
                t[i][i+1] = true;
                if(len != 2){
                start = i;
                len =2;
                }
            }
        }

        //from lenth 3 to so on ....(j=2 is basically length 3)
        for(int j=2;j<n;j++)
        {
            for(int i=0;i<=n-j-1;i++)
            {
                int l = i;
                int r = i + j;
                if(t[l+1][r-1] && s[l] == s[r]){
                    t[l][r] =true;
                    if(j+1 > len)
                        {
                            start = l;
                            len =j+1;
                        }
                }
            }
        }
        return s.substr(start , len);
    }
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank you" ;
    return 0;
}
