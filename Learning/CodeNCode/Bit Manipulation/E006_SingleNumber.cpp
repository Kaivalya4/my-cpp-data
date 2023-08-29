///Leetcode - Single Number2
/**
->Brute O(n^2)
->Using Map
->Using Bit manip
*/

//Using bit manip
/**
    int singleNumber(vector<int>& nums) {
        int res =0 ;
        vector<int> bits;
        for(int i=0 ;i<32 ;i++)
            bits.push_back(0);
        for(auto i:nums)
        {
            for(int j =0 ;j<32 ;j++)
            {
                if(i &(1<<j))
                    bits[j]++;
            }
        }
        for(int i=0 ;i<32;i++)
        {
            if(bits[i] %3 == 1)
                res += (1<<i);
        }
        return res;
    }
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You" ;
    return 0;
}
