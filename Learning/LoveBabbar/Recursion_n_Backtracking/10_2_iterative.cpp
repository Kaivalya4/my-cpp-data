//iterative using linear search

#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str;
    getline(cin , str);
    for(int i=0 ; i<str.length() ; i++)
    {
        if(str[i] >= 65 && str[i] <= 91)
        {
            cout << str[i] ;
            break;
        }
    }
    return 0;
}