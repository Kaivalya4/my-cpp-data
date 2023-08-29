#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool should_i_swap(int a , int b)
{
    if(a >= b)   /// if this holds
        return true;  /// and we want to swap it  then return true
    return false;
}

///MAIN MANTRA TO CONQUER COMPARATOR -
///comparator function of sort is defined opposite -> if a CONDITION hold and you want to swap then return
///false


///Now I will write a comparator which I will use for both my quadratic sort and stl sort
/// asscending -> first ,  descending -> second
bool comp(pair<int,int> a ,pair<int,int>  b)
{
    if(a.first > b.first)
        return false;
    else if(a.first == b.first)
    {
        if(a.second < b.second)
            return false;
        else
            return true;
    }
    return true;
}
int main()
{
    ///sort it
    int arr[] = {1,4,2,10,5,5,20} ;
    int n = 6;
    ///first lets write selection sort algorithm
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(should_i_swap(arr[i],arr[j]))    /// if(arr[i] >= arr[j])  instead of this we add a comparator
                swap(arr[i],arr[j]);
        }
    }

    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;

    ///sort vec in asscending according to first and in descending according to second
    vector<pair<int,int>> vec;
    vec.push_back({1,50});
    vec.push_back({5,25});
    vec.push_back({2,75});
    vec.push_back({10,40});
    vec.push_back({5,90});
    vec.push_back({5,10});
    vec.push_back({20,20});

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(!comp(vec[i] , vec[j]))  ///This type of definition is defined in stl sort
                swap(vec[i] ,vec[j]);
        }
    }

    for(int i=0;i<n;i++)
        cout << vec[i].first << " " << vec[i].second << endl;

    ///Lets use same comp with sort
    vector<pair<int,int>> vec1;
    vec1.push_back({1,50});
    vec1.push_back({5,25});
    vec1.push_back({2,75});
    vec1.push_back({10,40});
    vec1.push_back({5,90});
    vec1.push_back({5,10});
    vec1.push_back({20,20});

    sort(vec1.begin() , vec1.end() , comp);

    for(int i=0;i<n;i++)
        cout << vec1[i].first << " " << vec1[i].second << endl;
}
