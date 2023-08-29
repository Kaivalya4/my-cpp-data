/**
1,3,5,4,2
According to Wikipedia, a man named Narayana Pandita presented the following simple
algorithm to solve this problem in the 14th century-

1.Find the largest index k such that nums[k] < nums[k + 1].
    If no such index exists, just reverse nums and done.
2.Find the largest index l > k such that nums[k] < nums[l].
3.Swap nums[k] and nums[l].
4.Reverse the sub-array nums[k + 1:]
                                                  5
            5              5               4
           3  4     ->   4   3       ->         3
          1     2       1      2              2
                                        1

Intuition -
k is the point just before which the first peak occured . here arr[k] = 3 . Next we have to find element
next to 3 which is greater than 3 . It can be both 5 and 4 . But we will take element which comes after peak
and is greater than 3 then only next greater number can be achieved . If No such number is there then peak may
become that greater number
   1,2,3,4,5  -> 1,2,3,5,4

Consider first example again
 1,4,5,3,2  -> 1,4,2,3,5
Now the element after peak are decresing . So if we reverse , it became increasing and we get the next permutation

If no such k is find i.e. 5,4,3,2,1 - reverse sorted . Then point 2,3, will skip and hence we have to reverse only
1,2,3,4,5

Both traversel are from right to left . Check tuf channel again if get confused.

void nextPermutation(vector<int>& nums) {
        int k=-1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {   k = i;
                break;
            }
        }
        if(k == -1)
        {
            reverse(nums.begin() , nums.end());
            return ;
        }
        for(int i=nums.size()-1;i>k;i--)
        {
            if(nums[k]<nums[i])
            {
                swap(nums[k] , nums[i]);
                break;
            }
        }
        reverse(nums.begin()+k+1,nums.end());
    }
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You";
    return 0;
}
