#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> vec1;
vector<int> vec2;
vector<int> vec3;
vector<int> vec4;
 
//method 1
void find_union(int arr1[] , int arr2[])
{
    map<int,int> mymap;
    for(int i=0 ; i< 6 ; i++)
        mymap[arr1[i]] ++;
    for(int i=0 ; i<5 ; i++)
        mymap[arr2[i]] ++;
    for(auto i:mymap)
        vec1.push_back(i.first);
}
void find_intersection(int arr1[] , int arr2[])
{
    map<int , int> map1;
    map<int , int> map2;
    for(int i=0 ; i<6 ; i++)
        map1[arr1[i]] = 1;
    for(int i=0 ; i<5;i++)
        map2[arr2[i]] = 1;
    for(auto i:map1)
    {
        if(i.second == map2[i.first])
            vec2.push_back(i.first);
    }

}

//method2 - using naive approach - comparing each element of first with each element of second 
/*
Union: 

1. Initialize union U as empty.
2. Copy all elements of first array to U.
3. Do following for every element x of second array:
    If x is not present in first array, then copy x to U.
4. Return U.

Intersection: 

1. Initialize intersection I as empty.
2. Do following for every element x of first array
   If x is present in second array, then copy x to I.
3.Return I.
Time complexity of this method is O(mn) for both operations.
*/

//method3 - using sorting and binary search
/*
Union-
1.Initialize union U as empty.
2.Find smaller of m and n and sort the smaller array.
3.Copy the smaller array to U.
4.For every element x of larger array, do following
    Binary Search x in smaller array. If,,,, x is not present, then copy it to U.
5.Return U.

Intersection -
1.Initialize intersection I as empty.
2.Find smaller of m and n and sort the smaller array.
3.For every element x of larger array, do following
    Binary Search x in smaller array. If x is present, then copy it to I.
4.Return I.

Time complexity of botn this method is min(mLogm + nLogm, mLogn + nLogn)
*/
int bsearch(int a , int beg , int end)
{
    if(beg<=end)
    {
        int mid = (beg+end)/2;
        if(a > vec3[mid])
        {
            return bsearch(a , mid+1 , end);
        }
        else if(a < vec3[mid])
        {
            return bsearch(a ,beg , mid-1);
        }
        else if(a == vec3[mid])
        {
            return mid;
        }
    }
    return -1;
}
void mehod3_union(int arr1[] , int n , int arr2[] , int m)
{
    //we have to sort smallest array 
    if(n>m){
        sort(arr2 , arr2 + m);
        for(int i=0 ; i<m ; i++)
            vec3.push_back(arr2[i]);
        for(int i=0 ; i<n ; i++)
        {
            if(bsearch(arr1[i] , 0 , m) == -1)
                vec3.push_back(arr1[i]);
        }
    }
    

}

int main()
{
    int arr1[] = {7, 1, 5, 2, 3, 6};
    int arr2[] = {3, 8, 6, 20, 7};
    find_union(arr1 , arr2);
    find_intersection(arr1  ,arr2);
    mehod3_union(arr1 , 6, arr2 , 5);
    cout<< "union is : ";
    for(auto i:vec1)
        cout << i << " ";
    cout<<endl;
    cout<< "intersection is : ";
    for(auto i:vec2)
        cout << i << " ";
    cout<<endl;
    cout<< "union is : ";
    for(auto i:vec3)
        cout << i << " ";
    cout<<endl;
    return 0;

}