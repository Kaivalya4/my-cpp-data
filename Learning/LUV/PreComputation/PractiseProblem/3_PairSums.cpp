#include<iostream>
#include<unordered_map>

using namespace std;
int arr[10000000];

int main()
{
    int n , k;
    cin >> n >> k;
    unordered_map<int ,int> umap;
    for(int i=0 ;i<n ;i++){
        cin >> arr[i];
        umap[arr[i]]++;
    }
    int counts = 0;
    for(int i=0 ;i<n; i++)
    {
        counts += umap[k - arr[i]];
        if(k - arr[i] == arr[i])
            counts --;
        if(counts > 0)
        {
            cout << "YES";
            exit(0);
        }
    }
    cout << "NO";
    return 0;
}
