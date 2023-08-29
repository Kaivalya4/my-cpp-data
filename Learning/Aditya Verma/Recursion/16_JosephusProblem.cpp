///Also do gfg.practice
#include<iostream>
#include<vector>

using namespace std;

void solve(int k , vector<int> &v , int index)
{
    if(v.size() == 1)
    {
        cout << v[0] ;
        return ;
    }
    index = (index + k) % (v.size());
    v.erase(v.begin() + index);
    solve(k , v , index);
}

int main()
{
    vector<int> v;
    int n , k;
    cin >> n;
    for(int i = 0 ; i<n ; i++)
        v.push_back(i+1);
    cin >> k;
    k--;
    solve(k , v , 0);
    return 0;
}
