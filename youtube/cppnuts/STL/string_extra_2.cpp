#include<iostream>
#include<string>

//note - functions in string.h generally accepts const char* type string

using namespace std;

int main()
{
    string name = "Ztivalya";
    string mname = "Aaivalya";
    if(name != mname)  //retlational operator method .. it returns bool
        cout<< "they are not equal" << endl;
    else
    {
        cout<< "they are equal" << endl;
    }

    /*
    compare can perform lots of different operations alone , based on the type of arguments passed.
    */

    //'compare' compares two string based on ascii value similar as strcmp
    //if ascii value of any char in name > char in mname at that particular position then it return 1 
    //if .....name < ....mname then it return -1
    //if equal then 0 
    int final = name.compare(mname);  //its return type is integer
    cout<< "return type of final is : " << final << endl;
    if (!final)
        cout<< "They are equal" << endl;
    else
    {
        cout<< "They are not equal " << endl;
    }

    //in name from index = 2 compare 3 characters to 3 charcters of mname from index = 2
    if(name.compare(2,3,mname , 2 , 3) == 0)
        cout<< "equals" << endl;
    else
    {
        cout<< "not equals" << endl;
    }
    
    //to do similar thing with relational operator 
    int i,j;
    for( i=2 , j=2 ; i<5 && j<5 ; i++ , j++)
    {
        if(name[i] != mname[j]){
            break;
        }
    }

    if(i== 5 && j==5)
        cout<< "equal" << endl;
    else
    {
        cout<< "not equal" << endl;
    }
    
    return 0;
    
}