/**
Nearest greatest to right - practise.gfg
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> vec;
        stack<long long> s;
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty())
            {
                vec.push_back(-1);
            }
            else if(s.top() > arr[i] )
            {
                vec.push_back(s.top());
            }
            else{
                while(!s.empty() && s.top() < arr[i])
                {
                    s.pop();
                }
                if(s.empty()){
                    vec.push_back(-1);
                }
                else{
                    vec.push_back(s.top());
                }
            }
            s.push(arr[i]);
        }
        reverse(vec.begin(),vec.end());
        return vec;
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