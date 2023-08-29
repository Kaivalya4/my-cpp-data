/**
->Brute Force: find all tiplets and store in hash to remove duplicates. O(n^3) * O(logn) = O(n^3logn) [for 3 loops
    and storing in hashing takes logn] and O(m) for m elements in hash . We can do following
    x+y+z =0 => x+y = -z . Find all pairs such that sum is -z. here also 3 loops = one to fix z another 2 to find
    x ans y
->Hashing :store all elements in map. run two loops to find x,y and we can find z in constant time. store
    triplets in hash. O(n^2logn) [n^2 for two loops and logn for hashing to store triplets] and O(m+n) space to
    store tiplets and mapping
->Two Pointer : x+y = -z . Find pairs x,y such that sum = -z using two pointers.We can avoid duplicates also , so
    no need for hashing . O(n^2) time[ outer n time to fix z and inner n time for two pointer] and O(1) space
**/

/**
HASHING -
 vector<vector<int>> threeSum(vector<int>& a) {
      vector<vector<int>> ans;
        if(a.size() <=2)
            return ans;
      int x,y,z;
      unordered_map<int ,int> umap;
      for(auto i:a)
        umap[i]++;
      set<vector<int>> sets;
      for(int i=0 ; i<a.size()-2; i++)
      {
          umap[a[i]] -- ; //so that i th element does not include twice .
          for(int j=i+1;j<a.size()-1 ; j++)
          {
              umap[a[j]] --;
              if(umap[-a[i]-a[j]])
              {
                  vector<int> vec;
                  vec.push_back(a[i]);
                  vec.push_back(a[j]);
                  vec.push_back(-a[i]-a[j]);
                  sort(vec.begin(),vec.end());
                  sets.insert(vec);
              }
              umap[a[j]]++;
          }
          umap[a[i]]++;
      }
      for(auto i:sets)
        ans.push_back(i);
    return ans;
    }
*/

/**
Two Pointer -
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() <=2)
            return ans;
        sort(nums.begin() , nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int l = i+1;
            int r = nums.size() - 1;
            int sum = nums[i] *(-1);
            while(l<r)
            {
                if(nums[l] + nums[r] == sum)
                {
                    vector<int> vec;
                    vec.push_back(nums[i]);
                    vec.push_back(nums[l]);
                    vec.push_back(nums[r]);

                    ans.push_back(vec);
                    while(l<r && nums[l] == nums[l+1])
                        l++;
                    while(l<r && nums[r] == nums[r-1])
                        r--;
                    l++ , r--;
                }
                else if(nums[l] + nums[r] < sum)
                    l++;
                else
                    r--;
            }
            while(i<nums.size()-1 && nums[i] == nums[i+1])
                i++;
        }
        return ans;
    }
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You " << endl;
    return 0;
}
