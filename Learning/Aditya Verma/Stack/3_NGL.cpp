#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> NGL(int arr[] , int n)
{
	stack<int> stk;
	vector<int> ans;
	for(int i=0;i<n;i++)
	{
		if(stk.empty())
			ans.push_back(-1);
		else if(stk.top() >arr[i]){
			ans.push_back(stk.top());
		}
		else{
			while(!stk.empty() && stk.top()<arr[i]){
				stk.pop();
			}
			if(stk.empty())
				ans.push_back(-1);
			else
				ans.push_back(stk.top());
		}
		stk.push(arr[i]);
	}	
	return ans;
}
int main()
{
	int arr[100];
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> arr[i];
	vector<int> ans  = NGL(arr ,n );
	for(int i=0;i<n;i++)
		cout << ans[i] << " ";
	return 0;
}