#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str1("Kaivalya"); //another way of initializing
    string str2(str1) ; //inialization by another string
    string str3(5 , 'a');  //initializing first five character as 'a'
    string str4(str1 , 3 , 4); //part initializtion - from 3 index use 4 characters
    string str5(str1.begin() , str1.begin() + 4);  //iterator version of part initializtion
    string str6 = str1 ; //we can use assingnment operator also

    cout<< str2 << endl;
    cout<< str3 << endl;
    cout<< str4 << endl;
    cout<< str5 << endl;
    cout<< str6 << endl;

    //we can iterate over string as it is container class and we can use [] operator
    for(int i=0 ;i<str1.length()  ; i++)
        cout<<str1[i] << " ";
    cout<< endl;

    cout<< "3 and 4 character in str1 is : " <<str1[3] < str1.at(2) << " " << < endl;
    
    cout<< "first and last character of str1 is : " << str1.front() << " " << str1.back() << endl;

    const char* ch = str1.c_str(); //to get const char* from string
    cout<< "char form str1 is : " << ch << endl;

    str1.append(" Tripathi") ; //same as st1+=" Tripathi";
    str1.append("Thegreat" , 3, 5);  //append 5 characters starting from 3 index to str1
    cout<< "str1 after append : " << str1 << endl;

    str1.find(str2) !=string::npos ? cout<< "str2 is present in str1 " : cout << "str2 is not present in str1" ;
    cout<< endl;

    //(strart index , length of substr to be find)
    cout<< "Some substring of str1 are : " << str1.substr(0 , 8) << " " << str1.substr(0);
    cout<< endl;

    str1.erase(2,3);  //erase 3 characters from index 2
    cout<< str1 << endl;
    str1.erase(str1.begin() , str1.begin()+5);
    cout<< str1 << endl;

    //(starting index , number of characters to be replaced)
    str1.replace(0 , 0 , "Kaivalya");
    cout << str1 << endl;

    str1.clear();
    cout<< str1 << endl;
    return 0;
}