///k closest elements - gfg practise
/**
 -> my method1 - sort and use two pointers - ......i X j.......
 I have used LS . Instead we can use BS.
 my complexity - O(nlogn + n +  k)
 class Solution{
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int X) {
        // code here
        sort(arr.begin(),arr.end());
        vector<int> ans;
        int i =n-2 , j=n-1;
        for(int t=0;t<n;t++)
        {
            if(arr[t] == X)
            {
                i = t-1;
                j = t+1;
                break;
            }
            if(arr[t] > X){
                i = t-1;
                j = t;
                break;
            }
        }
        while(i>=0 && j<n)
        {
            if(abs(arr[i] - X) == abs(arr[j] - X))
            {
                ans.push_back(arr[j]);
                if(ans.size() == k)
                    return ans;
                j++;
            }
            else if(abs(arr[i]- X) < abs(arr[j] - X)){
                ans.push_back(arr[i]);
                if(ans.size() == k)
                    return ans;
                i--;
            }
            else{
                ans.push_back(arr[j]);
                if(ans.size() == k)
                    return ans;
                j++;
            }
        }
        while( ans.size() != k && i<0)
        {
            ans.push_back(arr[j++]);
            if(ans.size() == 0)
                return ans;
        }
        while(ans.size() != k && j>=n)
        {
            ans.push_back(arr[i--]);
            if(ans.size() == 0)
                return ans;
        }
        return ans;
    }
};

-> method2 - find absolute difference of all elements with X . make pair <abs difference , index> . Sort
on basis of index . O(n+nlogn) = O(nlogn)

-> method3 - After finding difference , instead of using sort we can use max heap.
 - I tried , but in gfg it wants answer in particular order which is not possible in corner cases
 class Solution{
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int X) {
        // code here
        sort(arr.begin(),arr.end());
        vector<int> ans;
        int i =n-2 , j=n-1;
        for(int t=0;t<n;t++)
        {
            if(arr[t] == X)
            {
                i = t-1;
                j = t+1;
                break;
            }
            if(arr[t] > X){
                i = t-1;
                j = t;
                break;
            }
        }
        while(i>=0 && j<n)
        {
            if(abs(arr[i] - X) == abs(arr[j] - X))
            {
                ans.push_back(arr[j]);
                if(ans.size() == k)
                    return ans;
                j++;
            }
            else if(abs(arr[i]- X) < abs(arr[j] - X)){
                ans.push_back(arr[i]);
                if(ans.size() == k)
                    return ans;
                i--;
            }
            else{
                ans.push_back(arr[j]);
                if(ans.size() == k)
                    return ans;
                j++;
            }
        }
        while( ans.size() != k && i<0)
        {
            ans.push_back(arr[j++]);
            if(ans.size() == 0)
                return ans;
        }
        while(ans.size() != k && j>=n)
        {
            ans.push_back(arr[i--]);
            if(ans.size() == 0)
                return ans;
        }
        return ans;
    }
};
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "thank you" << endl;

    return 0;
}
