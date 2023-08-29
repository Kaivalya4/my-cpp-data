/*
-Sort the vector.
-Assuming there is a point, on the left of the point, all elements add K, on the right of the point,
    all elements substract K, check each possible point. (a point is between two numbers).

maxheight =  max(arr[n-1]-k,arr[i]+k)
minheight = min(arr[0]+k,arr[i]-k)
i.e. 4 combination -
arr[n-1]-k , arr[0]+k //decrease max and increase smallest
arr[n-1]-k,arr[i]-k
arr[i]+k , arr[0]+k //any other value increased gives maxheight and smallest value increased gives minheight
arr[i]+k , arr[i]-k //any other value is increased and any other value is decreased which gives us max and
                    //min height a
but we want min height of all 4 combination .hence
result = min(result, maxheight - minheight)

More explanation:
Cause there are two segments (A[0]+K, A[1]+K, ..., A[i]+K, A[i+1]-K, ..., A[n]-K),
the first one is on the left of the current point (A[i] + K is the last element of the first segment),
the second one is on the right of the current point (A[i + 1] - K is the first element of the second segment).
For the first segment, the smallest element is left, the largest is A[i] + K; For the second segment,
A[i + 1] - K  is the smallest element, the largest is right.
 Thus, for each point, the largest element should be either A[i] + K or right,
 the smallest element should be either left or A[i + 1] - K.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr+n);
        int res = arr[n - 1] - arr[0];
        int left = arr[0] + K, right = arr[n - 1] - K;
        for (int i = 0; i < n - 1; i++) {
            int maxi = max(arr[i] + K, right);
            if(arr[i+1] < K) //to handle negative values , we dont consider it.
                continue;
            int mini = min(left, arr[i + 1] - K);
            res = min(res, maxi - mini);
        }
        return res;
}
int main()
{
      int k = 6;
    int n=3;
    int arr[n]={1, 15, 10};

    int ans = getMinDiff(arr, n ,k);

    cout << ans << "\n";
    return 0;
}
