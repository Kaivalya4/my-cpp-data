/**
Maixmum area rectangle in binary matrix - gfg.practice
->novice - first we create vector for each level or row . Then use novice approach to find Max area histogram
	for each level
->We can optimize the code to find MAH for each level using stack.

class Solution{
  public:
    int MAH(int arr[], int n)
    {
        // Your code here
        stack<int> s;
        vector<int> nsl;
        for(int i=0;i<n;i++)
        {
            if(s.empty())
                nsl.push_back(-1);
            else if(arr[s.top()] >= arr[i]){
                while(!s.empty() && arr[i] <= arr[s.top()]){
                    s.pop();
                }
                if(s.empty())
                    nsl.push_back(-1);
                else
                    nsl.push_back(s.top());
            }
            else
                nsl.push_back(s.top());
            s.push(i);
        }
        stack<int> stk;
        vector<int> nsr;
        for(int i=n-1;i>=0;i--)
        {
            if(stk.empty())
                nsr.push_back(n);
            else if(arr[stk.top()] >= arr[i])
            {
                while(!stk.empty() && arr[i] <= arr[stk.top()]){
                    stk.pop();
                }
                if(stk.empty())
                    nsr.push_back(n);
                else
                    nsr.push_back(stk.top());
            }
            else
                nsr.push_back(stk.top());
            stk.push(i);
        }
        reverse(nsr.begin(),nsr.end());
        int maxarea = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int height = arr[i];
            int width = (i - nsl[i] ) + (nsr[i]  - i - 1);
            int area = height * width;
            maxarea = max(area , maxarea);
        }
        return maxarea;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        stack<int> s;
        int area = 0;
        int buildings[m] = {0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j] == 0)
                {
                    buildings[j] = 0;
                }
                else
                    buildings[j] = buildings[j] +1;
            }
            area = max(area, MAH(buildings , m) );
        }
        return area;
    }
};
->Using Dynamic Programming
*/
#include<iostream>

using namespace std;

int main()
{
	cout << "Thank You" ;
	return 0;
}