#include<iostream>
#include<sstream>

using namespace std;

//What if we have an integer 55 but we want string 55 or vice versa, we use string stream

/*
A stringstream associates a string object with a stream allowing you to read from the string
as if it were a stream (like cin).

clear() — to clear the stream
str() — to get and set string object whose content is present in stream.
operator << — add a string to the stringstream object.
operator >> — read something from the stringstream object,
*/

/*
Some applications -
1. to count number of words
2. to get frequencies of different words in a string
3. removing spaces from string
4. string to number(we saw it here)
*/
int main()
{
    int input;
    cout << "Enter a intger : " ;
    cin >> input;

    stringstream sso; //stringstream object name
    sso << input ; //just like cout do consoleout and put things to screeen , sso will put input to stream

    string streamstr;
    sso >> streamstr; //just like cin takes input from console(here keyboard) , sso will take input from stream
    // store it to streamstr and we know that stream currently contains input . sso takes input as string from stream

    cout << "Integer value of input : " << input + 2  << endl;
    cout << "String value of input : " << streamstr + "2" << endl;

    sso.clear(); //we cleared the string
    string numstr = "44";

    sso << numstr;

    int num;

    sso >> num;

    cout << "Iteger one : " << num + 2 << endl;
    cout << "String one : " << numstr + "2" << endl;

    return 0;
}
