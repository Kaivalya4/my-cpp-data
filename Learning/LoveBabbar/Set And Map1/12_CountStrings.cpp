#include<iostream>
#include<string>
#include<unordered_map>

//O(N * M) where N is the number of strings and M is the length of the strings.
using namespace std;

int solve(string arr[] , int n , int m)
{
    unordered_map<string, int> umap;
    for(int i=0 ; i<n ; i++)
    {
        char maxs = arr[0][i];
        int maxind = 0 , flag = 0;
        for(int j=1 ; j<m ; j++)
        {
            if(maxs < arr[j][i])
            {
                maxs = arr[j][i];
                maxind = j;
                flag = 0;
            }
            else if(maxs == arr[i][j])
            {
                flag = 1;
            }
        }
        if(flag == 0)
        {
            umap[arr[maxind]] =1;
        }
    }
    int counts = 0;
    for(auto i:umap)
    {
        counts += i.second;
    }
    return counts;
}

int main()
{
    string arr[] =  { "223", "232", "112" } ;
    cout << solve(arr , 3 , 3) ;//(array , len of string  , len of array);
    return 0;
}
