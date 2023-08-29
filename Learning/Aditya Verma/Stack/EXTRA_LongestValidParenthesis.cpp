/**
Longest Valid Parenthesis - gfg.practice
->Generate all substring(O(n^2)) and check wether it is all valid (O(n)) -
    if yes then store its length
    Overall time complextiy is O(n^3)
->Stack(why we use it is clear) and Dynamic Programing(1D){ approached to dp without any recursion or something}
    ( ) ( ) ( ) ( ( ) ( )  (   )  )
    0 1 2 3 4 5 6 7 8 9 10 11 12 13

    we use stack - push('(') and pop ('(') when ')' is encountered . Following are invalidness -
            ->No pop occurs when string = (((((((( and hence length zero
            ->when ) encountered but stack is empty - ())))))  => invalid parenthesis
    for(i->n)
        -> length = i - s.top().second +1
        -> dp[i] = dp[s.top().second - 1] + length
    find max from dp

     dp[5] = 6.
     suppose i = 13.
     length = 13 - 6 + 1 = 8;
     dp[13] = dp[6 - 1] + 8 = 14



class Solution{
public:
    int maxLength(string S){
        // code here
        stack<pair<char,int>> s;
        vector<int>vec;
        for(int i=0;i<=S.length();i++)
            vec.push_back(0);
        for(int i=0;i<S.length();i++)
        {
            if(S[i] == '(')
            {
                s.push({'(',i});
            }
            else{
                if(s.empty())
                    continue;
                pair<char , int> ch = s.top();
                s.pop();
                int length = i - ch.second + 1;
                vec[i] = vec[ch.second == 0 ? 0 : ch.second-1] + length;
            }
        }
        int res = 0;
        for(int i=0;i<S.length();i++)
        {
            res = max(res , vec[i]);
        }
        return res;
    }
};

*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You";
    return 0;
}

