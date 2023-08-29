///hackerearth
#include<bits/stdc++.h>

using namespace std;

long long one = 1;
/**
long long solve(vector<pair<long long,long long> >  vec , vector<long long> temp ,  long long k){
    int l=0 , r =temp.size()-1;
    int n = temp.size() -1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(temp[mid] == k)
        {
            return vec[mid].second;
        }
        else if(k < temp[mid])
        {
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    if(l == 0)
        return vec[0].first + k -one;
    k -= temp[l-1];
    return vec[l].first + k -1;
}
*/
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int q;
        cin >> q;
        vector<pair<long long , long long>> vec;
        for(int i=0;i<n;i++)
        {
            long long a,b;
            cin >> a >> b;
            vec.push_back({a,b});
        }
        vector<long long > ks;
        for(int i=0;i<q;i++)
        {
            long long val;
            cin >> val;
            ks.push_back(val);
        }
        sort(vec.begin() , vec.end());
        int itr = 0 ;
        for(int i=1;i<n;i++)
        {
            if(vec[i].first <= vec[itr].second )
            {
                vec[itr] = {vec[itr].first , max(vec[itr].second , vec[i].second)} ;
            }
            else{
                vec[++itr] = vec[i];
            }
        }
        while(vec.size() > itr+1)
        {
            vec.pop_back();
        }
        vector<long long > temp;
        temp.push_back(vec[0].second - vec[0].first +one);
        for(int i=1;i<vec.size(); i++)
        {
            temp.push_back(vec[i].second - vec[i].first +one + temp[i-1]);
        }
        for(int i=0;i<q;i++)
        {
            if(ks[i] > temp[temp.size()-1])
                cout << -1 << endl;
            else
             {
                 for(int itr=0;itr<temp.size();itr++)
                 {
                     if(ks[i] <= temp[itr])
                     {
                            if(itr != 0)
                                ks[i] -= temp[itr-1];
                            cout << vec[itr].first + ks[i] - one << endl;
                            break;
                     }
                 }
             }
        }
    }
    return 0;
}
