//recursively find max or min element of array

#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int> vec , int maxi , int index)
{
    if(index == vec.size())
    {
        return maxi;
    }
    if(maxi < vec[index])
    {
        maxi = vec[index];
        return solve(vec , maxi , index+1);
    }
    return solve(vec , maxi , index+1);
}

int main()
{
    vector<int> vec;
    int n;
    cin >> n;
    int a;
    for(int i =0 ; i<n ; i++)
    {
         cin >> a;
        vec.push_back(a);
    }
    cout << "maximum is : " << solve(vec , -9999 , 0);
    return 0;
}
