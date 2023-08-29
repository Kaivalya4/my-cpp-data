///maximum of minimum of every window size - gfg.practice
/**
->Use of nested loops to find the answer ~ O(n^3)
->for every window size - find minimum in every window of that size(we know its algo) - find max for that size
->concept of NSL and NSR
class Solution
{
    public:
    vector<int> NSR(int arr[] , int n)
    {
	stack<int> s;
	vector<int> vec;
	for(int i=n-1;i>=0;i--)
	{
		if(s.empty()){
			vec.push_back(n);
		}
		else if( arr[s.top()] >= arr[i]){
			while(!s.empty() && arr[i] <= arr[s.top()]){
				s.pop();
			}
			if(s.empty()){
				vec.push_back(n);
			}
			else{
				vec.push_back(s.top());
			}
		}
		else{
			vec.push_back(s.top());
		}
		s.push(i);
	}
	reverse(vec.begin(),vec.end());
	return vec;
    }
    vector<int> leftSmaller(int n, int arr[]){
        // code here
        stack<int> stk;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(stk.empty())
                ans.push_back(-1);
            else if(arr[stk.top()]>=arr[i]){
                while(!stk.empty() && arr[stk.top()]>=arr[i]){
                    stk.pop();
                }
                if(stk.empty())
                    ans.push_back(-1);
                else
                    ans.push_back(stk.top());
            }
            else
                ans.push_back(stk.top());
            stk.push(i);
        }
        return ans;
    }

    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {

        vector<int> left = leftSmaller(n , arr);
        vector<int> right = NSR(arr , n);
        vector<int> ans;
        for(int i=0;i<=n;i++)
            ans.push_back(0);
        for(int i=0;i<n;i++)
        {
            int window = right[i] - left[i] -1;
            ans[window] = max(arr[i],ans[window]);
        }
        for(int i=n-1;i>=1;i--)
        {
            ans[i] = max(ans[i],ans[i+1]);
        }
        ans.erase(ans.begin()+0);
        return ans;
    }
};

    Concept -
    find NSL and NSR for each window . Then do window = right[i] - left[i] - 1 for each index i.
    So we can say that arr[i] is the smallest in window-neighbourhood . So there may be more than one element
    with same window size . We find maximum of all arr[i] for the same window size.
    CLAIM - the maximum arr[i] found , lets say :y for the window size x(say) is the final answer i.e.
            maximum of minimum of window size x = y . Why?
        Suppose there is an element t with window = z <x such that t>y . since its window size is z , that means
        if any one lement was added in that window then t no longer remain minimum in that window. So t is not
        my answer now.
        If any element exsists whose window size  =  x such that it is smaller in that window then this element
        must have claimed its demand when we will find maximum of all arr[i].

    Some elements in ans[] array will be zero .
    -> max of min of window x >= max of min window x+1 , x+2 , ..... } obvious . think of it . if suppose a is the
        answer for the window x . Now if I increase window size then it is clear that I will get a smaller element
        which will be greater than a.

    These were my wordings , now lets see what gfg says.

    Consider {10, 20, 30, 50, 10, 70, 30} . Find NSR and NSL
    Once we have indexes of next and previous smaller, we know that arr[i] is a minimum of a
    window of length “right[i] – left[i] – 1”. Lengths of windows for which the elements are minimum
    are {7, 3, 2, 1, 7, 1, 2}. This array indicates, the first element is minimum in the window of size 7,
    the second element is minimum in the window of size 3, and so on.
    Create an auxiliary array ans[n+1] to store the result.
    Values in ans[] can be filled by iterating through right[] and left[]

    for (int i=0; i < n; i++)
    {
        // length of the interval
        int len = right[i] - left[i] - 1;

        // arr[i] is a possible answer for
        // this length len interval
        ans[len] = max(ans[len], arr[i]);
    }

    We get the ans[] array as {0, 70, 30, 20, 0, 0, 0, 10}. Note that ans[0] or answer for length 0 is useless.
    Some entries in ans[] are 0 and yet to be filled. For example, we know maximum of minimum for lengths 1, 2, 3 and 7 are 70, 30, 20 and 10 respectively, but we don’t know the same for lengths 4, 5 and 6.
    Below are few important observations to fill remaining entries
        a) Result for length i, i.e. ans[i] would always be greater or same as result for length i+1, i.e., ans[i+1].
        b) If ans[i] is not filled it means there is no direct element which is minimum of length i and therefore either the element of length ans[i+1], or ans[i+2], and so on is same as ans[i]
        So we fill rest of the entries using below loop.

    for (int i=n-1; i>=1; i--)
        ans[i] = max(ans[i], ans[i+1]);
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You";
    return 0;
}
