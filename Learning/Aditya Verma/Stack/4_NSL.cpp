/**
Nearest smaller element to left - pracitse.gfg
class Solution{
public:
    vector<int> leftSmaller(int n, int arr[]){
        // code here
        stack<int> stk;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(stk.empty())
                ans.push_back(-1);
            else if(stk.top()>=arr[i]){
                while(!stk.empty() && stk.top()>=arr[i]){
                    stk.pop();
                }
                if(stk.empty())
                    ans.push_back(-1);
                else
                    ans.push_back(stk.top());
            }
            else
                ans.push_back(stk.top());
            stk.push(arr[i]);
        }
        return ans;
    }
};
*/
#include<iostream>

using namespace std;

int main()
{
	cout << "Thank YOu";
	return 0;
}