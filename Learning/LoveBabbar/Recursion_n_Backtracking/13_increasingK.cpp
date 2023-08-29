#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void func(vector<int> vec , int k , vector<int> &sol)
{
    if(k == 0 || vec.size() == 0)
    {
        if(k == 0)
        {
            for(auto i:sol)
            {
                cout << i ;
            }
            cout << endl;
        }
        return;
    }
    vector<int> sol1 = sol;
    vector<int> sol2 = sol;
    sol1.push_back(vec[0]);
    vec.erase(vec.begin());
    func(vec , k-1 , sol1);
    func(vec , k , sol2);
}
void solve(vector<int> vec, int k)
{
    vector<int> sol;
    func(vec , k , sol);
}

int main()
{
    vector<int> vec;
    int n;
    cin >> n;
    for(int i=1 ;i <= n ;i++)
    {
        vec.push_back(i);
    }
    int k;
    cin>> k;
    solve(vec , k);
    return 0;
}
