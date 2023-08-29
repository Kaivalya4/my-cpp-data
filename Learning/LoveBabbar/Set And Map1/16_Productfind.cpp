/*
1.Find product of all element and start traversing array if any element found such that product / element = element
then yes otherwise no
2.let a = required element and b = product of all element except and product of entire array = a*b
we want an a such that a = b then if we get a perfect number as product a*a then yes there exsist required element
Hence find product of all element , see if it is a perfect square and if yes wether its square root exsist in array
*/

//using 1
#include<iostream>

using namespace std;

bool solve(int arr[] , int n )
{
    int prod = 1;
    for(int i=0 ; i<n ; i++)
    {
        prod *= arr[i];
    }
    for(int i=0 ; i<n ; i++)
    {
        if(prod/arr[i] == arr[i] && prod % arr[i] == 0)
            return true;
    }
    return false;
}
int main()
{
    int arr[] = {1, 2, 12, 3, 2};
    if(solve(arr , 5))
        cout << "yes" ;
    else
        cout << "no";
    return 0;
}
