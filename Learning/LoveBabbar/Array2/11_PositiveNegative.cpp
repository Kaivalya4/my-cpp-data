/*
-> If extra space has been allowed then we can solve this in O(n) time and O(n) space and storing -ve elements
   and +ve elements in two separate array. first -ve element then +ve element ans so on... whichever will be
   suplus will come at end.Thats why we fixed that -ve at even and +ve at odd index
   2,3,-1,4,-5,6    => -1,2,-5,,3,4,6   (positive surplus come at end)
   -2,-3,1,-4,5,-6  => -2,1,-3,5,-4,-6  (negative surplus come at end)
   order will also preserved

-> Sort the array , we get -ve element at one side and +ve at another side. Now  we can put alternate positive
   negative element using these two side - we will swap the one negative and one positive
   Order not maintained
   O(nlogn) time , O(1) space

-> We can seperate out two negative and positive numbers without sort using two pointers.WE swap elements
   whenever we get a negative number on left side and positive number on right side.
   O(n) time and O(1) space
   Order is not maintained

-> Using Right rotation . Also , negative element at even index and pos at odd . Whichever is surplus will
    come to end automatically(we have seen above)
   Differnce in Right and left rotation -
   Right rotation : right most element shift elements to right
        2,3,1,4,5,6  -rotation by 1 unit->   6,2,3,1,4,5
   left rotation : left most element shift elements to left
        2,3,1,4,5,6  -rotation by 1 unit->   3,1,4,5,6,2
    Algo is same for both rotation

    O(n^2) time and O(1) space
*/

//Right Rotation method
#include<iostream>

using namespace std;

void rightRotate(int arr[] , int wrongindex , int i)
{
    int temp = arr[i];
    for(int index=i ; index>wrongindex ; index--)
        arr[index] = arr[index - 1];
    arr[wrongindex] = temp;
}

void rearrange(int arr[] , int n)
{
    int wrongindex = -1; // we will store the index where the element is wrong . -1 means no such index found
    for(int i=0 ;i<n ;i++)
    {
        //we have not found any wrong index till now.
        if(wrongindex == -1)
        {
            //But if current indexs value is wrong , then wrongindex = i
            //wrong if (positive at even) or (negative at odd)
            if((arr[i] >=0 && i%2 == 0) || (arr[i] <0 && i%2 !=0))
            {
                wrongindex = i;
            }
        }
        //we have already found a wrongindex , i is progressing until we find opposite sign element at i
        else{

            //if we found a opposite sign element then ---- RIGHT ROTATE
            if((arr[wrongindex]>=0 && arr[i] <0) || (arr[wrongindex] <0 && arr[i] >=0))
            {
                rightRotate(arr , wrongindex ,i);

                //suppose we get -ve value at wrongindex , we moved more than 2 steps then we able to find
                //a positive element . So between them there are multiple consecutive -ve element and hence
                //their order are not maintained.

                // So we do wrongindex += 2 . why?
                // Suppose before right rotation wrongindex has negative value . After rotation wrongindex
                // has positive value and negative value shifted right by one step. So positive at wrongindex
                // and negative at wrongindex+1 => order maintained . hence +2 and wrongindex+2 must contain
                // mismatched element (from prev paragraph)
                if(i - wrongindex >=2)
                    wrongindex += 2;
                //if wrongindex had -ve value and wrongindex+1 had +ve value. then right rotation maintained
                // the order . but we cant say wether wrongindex+2 has correct element or not.So when i reach
                // there we will check for its correctness at that time . until then no wrongindex
                else
                    wrongindex =-1;
            }
        }
    }

}

int main()
{
    int arr[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
     int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    for(int i=0 ;i<n ;i++)
        cout << arr[i] << " ";
    cout << endl;

    rearrange(arr, n);

    cout << "Rearranged array is \n";
    for(int i=0 ;i<n; i++)
        cout << arr[i] << " ";

    return 0;
}
