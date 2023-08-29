/**
Find repeating and missing - target - O(n) time and O(1) space
->Brute : check repeatness of every element
->Sorting : O(nlogn) time and O(1) space
->Mapping : O(n) time and space
->Array itself as mapping : Since elements are only positive so if we visited index i then we mark
        arr[arr[i]-1] = -arr[arr[i] -1] .   ----*
        So if we get an element x = abs(arr[i]) and arr[x-1] < 0 then x is visited twice
        We have to just put abs() in formula for * to avoid negative indexing

        O(n) time and O(1) space

        class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int repeat = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[abs(arr[i]) -1] <0)
            {
                repeat = abs(arr[i]);
                break;
            }
            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
        }
        long long sumarr = 0;
        for(int i=0;i<n;i++)
        {
            arr[i] = abs(arr[i]);
            sumarr += (long long )arr[i];
        }
        long long sumN = ((long long)n*((long long)n+1))/2;
        sumarr -= (long long)repeat;
        int *ans = new int[2];
        ans[0] = repeat;
        ans[1] = abs((int)(sumN - sumarr));
        return ans;
    }
};

->Using xor : O(n) time and O(1) space
    let xor1 = (xor of elements of array) xor (xor of 1 to n) = xor of repeating element and missing element = x^y(we dont know which one is repeating and which one is missing)

    ->find first set bit of xor1 . Then that set bit is either in x or in y
     So we find one set A  which has all elements with that position bit-set and similarly second set B with not bit-set
     A = xor of all those element with bit-set at that postiion
     B = xor of all thos ............ not bit - set  .;....
      A = A ^(all element in 1 to n with that position bit-set) = either of x or y remain
      B = B ^ (all element in 1 to n with that position not bit-set) = either of x or y remain

      class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int xor1 = 0;
        for(int i=0;i<n;i++)
            xor1 = xor1 ^ arr[i] ^ (i+1);

        int x =0  , y = 0;
        int itr = 0;
        int bitset =0;
        while(true)
        {
            bitset = xor1 &(1<<itr);
            if(bitset)
             break;
             itr++;
        }
        for(int i=0;i<n;i++){
            if(bitset & arr[i])
                x = x ^ arr[i];
            else
                y = y ^ arr[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(bitset & i)
                x = x^ i;
            else
                y = y^i;
        }
        int count1= 0;
        int count2 =0;
        for(int i=0;i<n;i++)
        {
            if(arr[i] == x)
                count1 ++;
            if(arr[i] == y)
                count2 ++;
        }
        if(count2 == 2)
            swap(x,y);
        int *ans = new int[2];
        ans[0] = x;
        ans[1] = y;
        return ans;
    }
};
*/

#include<iostream>

using namespace std;

int main()
{
    cout << "thank you";
    return 0;
}
