/*
we take maxreach , stepspossible , jump.
Consider 2,3,1,......
So form  2 we can move atmost 2 STEPS . So we can go upto 1 . While travelling upto 1 we find a largest value
So MAXREACH = I + ARR[I] will store it. So unitl steps != 0 we have to take a jump this can be either to 3 or 1.
-So whenever steps =0 we are sure that we will make a jump . hence jump++
-But where to jump will be handled by maxreach = maximum reachable index from positions between i to i+steps.
*/
//Greedy Approach - we move to index where we get the next max element so that we can make long distance
//jump

//O(n) time and O(1) space
#include<iostream>

using namespace std;

int minJumps(int arr[] , int n)
{
    int maxReach = arr[0];  //we can at max make arr[0] movements or steps
    int stepPoss = arr[0]; //same max steps possible from index 0 is arr[0]
    int jump =1; //we have moved from index 0 so 1 jump has been made.
    //incase first element is zero then stepPoss == 0 will never be satisfied and finally after O(n) time loop
    //will end and return -1
    for(int i=1;i<n;i++)
    {
        if(i == n -1)
            return jump;

        maxReach = max(maxReach , i+arr[i]); // ...,3,4,5,2,...  suppose we moved to 3 after some jumps . so
        //we can go upto 2 at max. so  i between 3 and 2 will contribute to maxReach . Here 5 will contribute
        //because 5 can take us to large distance and thus minimising our jumps

        stepPoss --; // if our point of focus is 3 then we can move upto 2 only. when we reach 2 we made a jump.
        //But where? answer is maxReach - i because maxReach = 5 + index(5) i.e. we have jumped to 5

        if(stepPoss ==0)
        {
            jump++; //but where

            //our steps got exhausted but our maxReach could not come upto i. that means 0 is there
            //if i == maxReach then our maxReach is upto i only. Because before coming to this if statement
            // maxReach must have been updated if any larger value exsisted at i, but this not happend,i.e.
            //at i there is 0
            if(i>=maxReach)
                return -1;
            stepPoss = maxReach - i;
        }
    }
    //whole loop ended but i == n-1 condition not reched i.e. not possible
    return -1;
}
int main()
{
    int arr[] = { 1, 3, 6, 3, 2,3, 6, 8, 9, 5 };
    //int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    //int arr[] = {1, 4, 3, 2, 6, 7};
    //int arr[] = {0,1,1,1,1};
    //int arr[] = {1,0,1,1,1};
    //int arr[] = {2,0,1,1,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of jumps to";
    cout << " reach the end is " << minJumps(arr, n);

    return 0;
}
