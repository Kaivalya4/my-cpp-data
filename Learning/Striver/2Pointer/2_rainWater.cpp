/**
Method1- O(n^2) time and O(1) space
int leftmax(int start , int ends , vector<int>vec)
{
    int maxi =0;
    for(int i=start;i<=ends;i++)
        maxi = max(vec[i],maxi);
    return maxi;
}

int trap(vector<int>& height) {
        int ans =0;
        for(int i=0;i<height.size();i++)
        {
            ans +=min(findmax(0,i,height),findmax(i,height.size()-1,height)) - arr[i];
        }
        return ans;
    }

Method2 - In metho1 we had to traverse entire array in each iteration. We can save that by building a prefix
and suffix array . O(n) time and O(2n) space
int trap(vector<int>& height) {
        int ans =0;
        if(height.size() == 0)
            return 0;
        vector<int> ltor , rtol;
        ltor.push_back(height[0]);
        for(int i=1;i<height.size();i++)
        {
            ltor.push_back(max(height[i],ltor[i-1]));
        }
        int n=height.size();
        rtol.push_back(height[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            rtol.push_back(max(height[i],rtol[rtol.size()-1]));
        }
        reverse(rtol.begin(),rtol.end());
        for(int i=0;i<n;i++)
        {
            ans += min(ltor[i],rtol[i]) - height[i];
        }
        return ans;
    }
*/
/**
Method3 -Same as method1 we have just casted the solution into if else condition.
O(n) time and O(1) space
int trap(vector<int>& height) {
        int ans=0;
        if(height.size() == 0)
            return 0;
        int n = height.size();
        int leftmax = height[0];
        int rightmax = height[n-1];
        int i=0;
        int j=n-1;
        while(i<j)
        {
            if(height[i]<=height[j])
            {
                if(leftmax <= height[i])
                    leftmax = height[i];
                else
                {
                    ans += leftmax - height[i];
                }
                i++;
            }
            else
            {
                if(rightmax <= height[j])
                    rightmax = height[j];
                else
                {
                    ans += rightmax - height[j];
                }
                j--;
            }
        }
        return ans;
    }
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "thank you";
    return 0;
}
