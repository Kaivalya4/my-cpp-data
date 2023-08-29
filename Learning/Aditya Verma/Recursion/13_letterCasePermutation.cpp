//string contains letter(upper , lower ,both) and number . workto do is same as before . Also do leetcode
#include<iostream>
#include<string>

using namespace std;

void func(string ip , string op)
{
    if(ip.size() == 0)
    {
        cout <<op << endl;
        return;
    }
    if(isalpha(ip[0]))  //chech if character is aplphabet or not
    {
        string op1 = op;
        string op2 = op;
        op1.push_back(tolower(ip[0]));  //incase if the letter is uppper
        op2.push_back(toupper(ip[0])); //incase if the letter is lower
        ip.erase(ip.begin());
        func(ip , op1);
        func(ip , op2);
    }
    else{   //if character is number
        string op1 = op;
        op1.push_back(ip[0]);
        ip.erase(ip.begin());
        func(ip , op1);
    }
}

void solve(string str)
{
    string ip = str;
    string op = "";
    func(ip , op);
}

int main()
{
    string str;
    cin >> str;
    solve(str);
    return  0;
}
