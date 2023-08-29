/**
->Hashing - we can use set to store non duplicates elements in sorted order and copy them back to array
->2 Pointer -
int removeDuplicates(vector<int>& arr) {
        if(arr.size() <=1)
            return arr.size();
        int n = arr.size();
        int k=0;
        int i=0 , j=1;
        while(i<j && j<n)
        {
            if(arr[i] == arr[j])
            {
                while(j<n-1 && arr[j] == arr[j+1])
                    j++;
                j++;
            }
            else
            {
                i++;
                arr[i] =arr[j];
                j++;
            }

        }
        return i+1;
    }
*/
#include<iostream>

using namespace std;

int main()
{
    cout << "Thank YOu" ;
    return 0;
}
