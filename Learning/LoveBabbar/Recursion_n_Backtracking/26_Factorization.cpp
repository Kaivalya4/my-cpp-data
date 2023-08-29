#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> ans;

//all product is product of all the numbers that we able to find that  lead to given number
//first we found 2 allproduct = 2*1 = 2
//suppose again we get 2 , allproduct = 2*2 = 4
//allproduct == n we got a combination
//if allproduct > n , we mutliplied two wrong number like ex -  8*4 = 32

void findit(int first , int allproduct , int n , vector<int> lists)
{
    if(allproduct > n)
        return ;

    if(allproduct == n)
    {
        ans.push_back(lists);
        return;
    }

    //we will find the divisor of n
    for(int i=first ; i<=n ; i++)
    {
        //bingo ! we got a number . suppose 2|16 , here let n = 16 , i = 2 . we will track now i=2.
        if(n%i == 0)
        {
            //then i is worthy of becoming part of list as it divided n.
            lists.push_back(i);
            //list after first iteration in each recursive call-
            //(2) (2,2) (2,2,2) (2,2,2,2)

            //comment is of only first iteration of each recursive call
            findit(i , i*allproduct , n , lists); //(2,2) -> (2,4) -> (2,8)

            lists.pop_back(); //we keep only one element in each iteration and others elements are added
            //to it as recursion moves . so we remove that one element to make our list empty
        }
    }
}

void solve(int n)
{
    vector<int> lists;
    findit(2 , 1 , n , lists);
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    solve(n);
}
