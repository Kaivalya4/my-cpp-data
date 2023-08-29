#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

//method1 - Using sorting we can group all distinct elements together and can count distinct elements.
//since we have to partition equally so either elements will be partitioned with p2 containing n/2 distinct elements or less
//so answer will be min(count , n/2) .
//ex - arr = 1,2,3,4,1,2,3,4,4,4 so count = 4 distinct element so p2 = 1,2,3,4,any_one_extra
//ex - arr = 1,1,1,2,2,3,5,4 count = 5 so p2 = 1,2,3,4 or p2 = 1,2,3,5 or p2 = 2,3,4,5 so n/2 is the answer
//O(nlogn) and O(1) space
void sorting(int arr[] , int n)
{
    int counts= 0;
    counts ++ ; //for the first element of the array
    sort(arr , arr+n);
    for(int i=1 ; i<n ;i++)
    {
        if(arr[i+1] != arr[i])
            counts++;
    }
    cout << "By sorting method the answer is  : " << min(counts , n/2) << endl;
    return;
}

//method2 - here we use hashmap to count distinct element . Else everything is same we return min of count and n/2
//O(n) for searching and O(n) for space

void hashing(int arr[] , int n)
{
    unordered_map<int , int > umap;
    for(int i=0 ; i<n ; i++)
    {
        umap[arr[i]] = 1;
    }
    int counts = 0;
    for(auto i:umap)
        counts += i.second;
    cout << "By hashing the answer is : " << min(counts ,n/2);
    return ;
}

int main()
{
    int arr[] = { 1, 1, 2, 1, 3, 4 };
    sorting(arr , 6);
    hashing(arr , 6);
    return 0;
}
