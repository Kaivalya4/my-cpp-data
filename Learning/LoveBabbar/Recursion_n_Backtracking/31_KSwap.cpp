//find the largest number in k swaps-
#include<iostream>

using namespace std;

//method1 we will place all the largest digit possible to the leftmost side and see which number is
    //greater
    //ex - 3435335 -> we can put 5 of index 3 with first pos or we can put 5 of index 6
    // -> when work of first index is done we will recurr for the next index
    // that what largest value can we put at index 1 and so on

void solve(string str , string &maxs , int k , int ind)
{
    if(k == 0)
    {
        return;
    }

    //we find the maximum element starting from index ind
    char maxy = str[ind];
    for(int i=ind +1; i<str.length() ; i++)
    {
        if(maxy < str[i])
            maxy = str[i];
    }

    //if the maximum element is not the starting ind then only swap is possible
    if(str[ind] != maxy)
        --k;
    for(int i=ind ;i<str.length() ; i++)
    {
        if(str[i] == maxy)
        {
            char temp = str[i];
            str[i] = str[ind];
            str[ind] = temp;

            if(str.compare(maxs)> 0)
                maxs = str;

            solve(str , maxs , k , ind+1);

            temp = str[i];
            str[i] = str[ind];
            str[ind] = temp;
        }
    }
}

int main()
{
    string str;
    cin >> str;
    string maxs = str;
    int k;
    cin >> k;
    solve(str , maxs , k , 0);
    cout << maxs ;
    return 0;
}
