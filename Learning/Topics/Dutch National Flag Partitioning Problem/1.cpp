/**
Q-> Sort the array of 0s , 1s , 2s  (in one pass and constant space)

We can rearrange the array in a single traversal using an alternative
linear-time partition routine that separates the values into three groups:
    The values less than the pivot,
    The values equal to the pivot, and
    The values greater than the pivot.
To solve this particular problem, consider 1 as a pivot.

This partitioning is similar to 3-way partitioning of Dutch National Flag Problem

void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0 , start = 0 , ends = n-1 , pivot = 1;
        while(ptr<=ends){
            if(nums[ptr]<pivot){
                swap(nums[ptr] , nums[start]);
                start++ , ptr++;   ///left part is already sorted so there is no way we will get anything except 1 from left
            } else if(nums[ptr] > pivot){
                swap(nums[ptr] , nums[ends]);
                ends--;  ///there can be a zero on right which we can get after swapping . In other
                ///words right part ptr is still unsorted.
            } else{
                ptr++;
            }
        }
    }
*/
