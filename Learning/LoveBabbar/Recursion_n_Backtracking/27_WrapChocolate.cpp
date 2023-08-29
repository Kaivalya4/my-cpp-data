#include<iostream>

using namespace std;

int counts = 0;

int func(int tof , int wrap) //wrap - wrapper required for one chocolate
{
    if(tof < wrap)
        return 0;

    //number of toffee we can get from the wrapper -
    int newtof = tof / wrap;

    //now newtof = number of wrapper . we use it to find remaining toffee
    //we use modulo to count remaining wrapper left like when 3 divided 5 we left with 1 + 2 previous wrapper
    return newtof + func(newtof + tof % wrap , wrap);
}

void solve(int money , int price  , int wrap)
{
    int tot =0;
    tot = money/price;
    tot = tot + func(tot , wrap); //number of toffe = number of wrappper
    cout << "Total chocolate : " << tot ;
}

int main()
{
    int money , price  , wrap;
    cin >> money >> price  >> wrap;
    solve(money , price , wrap);
    return 0;
}
