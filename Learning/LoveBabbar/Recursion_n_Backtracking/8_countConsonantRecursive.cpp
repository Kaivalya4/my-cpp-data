#include<iostream>
#include<string>

using namespace std;

//we use ibh . we make our test case smaller

int consonant(char ch)
{
    ch = tolower(ch);
    return !((ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) && (ch>=97 && ch<=122);
}

int countConsonant(string str , int n)
{
    if(n == 1)
    {
        char ch = tolower(str[0]);
        //! is on aeiou only
        return !((ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) && (ch>=96 && ch<=121);
    }
    //we make input smaller. Now we take out str[n-1] so we check it for consonant and add it to our
    //small input case to get final answer i.e. IBH
    return countConsonant(str , n -1) + consonant(str[n-1]);
}

int main()
{
    //string str = "geeksforgeeks tutorial";
    string str;
    getline(cin , str);  //to input whole line in c++
    cout << "number of consonant : " << countConsonant(str , str.length());
    return 0;
}