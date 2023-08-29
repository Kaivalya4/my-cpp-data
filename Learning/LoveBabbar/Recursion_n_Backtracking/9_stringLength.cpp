#include<iostream>
#include<string>

using namespace std;

//time - O(n)

int length(string str)
{
    if(str.empty() == 1)
    {
        return 0;
    }
    str.erase(str.begin());
    return 1 + length(str);
}

int main()
{
    string str;
    cin>> str;
    cout << "length of string is : " << length(str);
    return 0;
}
