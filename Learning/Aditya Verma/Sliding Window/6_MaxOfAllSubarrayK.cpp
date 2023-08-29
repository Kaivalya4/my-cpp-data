/**
Maximum of All Subarray of Size K - gfgPractise
-> naive approach using two nested loops
-> using Self Balancing BST or AVL tree. Instead of AVL we can use max heap also
-> using deque like data structure . I have used vector for this -:
my optimized solution -
class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> vec;
        vector<int> ans;
        int i=0 , j=0;
        while(j<n)
        {
           
            while(vec.size() != 0 && arr[j]>vec[vec.size()-1])
            {
                vec.pop_back();
            }                
            vec.push_back(arr[j]);
            if(j-i+1 == k)
            {
                if(vec.size()!=0)
                {
                    ans.push_back(vec[0]);
                    if(arr[i] == vec[0])
                    {
                        vec.erase(vec.begin()+0);
                    }
                    
                }
                i++;
            }
            j++;
        }
        return ans;
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
