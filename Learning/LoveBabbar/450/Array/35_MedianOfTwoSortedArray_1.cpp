///Median of two sorted array of same size
/**
->Use of merge sort merge routine - O(n+m) time and O( (n+m)/2) space(As we dont need sorted arrays)
    -we can optimize the complexity to O((n+m)/2) time and O(1) space : keep a counter  and
     as we reach around mid , we store two elements and use them accordingly as m+n = even or odd.
->Use of extra space and sort - O( (n+m)log(n+m) ) and O(n+m) space
->Use of Binary Search
*/

/**
merge sort method - This solution is for different size . but we can easily modify for same size.
class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        int i=0 , j =0;
        int n = array1.size() ;
        int m = array2.size() ;
        double first = 0 , second = 0;
        int counts = 0;
        int mid = (n+m)/2 ;
        while(i<n && j <m)
        {
            if(array1[i]<=array2[j])
            {
                counts++;
                if(counts == mid){
                    first = array1[i];
                }
                else if(counts == mid+1){
                    second = array1[i];
                    break;
                }
                i++;
            }
            else{
                counts++;
                if(counts == mid){
                    first = array2[j];
                }
                else if(counts == mid+1){
                    second = array2[j];
                    break;
                }
                j++;
            }
        }
        while(i<n){
            counts++;
            if(counts == mid){
                first = array1[i];
            }
            else if(counts == mid+1){
                second = array1[i];
                 break;
            }
            i++;
        }
        while(j<m){
            counts++;
            if(counts == mid){
                first = array2[j];
            }
            else if(counts == mid+1){
                second = array2[j];
                break;
            }
            j++;
        }
        if( (m+n)%2==0)
            return (first+second)/2;
        else
            return second;
        }
};

-> See binary search  in next program.
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank You" ;
    return 0;
}
