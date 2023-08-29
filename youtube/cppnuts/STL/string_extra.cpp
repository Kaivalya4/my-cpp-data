#include<iostream>
//#include<string>

using namespace std;

int main()
{
    char* name= "kaivalya";
    //name[0] = 'K';
    cout << name <<endl;
    const char* title = "TRIPATHI";
    //we cant update it like above because we have use const

    string n = "Kaivalya"/*+"Tripathi*/; //adding here in declaration will give error because compiler interpretes those things inquotes as const 
    //char array which is nothing  but a pointer
    n +=" tripathi"; //this is valid - adding values to string 

    //so we can do like this:
    string name1 = string("Kaivalya") + " Tirpathi";
    cout << name1 << endl;

    //we can use c functions along with some new functions defined in C++ string
    cout << name1.size() << endl;

    //find() returns starting position of the character of the string provided
    cout<< name1.find("ir") << endl;

    bool ans = name1.find("ir") != string::npos; //that means that position is not equal to npos(no position found)
    cout<< ans << endl;

    return 0;
}