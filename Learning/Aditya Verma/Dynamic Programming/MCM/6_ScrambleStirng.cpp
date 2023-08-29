/**
leetcode - scramble string

unordered_map<string,int> umap;
    bool isScramble(string s1, string s2) {
        if(s1.compare(s2)== 0){
            return true;
            cout << 1 << endl;
        }
        if(s1.length() == 1)
            return s1.compare(s2) == 0;

        if(umap[s1+"+"+s2] !=0)
        {
            if(umap[s1+"+"+s2] == 2)
                return false;
            return true;
        }

        int n = s1.length();
        for(int k=1;k<=n-1;k++)
        {
            if(isScramble(s1.substr(0,k) , s2.substr(0,k)) && isScramble(s1.substr(k,n-k) , s2.substr(k,n-k)) )
                return umap[s1+"+"+s2] = 1;
            if(isScramble(s1.substr(0,k) , s2.substr(n-k,k)) && isScramble(s1.substr(k,n-k) ,s2.substr(0,n-k)))
                return umap[s1+"+"+s2] = 1;
        }
        umap[s1+"+"+s2] = 2;
        return false;
    }
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank you" << endl;
    return 0;
}
