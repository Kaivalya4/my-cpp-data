/*
->a string is a class which defines objects that be represented as stream of characters
->unlike character array here memory is allocated dynamically
->std::string are slower as compared to character array
*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str ,  str1;
    cout<< "Enter value of str using cin : " ; 
    cin >> str;
    getchar();
    cout << "value of str : " << str;


    cout<<endl<<"Enter value of str1 using getline : " ;
    getline(cin , str1);  //to store stream of characters in object memory
    cout<< endl << "value of str1 : " <<str1 << endl;     

    str.push_back('m');  //push a character at the end of the string
    cout<< "value of str after push_back: " << str << endl;
    

    str.pop_back();  //deletes last character of the string
    cout << "value of str after pop_back : " << str << endl;

    cout<< "capacity of str is : " << str.capacity() << endl;  //we know that str allocates memory dynamically when required(amortized analysis) . this that capacity

    cout<< "length of str is : " << str.length() << endl;  //length of string

    cout<< "size of str is : " << str.size() << endl;  //size also returns length

    str.resize(10);    //changes lenght of the str (increase or decrease) . if incresed then extra index are filled with spaces
    cout<< "size of str after resize : " << str.size() << endl;
    cout << "checking :" << endl;
    for(int i=0 ; i<str.length() ; i++)
        cout<< i+1 << " " <<  str[i] << endl ;

    //NW
    cout << "capacity of str before shrink_to_fit : " << str.capacity() << endl; 
    str.shrink_to_fit();  //mak
    cout << "capacity of str after shrink_to_fit : " << str.capacity() << endl; 

    string::iterator it; //iterator
    cout << "content of str using iterator : " ;
    for(it = str.begin() ; it!=str.end() ; it++)  //begin() - returns iterator to beg ,  end() - returns iterator to end of string
        cout << *it ;
    cout<<endl;

    string:: reverse_iterator it1;  //reverse iterator which can traverse back
    cout << "content of str using reverse iterator : " ;
    for(it1 = str.rbegin() ; it1!= str.rend() ; it1++) //rbegin() - reverse iterator point to end
        cout << *it1 ;
    cout<< endl;

    cout<< "We created a string str3 and a char array ch(empty) : "<< endl;
    string str3 = "Hanuman";
    char ch[10];
    str3.copy( ch, 7 ,0 );  //target string - where copied things will be store comes in argument , length of the string , starting position
      //dont use it copy substring , it gives lots of error
    cout<< "Value of ch after copy operation is  : " << ch << endl;

    cout<<"str3 before swap : " << str3 << endl;
    string str4 = "Ram";
    cout<<"str4 before swap : " << str4 << endl;
    str3.swap(str4);
    cout<< "str3 after swap : "<< str3 << endl;
    cout<< "str4 after swap : " << str4 << endl;
    
    return 0;

}