#include<iostream>
#include<queue>

using namespace std;

/**
Mor efficient method apart from queue method. Intution is same.


int solve(int arr[],int n , int k)
{
    int winner = 0 ;
    int tempK = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] > winner) ///if the largest number occur in some of the last position and tempK == k condition is not met then we are assure that largest element is the winner
        {
            winner = arr[i];
            if(i) ///if not first index then true.
            {
                tempK = 1;
            }
        }
        else{
            tempK ++;
        }
        if(tempK == k)
            break;
    }
    return winner;
}

*/

///Using queue data structure
int solve(int arr[] , int n , int k)
{
    queue<int> q;
    for(int i=0;i<n;i++)
        q.push(arr[i]);
    int tempK = 0;
    int winner = q.front();
    q.pop();
    while(true)
    {
        int tops = q.front();
        q.pop();
        if(winner > tops)
        {
            tempK++;
            q.push(tops);
        }
        else{
            tempK=0;
            q.push(winner);
            winner = tops;
        }
        if(tempK == k)
            break;
    }
    return winner;
}

int main()
{
    int n;
    cin >> n;
    int arr[100];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int k;
    cin >> k;
    cout <<  solve(arr , n , k) << endl;
    return 0;
}

