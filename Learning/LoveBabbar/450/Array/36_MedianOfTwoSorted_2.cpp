/**
Median of two sorted array of different sizes - gfg.practice.
->We already know sorting and merge routine method.
->Binary Search (very error prone --- so visualize like I have depicted below)
        [1][4][6][8][9][10]
        0  1  2  3  4  5  6      <----- partitioning point which mid of BS will take

        What is our aim ? fix pointers in array1 and array2 such that if we take all elements left of that
        pointers from array1 and array2 then we get all elements that are smaller than median( of sorted array
        arrangement) -
         ..........smaller ...... (partition) .........greater .......

        So we apply binary search on small array(why ? we see later)
        [.....l1]r1.....      } we founded cut1(or mid) using binary search . So what will be the cut on second array?
                |
                cut1
        simple : "(n+m)/2 - cut1" as only (n+m)/2 elements will be smaller than median.
        [....l2]r2.....
               |
             cut2

        A->
        Now how to know that all elements in the [...] part of the arrays are samller than my median ?
        Simple , since the array is sorted => l1<=r1 . We just want l1 <=r2  ----1

        lly , l2<=r2 is given. We just want l2<=r1  ----2
        So if 1 and 2 holds then we get all the elements that are smaller than my median .
        Now max(l1,l2) will be one of my median (for odd) or one of the candidate for median(for even).
        And min

        B->
        If l1>r2 => l1 should be reduced or should be shift to right such that l1<=r1 conditions hold
            So we should shift cut1 to right.
            That means we increase number of elements from array1 and decrease number of elements from array2

            ( elements left to cut1  + elements right to cut2 = constant = (n+m+1)/2)      ----- *

        B->
        If l2>r1 => l2 should be reduced or should be shift to left => we should shift cut1 to right and
        automatically cut2 will shift to left (using *)

        A , B , C gives the conditions of Binary Search

        Edge cases -

        [1][4][6][8][9][10]
        0  1  2  3  4  5  6
                          ^
                         cut1 = 6
        i.e. we are taking 6 elements from array1 . So l1 = array[cut1-1] . But r1 ? (Ans : INT_MAX (Think) )
        [1][4][6][8][9][10]
        0  1  2  3  4  5  6
        ^
        cut1 = 0
        lly, here => l1 = INT_MIN and r1 = array[cut1]

        Similar caution we will see on array2.

        Now why to Binary Search on Smaller Array?
        1) OUR COMPLEXTITY WILL REDUCE
        2) MOST IMPORTANT   -
                If array1.size() = 20 and array2.size() = 1
                If We apply BS on array1 then we will pick 10 elements from array1 and 10 from array2 but
                    cardinality of array2 =1 . So we might get wrong answer or even Segmentation fault


    Time : O(min(logn,logm)) and space: O(1)
    class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        int n = array1.size();
        int m = array2.size();
        if(n>m)
          return MedianOfArrays(array2,array1);
        int low = 0 , high = n;
        while(low<=high)
        {
            int cut1 = (low+high)/2;
            int cut2 = (n+m+1)/2 - cut1;

            int l1 = (cut1 == 0 ? INT_MIN : array1[cut1-1]);
            int l2 = (cut2  == 0 ? INT_MIN : array2[cut2-1]);

            int r1 = (cut1 == n ? INT_MAX : array1[cut1]);
            int r2 = (cut2 == m ? INT_MAX : array2[cut2]);


            if(l1<=r2 && l2<=r1 )
            {
                if ((m + n) % 2 == 0)
                    return (max(l1, l2)+ min(r1, r2))/ 2.0;
                return max(l1, l2);
            }
            else if(l1>r2){
                high = cut1-1;
            }
            else if(l2 > r1){
                low = cut1+1;
            }
        }
        return 0.0;
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
