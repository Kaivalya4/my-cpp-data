
/**
gfg.pracitce - Boolean Parentherization

->we can also use map for memoization

int t[201][201][2] ;
    int solve(string &s , int i , int j , bool want)
    {
        if(i==j)
        {
            if( (s[i] == 'T' && want == true) || (s[i] == 'F' && want == false) )
                return 1;
            return 0;
        }
        if(i>j)
            return 0;
        int val = want;
        if(t[i][j][val] != -1)
            return t[i][j][val] ;
        int temp = 0;
        for(int k=i+1 ; k<=j-1 ;k+=2)
        {
            int tl = solve(s,i,k-1,true);
            int fl =solve(s ,i,k-1,false);
            int tr = solve(s , k+1,j,true);
            int fr = solve(s,k+1,j,false);
            if(s[k] == '|')
            {
                if(want ==false)
                    temp = temp + fl*fr;
                else
                    temp = temp + tl*fr + tl*tr + fl*tr;
            }
            else if(s[k] == '&')
            {
                if(want)
                    temp = temp + tl*tr;
                else
                    temp = temp +  tl*fr +fl*tr +fl*fr;
            }
            else if(s[k] == '^'){
                if(want)
                    temp = temp + tl*fr + fl*tr;
                else
                    temp = temp +  tl*tr + fl*fr;
            }
            //cout << temp << endl;
        }
        return t[i][j][val] = temp%1003;
    }
    int countWays(int N, string S){
        // code here
        if(N == 1)
        {
            if(S[0] == 'T')
                return 1;
            else
                return 0;
        }
        memset(t, -1 ,sizeof(t));
        return solve(S , 0 , N-1 , true);
    }
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You" << endl;
    return 0;
}
