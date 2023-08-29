/**
Question1 : find the element in the array which appears more than n/2 times where n is the size of array

Method1: Brute Force => double loop for each element of the array to count its occurence
         O(n^2) time and O(1) space
Method2: Use of map to count occurence of each element.
         O(n*logn) time and O(~n) space
Method3: Sort to keep all similar element at one place and count in linear time.
         O(n*logn) time and O(1) space
Methdo4 : Voting Algorithm => O(n) time and O(1) space.

            int candidate =-1;
            int count = 0;
            for(int i=0;i<n;i++){
                if(count == 0){
                    candidate = vec[i];
                }else if(vec[i] == candidate){
                    count++;
                }else{
                    count--;
                }
            }
            => Concept of maths . There can be only one element whose count can be more or equal to n/2.
             If element is present more than or equal to n/2 then count will be zero and candidate will
            store that number . But if there is no element present more than or equal to n/2 times then candidate will store
            the wrong answer. Hence we will run a loop once again to verify our answer.

            count =0;
            for(auto i:vec)
                if(i == candidate)
                    count++;
            if(count >=n/2)
                return candidate;
            return -1;
*/

/**
Question2 : find all the element in the array which appears more than n/3 times where n is the size of array

Method1 , Method2 , Method3 is same as above.

Method4 : Extended Voting Algorithm.

vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = INT_MAX, candidate2  = INT_MAX;
        int count1 = 0 , count2 =0;
        int n = nums.size();
        vector<int> sol;
        for(auto i:nums){
            if(candidate1 == i){
                count1++;
            } else if(candidate2 == i){
                count2++;
            } else if( count1 ==0){
                candidate1 = i;
                count1++;
            } else if(count2 == 0){
                candidate2 =i ;
                count2++;
            } else{
                count1-- ,count2--;
            }

        }
        count1 =0 , count2 =0;
        for(auto i:nums){
            if(i == candidate1)
                count1++;
            if(i == candidate2)
                count2++;
        }
        if(count1 > n/3)
            sol.push_back(candidate1);
        if(count2 > n/3 )
            sol.push_back(candidate2);
        return sol;
    }

    => For more than n/2 there is only solution . lly for more than n/3 there can be atmost 2 solution .
    Hence we have taken two candidate.

*/

#include<iostream>

int main(){
    std::cout << "Hello world" << std::endl;
    return 0;
}
