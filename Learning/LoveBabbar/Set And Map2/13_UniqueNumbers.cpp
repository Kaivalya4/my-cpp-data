#include<iostream>
#include<unordered_set>

using namespace std;

void count_unique(unordered_set<int>&s , int n)
{
    while(1)
    {
        if(s.find(n) != s.end())
            break;
        s.insert(n);
        n++;
        while(n%10 == 0)
        {
            n = n/10;
        }
    }
}

int main()
{
    int n = 10;
    unordered_set<int> s;
    count_unique(s, n);

    cout << s.size();
    return 0;
}
