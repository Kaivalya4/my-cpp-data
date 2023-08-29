/**
gfg - K largest element.(its K not Kth)
-> Sorting
-> In Bubble sort , modify the outer loop to run k times only . After K times , k largest element will be at their
    respective position at the end of array.On similar basis we can modigy selection sort.
     We can modify others sorting algo too.
-> using min heap
*/
///min heap method -

#include<iostream>
#include<queue>

using namespace std;

void solve(int arr[] , int n , int k)
{
    priority_queue<int , vector<int> , greater<int>> minheap;
    for(int i=0;i<n;i++)
    {
        minheap.push(arr[i]);
        if(minheap.size() > k)
            minheap.pop();
    }
    while(!minheap.empty())
    {
        cout << minheap.top() << " ";
        minheap.pop();
    }
}

int main()
{
    int arr[1000];
    int n,k;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    solve(arr,n,k);
    return 0;
}
