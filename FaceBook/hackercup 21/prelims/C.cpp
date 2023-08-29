#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("xs_and_os_input.txt","r",stdin);
        freopen("outputC_3.txt","w",stdout);
    int t;
    cin >> t;
    int itr = 0;
    while(t--){
        int n;
        cin >> n;
        char arr[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> arr[i][j];
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++)
        {
            int ctr = 0;
            bool flag = true;
            for(int j=0;j<n;j++)
            {
                if(arr[i][j] == 'O'){
                    flag = false;
                    break;
                }
                else if(arr[i][j] == 'X')
                    continue;
                else{
                    ctr++;
                }
            }
            if(flag){
                ans = min(ans,ctr);
            }
        }
        for(int j=0;j<n;j++)
        {
            int ctr =0;
            bool flag = true;
            for(int i =0;i<n;i++)
            {
                if(arr[i][j] == 'O')
                {
                    flag = false;
                    break;
                }
                else if(arr[i][j] == 'X')
                    continue;
                else{
                    ctr++;
                }
            }
            if(flag){
                ans = min(ans,ctr);
            }
        }
        if(ans == INT_MAX)
        {
            cout << "Case #" << ++itr << ": Impossible" << endl;
            continue;
        }
        int counts = 0;
        for(int i=0;i<n;i++)
        {
            vector<pair<int,int>> vp;
            int tofill = ans;
            bool flag = true;
            for(int j=0;j<n;j++){
                if(arr[i][j] == 'O')
                {
                    flag = false;
                    break;
                }
                else if(arr[i][j] == 'X')
                    continue;
                else {
                    if(tofill == 0)
                    {
                        flag = false;
                        break;
                    }
                    vp.push_back({i,j});
                    tofill--;
                }
            }
            if(flag && tofill == 0)
            {
                if(ans == 1)
                {
                    arr[vp[0].first][vp[0].second] = 'X';
                }
                counts++;
            }
            vp.clear();
        }
         for(int j=0;j<n;j++)
        {
            int t;
            int tofill = ans;
            bool flag = true;
            for(int i=0;i<n;i++){
                if(arr[i][j] == 'O')
                {
                    flag = false;
                    break;
                }
                else if(arr[i][j] == 'X')
                    continue;
                else {
                    if(tofill == 0)
                    {
                        flag = false;
                        break;
                    }
                    tofill--;
                }
            }
            if(flag && tofill == 0)
            {
                 counts++;
            }
        }
        cout << "Case #" << ++itr << ": "<< ans << " " << counts << endl;
    }
    return 0;
}

