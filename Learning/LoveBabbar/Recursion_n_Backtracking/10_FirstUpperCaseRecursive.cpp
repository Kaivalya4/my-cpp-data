//Given a string find its first uppercase letter

#include<iostream>
#include<string>

using namespace std;

char solve(string str)
{
    if(str.length() == 0)
    {
        return '\0';
    }
    if(str[0] >=65 && str[0] <=91)
    {
        return str[0];
    }
    str.erase(str.begin());
    return solve(str);
}

int main()
{
    string str;
    getline(cin , str);
    cout << "first uppercase letter : " << solve(str) ;
    return 0;
}