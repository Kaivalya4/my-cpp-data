#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void func(vector<int>vec , int r , vector<int>&sol)
{
    if(r == 0 || vec.size() == 0)
    {
        if(r == 0)
        {
            for(auto i:sol)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        return ;
    }
    vector<int> sol1 = sol;
    vector<int> sol2 = sol;
    sol1.push_back(vec[0]);
    vec.erase(vec.begin());
    func(vec , r-1 , sol1);
    func(vec , r , sol2);
}
void solve(vector<int>vec , int r)
{
    vector<int> sol;
    sort(vec.begin() , vec.end());
    for(int i=0 ; i<vec.size() - 1 ;i++) //to handle duplicates if like arr = {1,2,1}
    {
        if(vec[i] == vec[i+1]){
            vec.erase(vec.begin() + i);
        }
    }
    func(vec , r , sol);
}
int main()
{
    vector<int> vec;
    int n;
    cin >> n;
    int a;
    for(int i=0 ;i < n ;i++)
    {
        cin >> a;
        vec.push_back(a);
    }
    int r;
    cin>> r;
    solve(vec , r);
}
