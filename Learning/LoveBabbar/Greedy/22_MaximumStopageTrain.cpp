#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct trains{
    int arrival;
    int dept;
    int plat;
};


int solve(trains arr[] , int n , int m)
{
    vector<pair<int,int>> EachPlatform[m+1];
    for(int i=0;i<n;i++)
    {
        EachPlatform[arr[i].plat].push_back({arr[i].dept,arr[i].arrival});
    }
    for(int i=1;i<=m;i++)
        sort(EachPlatform[i].begin(),EachPlatform[i].end());

    int counts = 0;
    ///Apply Activity Selection or N meetings  for each platform
    for(int i=1;i<=m;i++)
    {
        if(EachPlatform[i].size() == 0)
            continue;

        counts++;
        pair<int,int> last = EachPlatform[i][0];
        for(int j=1;j<EachPlatform[i].size();j++)
        {
            if(EachPlatform[i][j].second >= last.first)
            {
                counts++;
                last = EachPlatform[i][j];
            }
        }
    }
    return counts;

}

int main()
{
    int n;
    cout << "Enter number of trains : ";
    cin >> n;
    cout << "Enter number of platforms : ";
    int m;
    cin >> m;
    trains arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i].arrival >> arr[i].dept >> arr[i].plat;
    }
    cout << "Maximum trains stopped : "  << solve(arr , n, m );
    return 0;
}

