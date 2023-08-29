#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str;
    int count = 0;
    getline(cin , str); //argument of getline (istream object , string object , delimiter character)
    //delimiter character tells the function to stop reading further imput after reaching this character
    for(int i=0 ; i<(int)str.length() ; i++)
    {
        char ch = tolower(str[i]);
        if((!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) && (ch>=97 && ch<=122))
        {
            count ++;
        }
    }
    cout << "number of consonants are : " << count ;
    return 0;
}