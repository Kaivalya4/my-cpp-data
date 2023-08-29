#include<iostream>
#include<algorithm>

using namespace std;

struct stock{
    int price;
    int day;
};

bool comp(struct stock a , struct stock b)
{
    if(a.price == b.price)
    {
        if(a.day < b.day)
            return false;
    }
    else if(a.price > b.price)
        return false;
    return true;
}
int main()
{
    stock arr[100];
    int n;
    cin >>n;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i].price;
        arr[i].day = i+1;
    }
    int k;
    cin >> k;
    sort(arr , arr+n , comp);
    int ctr = 0;
    for(int i=0;i<n;i++)
    {
        if(k< arr[i].price)
            break;
        int val = k/(arr[i].price);
        if(val > arr[i].day)
        {
            k -= (arr[i].day)*(arr[i].price);
            ctr += arr[i].day;
        }
        else{
            k -= (val)*(arr[i].price);
            ctr += val;
        }
    }
    cout << ctr << endl;
    return 0;
}

