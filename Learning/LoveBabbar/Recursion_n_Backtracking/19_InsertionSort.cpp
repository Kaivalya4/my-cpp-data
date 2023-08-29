#include<iostream>
#include<vector>

using namespace std;

void inserts(vector<int> & vec , int temp)
{
    if(vec.size() == 0 || temp >= vec.back())
    {
        vec.push_back(temp);
        return;
    }
    int last = vec[vec.size()-1];
    vec.pop_back();
    inserts(vec , temp);
    vec.push_back(last);
}

void sorts(vector<int> &vec , int n)
{
    if(n == 0)
    {
        return ;
    }
    int temp = vec[n];
    vec.pop_back();
    sorts(vec , n-1);
    inserts(vec , temp);
}

int main()
{
    vector<int> vec;
    int n , a;
    cin >> n;
    for(int i=0 ; i<n; i++)
    {
        cin >> a;
        vec.push_back(a);
    }
    sorts(vec , n-1);
    for(auto i: vec)
        cout << i << " ";
    return 0;
}
