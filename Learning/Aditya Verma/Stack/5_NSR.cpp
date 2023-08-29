#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

/**
7
1 -100 2 35 40 16 3
*/
using namespace std;

vector<int> NSR(int arr[] , int n)
{
	stack<int> s;
	vector<int> vec;
	int itr = 0;
	for(int i=n-1;i>=0;i--)
	{
		if(s.empty()){
			vec.push_back(-1);
		}
		else if( (s.top()) > arr[i]){
			while(!s.empty() && arr[i] < s.top()){
				s.pop();
			}
			if(s.empty()){
				vec.push_back(-1);
			}
			else{
				vec.push_back(s.top());
			}
		}
		else{
			vec.push_back(s.top());
		}
		s.push(arr[i]);
	}
	reverse(vec.begin(),vec.end());
	return vec;
}
int main()
{
	int arr[100];
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> arr[i];
	vector<int> vec;
	vec = NSR(arr , n);
	cout << endl;
	for(int i=0;i<n;i++)
		cout << vec[i] << " ";
	return 0;
}
